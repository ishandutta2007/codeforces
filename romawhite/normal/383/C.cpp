#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <fstream>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define y0 gfdssdfer
#define y1 wetgwervbwqr

#define distance sgfsdfgs

typedef long long Int;
typedef unsigned int uint;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double PI = acos(-1.0);
const int INF = 1000000000;
const int MAX = 2048;
const int MAX2 = 1000007;
const int MOD = 1000000007;

int n,m;
const int MAXN = 200007;

int a[MAXN];
vector<int> g[MAXN];
int d[MAXN];
int tin[MAXN];
int tout[MAXN];
int timer = 0;

void dfs0(int v , int p){
    tin[v] = timer++;
    FOR(i,0,g[v].size())
        if (g[v][i] != p){
            d[g[v][i]] = d[v] + 1;
            dfs0(g[v][i] , v);
        }
    tout[v] = timer++;
}

int b[MAXN];
vector<pair<int,int> > c;

/*void dfs(int v, int p , int delta){
    delta += b[v];
    a[v] += delta;
    FOR(i,0,g[v].size())
        if (g[v][i] != p)
            dfs(g[v][i] , v , -delta);
}*/

bool upper(int a , int par){
    return tin[a] >= tin[par] && tout[a] <= tout[par];
}

pair<int,int> q[MAXN];
bool used[MAXN];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    cin >> n >> m;
    FOR(i,0,n)
        scanf("%d" , &a[i]);

    FOR(i,0,n - 1){
        int x,y;
        scanf("%d%d" , &x , &y);
        --x;--y;
        g[x].PB(y);
        g[y].PB(x);
    }

    dfs0(0,-1);

    int k = 2000;

    FOR(i,0,m){
        int t;
        scanf("%d" , &t);
        if (t == 1){
            int v , d;
            scanf("%d%d" , &v , &d);
            --v;
            c.PB(MP(v , d));
            b[v] += d;
            if (c.size() > k){
                
                int l = 0;
                int r = 0;
                q[r++] = MP(0,0);
                FILL(used,0);
                used[0] = 1;

                while (l < r){
                    int v = q[l].first;
                    int delta = q[l].second;
                    ++l;
                    delta += b[v];
                    a[v] += delta;
                    FOR(j,0,g[v].size())
                        if (!used[g[v][j]]){
                            used[g[v][j]] = 1;
                            q[r++] = MP(g[v][j] , -delta);
                        }
                }

                FILL(b,0);
                c.clear();
            }
        }
        else{
            int v;
            scanf("%d" , &v);
            --v;
            int res = a[v];
            FOR(j,0,c.size())
                if (upper(v , c[j].first)){
                    int d1 = d[v];
                    int d2 = d[c[j].first];
                    if (d2 % 2 == d1 % 2)
                        res += c[j].second;
                    else res -= c[j].second;
                }
            printf("%d\n" , res);
        }
    }

}