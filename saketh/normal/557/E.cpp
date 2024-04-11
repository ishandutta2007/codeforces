#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string.h>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <typeinfo>
using namespace std;

typedef long long ll;

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

vector<pair<int, int> > hp; 

template<typename T> T &quick_select(vector<T> &v, function<int(T&,T&)> comp, int l, int r, int k){
    T& pivot = v[r];
    int below = 0, same = 1;

    for(int i = l; i <= r - same; i++){
        int res = comp(v[i], pivot);
        if(res == 0){
            swap(v[r-same], v[i]);
            same++;
            i--;
        }
        else if(res == -1){
            swap(v[l+below], v[i]);
            below++;
        }
    }
   
    if(below <= k && k < below+same) return v[r];
    if(below > k) return quick_select(v, comp, l, l+below-1, k);
    return quick_select(v, comp, l+below, r-same, k-below-same); 
}

template<typename T> T &quick_select(vector<T> &v, function<int(T&,T&)> comp, int k){
    srand(time(NULL));
    shuffle(hp.begin(), hp.end(), default_random_engine(rand()));
    return quick_select(v, comp, 0, v.size()-1, k); 
}

int N, K;
string str;

int main(){
    cin >> str >> K;
    N = str.size();

    for(int i=0; i<N; i++){ // odd length half-palindrome
        bool evens = true, odds = true;
        for(int j=0; i-j >= 0 && i+j < N ; j++){
            if(j&1){
                odds &= str[i-j] == str[i+j];
                if(odds) hp.emplace_back(i-j, 2*j+1);
            } else {
                evens &= str[i-j] == str[i+j];
                if(evens) hp.emplace_back(i-j, 2*j+1);
            }
        } 
    }

    for(int i=0; i+1<N; i++){ // even length half-palindrome
        bool evens = true, odds = true;
        for(int j=0; i-j >= 0 && i+j+1 < N; j++){
            if(j&1){
                odds &= str[i-j] == str[i+j+1];
                if(odds) hp.emplace_back(i-j, 2*j+2);
            } else {
                evens &= str[i-j] == str[i+j+1];
                if(evens) hp.emplace_back(i-j, 2*j+2);
            }
        }
    }

    suffix_array sa(str);
    std::function<int(pair<int, int>&, pair<int, int>&)> compare = 
        [&sa](pair<int, int>& a, pair<int, int>& b) { 
            return sa.comp(a.first, a.second, b.first, b.second); };
    pair<int, int> res = quick_select(hp, compare, K-1);
    cout << str.substr(res.first, res.second) << endl;
}