//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000002013;

int a[1007];
vector<int> g[1007];
int used[1007];
int k;
void dfs(int v){
    used[v] = 1;
    ++k;
    FOR(i,0,g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

bool dp[1007];
int main()
{
    int n , x;
    cin >> n >> x;
    --x;
    FOR(i,0,n){
        cin >> a[i] , a[i]--;
        if (a[i] != -1){
            g[i].PB(a[i]);
            g[a[i]].PB(i);
        }
    }
    int X = x;
    int pos = 0;
    while (X != -1){
        ++pos;
        X = a[X];
    }
    k = 0;
    dfs(x);

    vector<int> b;

    FOR(i,0,n)
        if(!used[i]){
            k = 0;
            dfs(i);
            b.PB(k);
        }

    FILL(dp , 0);
    dp[0] = 1;

    FOR(i,0,b.size())
        RFOR(j,1007,0)
            if (dp[j] && b[i] + j < 1007)
                dp[j + b[i]] = 1;

    FOR(i,0,1007)
        if (dp[i])
            cout << i + pos << endl;

    return 0;
};