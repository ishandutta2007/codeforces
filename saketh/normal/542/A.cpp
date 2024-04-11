#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long ll;
const int MAXV = 200005;
const int INF = 0x7f7f7f7f;

int V, C;
int vx[MAXV], vy[MAXV];
int cx[MAXV], cy[MAXV];
int viewers[MAXV];

vector<int> allv;
int comp(int v){
    return lower_bound(allv.begin(), allv.end(), v) - allv.begin();
}

ll bst = 0;
int c = -1, v = -1; 
pair<int, int> lm[4 * MAXV], rm[4 * MAXV];
vector<int> videos[4*MAXV];
vector<int> channs[4*MAXV];

void check(int chan, int video, int left, int right){
    left = max(left, cx[chan]);
    right = min(right, cy[chan]);
    ll val = (right - left) * 1ll * viewers[chan];

    if(val > bst){
        bst = val;
        c = chan;
        v = video;
    } 
}

pair<int, int> bit[4 * MAXV];

pair<int, int> pmax(pair<int, int> a, pair<int, int> b){
    return a.first > b.first ? a : b;
}

pair<int, int> read(int k){
    pair<int, int> ans = make_pair(0, 0);
    while(k > 0){
        ans = pmax(ans, bit[k]);
        k -= (k & -k);
    }
    return ans;
}

void update(int i, pair<int, int> v){
    while(i < 4*MAXV){
        bit[i] = pmax(bit[i], v);
        i += (i & -i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> V >> C;
    
    for(int i=0; i<V; i++){
        cin >> vx[i] >> vy[i];
        allv.push_back(vx[i]);
        allv.push_back(vy[i]);
    }

    for(int i=0; i<C; i++){
        cin >> cx[i] >> cy[i] >> viewers[i];
        allv.push_back(cx[i]);
        allv.push_back(cy[i]);
    }

    sort(allv.begin(), allv.end());
    allv.resize(unique(allv.begin(), allv.end()) - allv.begin());
    
    memset(lm, 0x7f, sizeof(lm));

    for(int i=0; i<V; i++){
        int rc = comp(vy[i]), lc = comp(vx[i]);
        if(lc < lm[rc].first) lm[rc] = make_pair(lc, i);
        if(rc > rm[lc].first) rm[lc] = make_pair(rc, i);
        videos[rc].push_back(i);
    }        

    for(int i=0; i<C; i++)
        channs[comp(cy[i])].push_back(i);

    for(int i=1; i<allv.size(); i++)
        if(rm[i-1].first > rm[i].first)
            rm[i] = rm[i-1];

    for(int i=allv.size()-2; i>=0; i--)
        if(lm[i].first > lm[i+1].first)
            lm[i] = lm[i+1];

    for(int i=0; i<C; i++){
        int x = comp(cx[i]), y = comp(cy[i]);
        check(i, rm[x].second, cx[i], allv[rm[x].first]);
        if(lm[y].first == INF) continue;
        check(i, lm[y].second, allv[lm[y].first], cy[i]);
    }

    int M = allv.size();

    for(int i=0; i<M; i++){
        for(int vi : videos[i])
            update(M-comp(vx[vi]), make_pair(vy[vi]-vx[vi], vi));

        for(int ch : channs[i]){
            pair<int, int> mlen = read(M-comp(cx[ch]));        
            ll val = mlen.first * 1ll * viewers[ch];
            if(val > bst){
                bst = val;
                c = ch;
                v = mlen.second;
            }
        } 
    }

    cout << bst << endl;
    if(bst) cout << v+1 << " " << c+1 << endl;
}