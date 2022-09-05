#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define f first
#define s second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define RFOR(i, b, a) for (int i = b-1; i>=a; --i)
#define FILL(a, b) memset(a, b, sizeof a)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)a.size()

typedef long long Int;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef pair<Int, Int> PLL;

const int INF = 1000 * 1000 * 1000;
const Int LINF = 1LL * INF*INF;
const int MAX = 100007;
const double PI = acos(-1.);
const double EPS = 1e-8;


int a[MAX];
int pos[MAX];

int dp[MAX];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int n;
    cin >> n;
    
    FOR(i,0,n)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    
    RFOR(i,n + 1,1)
    {
        int j = pos[i];
        for(int t = j + i; t < n; t += i)
        {
            if (a[t] > i)
                dp[j] |= !dp[t];
        }
        for(int t = j - i; t >= 0 ; t -= i)
        {
            if (a[t] > i)
                dp[j] |= !dp[t];
        }
    }
    
    FOR(i,0,n)
    {
        if (dp[i])
        {
            cout << 'A';
        }
        else
        {
            cout << 'B';
        }
    }
    
    return 0;
}