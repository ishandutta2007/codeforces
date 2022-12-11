#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
//#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
 
// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
using namespace std;
using i64 = long long;
//using i128 = __int128;
#define MAXN 305
#define MAXM 305
#define M 1000000
#define K 17
#define MAXP 25
#define MAXK 55
#define MAXERR 105
#define MAXLEN 105
#define MDIR 10
#define MAXR 705
#define BASE 102240
#define MAXA 28
#define MAXT 100005
#define LIMIT 86400
#define MAXV 305
#define LEQ 1
#define EQ 0
#define OP 0
#define CLO 1
#define DIG 1
#define C1 0
#define C2 1
#define PLUS 0
#define MINUS 1
#define MUL 2
#define CLO 1
#define VERT 1
#define W 1
#define H 17
#define SPEC 1
#define MUL 2
#define CNT 3
#define ITER 1000
#define INF 1e9
#define EPS 1e-7
#define MOD 998244353
//#define MOD2 1000000007
#define FACT 100000000000000
#define SRC 0
#define PI acos(-1)
#define PUSH 0
#define POP 1
typedef long long ll;
typedef ll hash_t;
//typedef __int128_t lint;
typedef long double ld;
typedef pair<int,int> ii;
typedef pair<int,ll> ilp;
typedef pair<ll,ii> pl;
typedef pair<ll, ll> pll;
typedef pair<ll,int> ppll;
typedef pair<ll,int> li;
typedef pair<ll,ll> iv;
typedef pair<double,int> ip;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> tll;
typedef tuple<ld, int, int> iit;
typedef tuple<int,int,ll> i3;
typedef vector<vector<int>> vv;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<vector<ll>> vll;
typedef complex<ld> cd;
typedef tuple<int,ll,ll> tpl;
#define rep(i,x,y) for (int i = (x); i < (y); i++)
#define trav(i,v)  for (auto &i : v)
#define sz(A) (int)(A.size())
#define pb push_back
#define eb emplace_back
typedef vector<int> vi;

int low[MAXN], disc[MAXN], t = 0, scc = 0, tot[MAXN], cnt[MAXN];
stack<int> s;
bool vis[MAXN], stack_mem[MAXN];
int sz[MAXN];
unordered_map<int,int> rmp;
vv scnodes, adj;
int am[MAXN][MAXN];
void tarjan(int u) {
    disc[u] = low[u] = t++;
    stack_mem[u] = true;
    vis[u] = true;
    s.push(u);
    for (int &v : adj[u]) {
        if (!vis[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (stack_mem[v]) low[u] = min(low[u], disc[v]);
    }
    if (low[u] == disc[u]) {
        int sz = 0;
        vi v;
        while (s.top() != u) {
            stack_mem[s.top()] = false;
            v.pb(s.top());
            rmp[s.top()] = scc;
            s.pop();
            sz++;
        }
        stack_mem[u] = false;
        s.pop();
        v.pb(u);
        sz++;
        tot[scc] = sz;
        rmp[u] = scc++;
        scnodes.eb(v);
    }
}


int main() {
    memset(low, -1, sizeof(low));
    memset(vis, false, sizeof(vis));
    memset(disc, -1, sizeof(disc));
    memset(stack_mem, false, sizeof(stack_mem));
    t = scc = 0;
    int n; cin >> n;
    adj.resize(n);
    vector<ii> el;
    rep(i,0,n) {
        rep(j,0,n) {
            int con; cin >> con;
            if (con) adj[i].pb(j), el.eb(i,j);
        }
    }
    rep(i,0,n) {
        if (!vis[i]) tarjan(i);
    }
    /*
    trav(i,scnodes) {
        rep(j,0,sz(i)) cout << i[j] << ' ';
        cout << '\n';
    }
    */
    vi indeg(n + 5);
    vv nadj(n + 5);
    for (auto [l,r] : el) {
        if (rmp[l] != rmp[r]) {
            am[rmp[l]][rmp[r]] = 1;
            indeg[rmp[r]]++;
            nadj[rmp[l]].pb(rmp[r]);
        }
    }
    queue<int> q;
    rep(i,0,scc) {
        if (!indeg[i]) q.push(i);
    }
    vi topsort;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topsort.pb(u);
        trav(i, nadj[u]) {
            if (--indeg[i] == 0) {
                q.push(i);
            }
        }
    }
    int h = 27;
    int w = 4;
    int l = 800;
    vector<vector<string>> building(h, vector<string>(w));
    rep(i,0, h) {
        rep(j,0, w) {
            rep(k,0, l) {
                building[i][j] += (i%3 == 2? '#': '.');
            }
        }
    }
    auto makecol = [&](int h1, int h2, int x, int y, char ch) {
        rep(i, h1, h2+1) {
            building[i][x][y] = ch;
        }
    };
    auto maketunnel = [&](int lowlvl, int highlvl, int x, int y) {
        //cout<<"making tunnel"<<x<<","<<y<<"..."<<lowlvl<<" "<<highlvl<<"\n";
        int lw = lowlvl*3 + 2;
        int hg = highlvl *3 - 1;
        makecol(lw, hg, x, y, '.');
        makecol(lw, hg, x+1, y, '#');
        makecol(lw, hg, x-1, y, '#');
        makecol(lw, hg, x, y+1, '#');
        makecol(lw, hg, x, y-1, '#');
    };
    int no = 0;
    rep(i, 0, scc) {
        rep(j, i+1, scc) {
            int x = no*5 + 2;
            if (am[topsort[i]][topsort[j]]) {
                maketunnel(i, j, 2, x);
                no++;
            }
        }
    }
    rep(i, 0, scc) {
        int idx = topsort[i];
        vi &members = scnodes[idx];
        for (auto x: members) {
            building[3*i + 1][0][x] = (char)(x + '1');
        }
    }
    cout<<l<<" "<<w<<" "<<h<<"\n";
    rep(i, 0, h) {
        rep(j, 0, w) {
            cout<<building[i][j]<<"\n";
        }
        cout<<"\n";
    }
}