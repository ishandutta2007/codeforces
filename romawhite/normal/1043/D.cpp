#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL*INF*INF;
const int MAX = 100007;
const double PI = acos(-1.);
const double EPS = 1e-8;

const int MOD = 1000000007;

map<PII, int> M;

VI G[MAX];

Int dp[MAX];

Int dfs(int v)
{
    if (dp[v] != -1) return dp[v];
    
    Int & res = dp[v];
    res = 1;
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i];
        res += dfs(to);
    }
    return res;
}

int main()
{
//            freopen("in.txt", "r", stdin);
    //    freopen("out.txt", "w", stdout);
    
    int n , m;
    cin >> n >> m;
    FOR(i,0,m)
    {
        VI A(n);
        FOR(j,0,n)
        {
            scanf("%d" , &A[j]);
            --A[j];
        }
        FOR(j,0,n - 1)
        {
            M[MP(A[j] , A[j + 1])] ++;
        }
    }
    
    for(auto it = M.begin(); it != M.end(); ++it)
    {
        if (it->second != m) continue;
        
        int a = it->first.first;
        int b = it->first.second;
        
        G[a].push_back(b);
    }
    
    FILL(dp, -1);
    
    Int res = 0;
    FOR(i,0,n)
    res += dfs(i);
    
    cout << res << endl;
    
    cerr << "Time : " << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    
    
    return 0;
}