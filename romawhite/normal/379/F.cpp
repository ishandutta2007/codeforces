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

const int MAXN = 1004007;

int n,l;

vector<int> g[MAXN];

int tin[MAXN];
int tout[MAXN];
int timer;
int up[MAXN][27];

void dfs (int v , int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i < 27; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (int i=0; i<g[v].size(); ++i)
        if (g[v][i] != p){
            dfs (g[v][i] , v);
    }
    tout[v] = ++timer;
}

bool upper (int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int length (int a, int b) {
    int res = 0;
    if (!upper (a, b)){
        int A = a;
        for (int i=26; i>=0; --i)
            if (! upper (up[A][i], b)){
                A = up[A][i];
                res += (1 << i);
            }
        ++res;
    }
    if (!upper (b, a)){
        int B = b;
        for (int i=26; i>=0; --i)
            if (! upper (up[B][i], a)){
                B = up[B][i];
                res += (1 << i);
            }
        ++res;
    }

    return res;

}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt" , "r" , stdin);
#endif

    int m;
    cin >> m;
    vector<int> q;
    n = 4;
    g[0].PB(1);
    g[0].PB(2);
    g[0].PB(3);
    g[1].PB(0);
    g[2].PB(0);
    g[3].PB(0);
    FOR(i,0,m){
        int x;
        scanf("%d" , &x);
        --x;
        g[x].PB(n);
        g[n].PB(x);
        ++n;
        g[x].PB(n);
        g[n].PB(x);
        ++n;
        q.PB(x);
    }

    dfs(0 , 0);

    //length(0,1);

    //cout << length(10,18) << endl;

    int d = 2;
    vector<int> center;
    center.PB(0);

    FOR(i,0,n)
        g[i].clear();
    n = 4;
    g[0].PB(1);
    g[0].PB(2);
    g[0].PB(3);
    g[1].PB(0);
    g[2].PB(0);
    g[3].PB(0);
    FOR(i,0,m){
        g[q[i]].PB(n);
        g[n].PB(q[i]);
        ++n;
        g[q[i]].PB(n);
        g[n].PB(q[i]);
        ++n;
        if (center.size() == 1){
            int dd = length(q[i] , center[0]);
            if (dd == d / 2){
                FOR(j,0,g[center[0]].size()){
                    if (length(q[i] , g[center[0]][j]) == dd - 1){
                        center.PB(g[center[0]][j]);
                    }
                }
                ++d;
            }
        }
        else{
            int d1 = length(q[i] , center[0]);
            int d2 = length(q[i] , center[1]);
            if (d1 > d2)
                swap(center[0] , center[1]);
            if (d / 2 == min(d1,d2)){
                center.pop_back();
                ++d;
            }
        }

        /*FOR(i,0,center.size())
            cout << center[i] << ' ';
        cout << " --- ";*/

        cout << d << endl;
    }
}