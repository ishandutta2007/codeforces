//#define _GLIBCXX_DEBUG

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <bitset>
#include <map>
#include <cassert>
#include <memory.h>
#include <limits>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

double dist(pi l, pi r);


#define FILENAME "souvenir"

int main(){
    string s = FILENAME;
#ifdef DEBUG
    freopen("/Users/RiaD/Contests/Contests/input", "r", stdin);
    //freopen("output", "w", stdout);
    //cout<<FILENAME<<endl;
    //assert (s != "change me please");
    clock_t start = clock();
#else
    //freopen(FILENAME ".in", "r", stdin);
    //freopen(FILENAME ".out", "w", stdout);
#endif
    cout.sync_with_stdio(0);
    cout.precision(20);
    cout << fixed;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
#ifdef DEBUG
    cerr<<"\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
    return 0;
}


int dsu[303030];
vector<int> g[303030];
int ans[303030];

int get(int x) {
    if(dsu[x] == x) {
        return x;
    }
    else
        return dsu[x] = get(dsu[x]);
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    dsu[a] = b;
}

pi dfs(int v, int p) {
    pi res = {-1, v};
    for(int to: g[v]) {
        if(p != to)
            res = max(res, dfs(to, v));
    }
    ++res.first;
    return res;
}

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    for(int i = 0; i < n; ++i) {
        dsu[i] = i;
    }
    for(int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
        unite(a, b);
    }

    for(int i = 0; i < n; ++i) {
        if(get(i) == i) {
            //cout << i << endl;
            int x = dfs(i, -1).second;
            int y = dfs(x, -1).first;
            ans[i] = y;

            //cout << i << ' ' << y << endl;
        }
    }

    for(int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if(t == 1) {
            int z;
            cin >> z;
            --z;
            cout << ans[get(z)] << '\n';
        }
        else {
            int x, y;
            cin >> x >> y;
            --x,--y;

            x = get(x);
            y = get(y);
            if(x == y)
                continue;
            dsu[x] = y;
            assert(get(x) == get(y) && get(y) == y);
            ans[y] = max(ans[y], max(ans[x], 1 + (ans[x] + 1) / 2 + (ans[y] + 1) / 2));
        }
    }
}