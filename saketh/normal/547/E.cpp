#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <tuple>
using namespace std;

struct suffix_array{
    const int INF = 0x7f7f7f7f;

    int L, D;
    string str;
    vector<vector<int> > suff;
    vector<int> rank_of, at_rank;

    pair<pair<int, int>, int> __make_rep(int l, int i, int p){
        if(!l) return {{str[i], INF}, i};
        return {{suff[l-1][i], (i+p<L) ? suff[l-1][i+p] : INF}, i};
    }

    suffix_array(string _str){
        str = _str;
        L = str.size();
        D = 33 - __builtin_clz(L-1);
        suff.resize(D);

        vector<pair<pair<int, int>, int> > keys(L);
        for(int l=0; l<D; l++){
            for(int i=0; i<L; i++)
                keys[i] = __make_rep(l, i, 1<<(l-1));
            sort(keys.begin(), keys.end());
            
            suff[l].resize(L);
            for(int i=0, r=0; i<L; i++){
                if(i>0 && keys[i].first != keys[i-1].first) r++;
                suff[l][keys[i].second] = r;
            }
        }

        rank_of.resize(L);
        at_rank.resize(L);
        for(int i=0; i<L; i++){
            rank_of[i] = suff.back()[i];
            at_rank[rank_of[i]] = i;
        }
    }

    // compare the string at [i, i+l1) to the string at [j, j+l2) 
    int comp(int i, int l1, int j, int l2){
        int cl = min(l1, l2);
        for(int l=0; l<D; l++)
            if((cl>>l)&1){
                if(suff[l][i] != suff[l][j]) 
                    return suff[l][i] < suff[l][j] ? -1 : 1;
                i += 1<<l, j += 1<<l;
            }

        return (l1!=l2) ? (l1<l2) ? -1 : 1 : 0;
    }

    // find the interval of suffix ranks corresponding to instances of the substring at [i, i+len)
    pair<int, int> find_range(int i, int len){
        int left = rank_of[i]; 
        for(int lo=0, hi=left; lo<=hi; ){
            int mi = (lo + hi)/2;
            if(comp(i, len, at_rank[mi], len) == 0){
                left = mi;
                hi = mi-1;
            }
            else lo = mi+1;
        }

        int right = rank_of[i];
        for(int lo=right, hi=L-1; lo<=hi; ){
            int mi = (lo + hi)/2;
            if(comp(i, len, at_rank[mi], len) == 0){
                right = mi;
                lo = mi+1;
            }
            else hi = mi-1;
        }

        return make_pair(left, right);
    } 
};

struct binary_indexed_tree{
    int S;
    vector<int> v;
    
    binary_indexed_tree(int _S){
        S = _S;
        v.resize(S+1);
    }

    int read(int i){
        int sum = 0;
        for(i++; i > 0; ){
            sum += v[i];
            i -= (i & -i);
        }
        return sum;
    }

    void update(int i, int k){
        for(i++; i<v.size(); ){
            v[i]+=k;
            i += (i & -i);
        }
    }

    int read_range(int l, int r){
        return read(r) - read(l-1);
    }
};

const int MAXN = 200005;
const int MAXQ = 500005;

int N;
int wsize[MAXN], where[MAXN];
int wb[MAXN], we[MAXN];

int Q;
vector<pair<int, int> > subs[MAXN], adds[MAXN];
int qans[MAXQ];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> Q;

    stringstream ss_str;
    string phone;
    for(int i=0; i<N; i++){
        cin >> phone;
        ss_str << phone << '*';
        wsize[i] = phone.size();
        where[i+1] = where[i] + wsize[i] + 1;
    }

    suffix_array sa(ss_str.str());

    for(int i=0; i<N; i++)
        tie(wb[i], we[i]) = sa.find_range(where[i], wsize[i]);

    for(int i=0, w, l, r; i<Q; i++){
        cin >> l >> r >> w;
        subs[l-1].emplace_back(w-1, i);
        adds[r-1].emplace_back(w-1, i);
    }

    binary_indexed_tree bit(sa.L);

    for(int i=0; i<N; i++){
        for(auto p : subs[i])
            qans[p.second] -= bit.read_range(wb[p.first], we[p.first]);
        for(int j=where[i]; j<where[i]+wsize[i]; j++)
            bit.update(sa.rank_of[j], 1);  
        for(auto p : adds[i])
            qans[p.second] += bit.read_range(wb[p.first], we[p.first]);
    }

    for(int i=0; i<Q; i++)
        cout << qans[i] << "\n";
}