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
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

vector<pair<int,int> > res;
int deg[1 << 17];
int xr[1 << 17];

void dfs(int v)
{
    deg[v] = -1;
    int to = xr[v];
    res.push_back(MP(v, to));
    if (deg[to])
    {
        xr[to] ^= v;
        deg[to]--;
        if (deg[to] == 1)
        {
            dfs(to);
        }
    }

}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d%d" , &deg[i] , &xr[i]);
    }

    FOR(i,0,n)
    {
        if (deg[i] == 1)
        {
            dfs(i);
        }
    }

    cout << res.size() << endl;
    FOR(i,0,res.size())
    {
        printf("%d %d\n" , res[i].first , res[i].second);
    }

    return 0;
}