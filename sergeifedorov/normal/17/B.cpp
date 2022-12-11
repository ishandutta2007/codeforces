#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define norm(a) sort(all(a)); a.erase(unique(all(a)), a.end());
#define num(a, v) (int)(lower_bound(all(a), v) - a.begin())
#define sqr(a) (a)*(a)

typedef long long int64;
typedef pair<int,int> pii;

const int inf = (int)1E+9;
const double eps = 1e-9;

const string task = "a";
const string inp = task + ".in";
const string oup = task + ".out";

int n,m;
int q[1010];
vector<pair<int,pii> >e;
int p[1010];
bool used[1010];
  
int pr(int v){
    if (p[v] == v) return v;
    return p[v] = pr(p[v]);
}

void merge(int v, int u){
    v = pr(v);
    u = pr(u);
    if (rand() & 1)
        p[v] = u;
    else
        p[u] = v;
}


int main(){
//  freopen(inp.data(), "rt", stdin);
//  freopen(oup.data(),"wt", stdout);

    cin >> n;
    forn(i,n){
        cin >> q[i];
        p[i] = i;
    }
    cin >> m;
    forn(i,m){
        int u,v,w;
        cin >> u >> v >> w;
        u--;
        v--;
        e.pb(mp(w,mp(u,v)));
    }
    sort(all(e));
    int res = 0;
    int cnt = 0;
    forn(i,e.size()){
        int a = e[i].sc.fs;
        int b = e[i].sc.sc;
        if (pr(a) == pr(b) || used[b]) continue;
        cnt ++;
        res += e[i].fs;
        merge(a,b);
        used[b] = 1;
    }
    if (cnt < n-1)
        res = -1;
    cout << res << endl;
    

    return 0;
}