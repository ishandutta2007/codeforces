#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 1e9
using namespace std;
typedef vector<vector<int>> vv;
typedef long long ll;
#define rep(i,x,y) for (int i = (x); i < (y); i++)


vv adj;
ll n;
ll sm[MAXN];
void dfs(int u, int p) {
    sm[u] = 1;
    for (auto &i : adj[u]) {
        if (i != p) {
            dfs(i,u);
            sm[u] += sm[i];
        }
    }
}


int getcentroid(int u, int pr) {
    for (auto v: adj[u]) {
        if (v == pr) continue;
        if (sm[v]*2 >= n) {
            return getcentroid(v, u);
        }
    }
    return u;
}
const int NSIZE = 500001;
const int DEM = 120;
int main() {
    cin >> n;
    adj.resize(n);
    rep(i,0,n-1) {
        int a; cin >> a;
        a--;
        adj[i+1].push_back(a);
        adj[a].push_back(i+1);
    }
    dfs(0,-1);
    int centroid = getcentroid(0, -1);
    //cout<<centroid<<"\n";
    dfs(centroid, -1);
    map<int,int> treesizes;
    for (auto v: adj[centroid]) {
        treesizes[sm[v]]++;
    }
    bitset<NSIZE> cur;
    cur.reset();
    cur[0] = 1;
    for (auto &[sz, no]: treesizes) {
        if (sz > DEM) {
            rep(i, 0,no) {
                cur = (cur |= (cur <<sz));
            }
        } else {
            bitset<NSIZE> nw;
            nw.reset();
            rep(i, 0, sz) {
                int curcount = 0;
                for (int j = i; j < NSIZE; j+= sz) {
                    if (cur[j]) curcount++;
                    int bf = j - sz*(no+1);
                    if (bf >= 0 && cur[bf]) {
                        curcount--;
                    }
                    assert(curcount >= 0);
                    if (curcount > 0) {
                        nw[j] = 1;
                    }
                }
            }
            swap(nw, cur);
        }
    }
    ll totsum = accumulate(begin(sm), end(sm), 0LL);


    ll med = (n-1)/2;
    for (ll i = med; i >= 0; i--) {
        if (cur[i]) {
            totsum += i*(n-1-i);
            cout<<totsum<<"\n";return 0;
        }
    }

}