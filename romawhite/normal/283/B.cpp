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
using namespace std;
 
#define next fgdfvd
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef pair <int, int> PII;

vector<int> gr[200007];
vector<int> g[200007];
int next[200007];
bool used[200007];
bool q[200007];
int a[200007];
LL res[200007];

bool us[200007];

void dfs1(int v){
    used[v] = 1;
    FOR(i,0,gr[v].size())
        if (!used[gr[v][i]])
            dfs1(gr[v][i]);
}

void dfs2(int v){
    us[v] = 1;
    res[v] = next[v];
    FOR(i,0,g[v].size()){
        if (!us[g[v][i]])
            dfs2(g[v][i]);
        res[v] += res[g[v][i]];
    }
}


int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    FOR(i,0,200007)
        q[i] = 1;

    int n;
    cin >> n;

    FOR(i,2,n + 1)
        scanf("%d" , &a[i]);

    FOR(i,2,n + 1){
        int t = i;
        t += a[i];
        LL y = 0;
        y += a[i];
        next[i] = y;
        if (t <= 1 || t > n)
            continue;
        y += a[t];
        t -= a[t];
        next[i] = y;
        if (t < 1 || t > n)
            continue;
        g[i].PB(t);
        gr[t].PB(i);
    }

    FOR(i,2,n + 1)
        if (!used[i] && g[i].size() == 0)
            dfs1(i);


    FOR(i,2,n + 1)
        res[i] = -1;

    FOR(i,2,n + 1)
        if (!us[i] && used[i])
            dfs2(i);


    FOR(i,2,n + 1){
        int t = i;
        LL y = i - 1;
        y += a[t];
        t -= a[t];
        if (t <= 0 || t > n){
            printf("%I64d\n" , y);
            continue;
        }
        if (t == 1){
            printf("-1\n");
        }
        else printf("%I64d\n" , (res[t] == -1 ? -1 : y + res[t]));
    }



    return 0;
}