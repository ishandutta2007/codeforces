#define _ijps 0
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:667772160")
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
#include <map>
#include <set>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>
#include <bitset>
#include <algorithm>
#include <string>
#include <fstream>
#include <assert.h>
#include <list>
#include <cstring>
using namespace std;

#define name ""
typedef unsigned long long ull;
typedef long long ll;
#define mk make_pair
#define forn(i, n) for(ll i = 0; i < (ll)n; i++)
#define fornn(i, q, n) for(ll i = (ll)q; i < (ll)n; i++)
#define times clock() * 1.0 / CLOCKS_PER_SEC
#define inb push_back

struct __isoff{
    __isoff(){
        if (_ijps)
            freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);//, freopen("test.txt", "w", stderr);
        //else freopen(name".in", "r", stdin), freopen(name".out", "w", stdout);
        //ios_base::sync_with_stdio(0);
        srand(time(0));
        //srand('C' + 'T' + 'A' + 'C' + 'Y' + 'M' + 'B' + 'A');
    }
    ~__isoff(){
        //if(_ijps) cout<<times<<'\n';
    }
} __osafwf;
const ull p1 = 31;
const ull p2 = 29;
const double eps = 1e-8;
const double pi = acos(-1.0);

const ll inf = 1e17 + 7;
const int infi = 1e9 + 7;
const ll dd = 2e6 + 7;
const ll mod = 1e9 + 7;

int n, m;
vector<int> P[dd];
vector<pair<int, int> > H[dd];
int In[dd], Out[dd];
int A[30];
int ti = 0;
string s;

void dfs(int v, int h){
    In[v] = ++ti;
    H[h].push_back(mk(ti, H[h].back().second ^ A[s[v] - 'a']));
    forn(i, P[v].size())
        dfs(P[v][i], h + 1);
    Out[v] = ++ti;
}

int main(){
    cin >> n >> m;
    forn(i, n)
        H[i].resize(1);
    forn(i, 30)
        A[i] = 1 << i;
    forn(i, n - 1){
        int t;
        scanf("%d", &t);
        P[t - 1].push_back(i + 1);
    }
    cin >> s;
    dfs(0, 0);
    forn(i, m){
        int h, v;
        scanf("%d%d", &v, &h);
        v--, h--;
        int l = lower_bound(H[h].begin(), H[h].end(), mk(In[v], -1)) - H[h].begin() - 1;
        int r = lower_bound(H[h].begin(), H[h].end(), mk(Out[v], -1)) - H[h].begin() - 1;
        int t = H[h][l].second ^ H[h][r].second;
        bool ok = t - (t & -t);
        if(!ok)
            printf("Yes\n");
        else
            printf("No\n");
    }
}