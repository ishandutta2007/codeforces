#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))
#define MP make_pair
#define PB push_back
#define ALL(A) A.begin(),A.end()
#define SZ(A) (int)A.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000000;
const int MAX = 1000000;
const int ST = 1000000007;

double dp[1 << 20];

int cnt[1 << 20];

double res[22];

double p[22];

int main()
{
    //freopen("in.txt" , "r" , stdin);

    FOR(i,1,1 << 20)
    {
        cnt[i] = cnt[i / 2] + i % 2;
    }

    int n , k;
    cin >> n >> k;
    FOR(i,0,n)
    {
        cin >> p[i];
    }


    dp[0] = 1;

    FOR(mask , 0 , 1 << 20)
    {
        double sum = 0;
        FOR(i,0,n)
        {
            if (!(mask & (1 << i)))
            {
                sum += p[i];
            }
        }

        if (sum < 1e-6) continue;

        FOR(i,0,n)
        {


            if (!(mask & (1 << i)))
            {
                if (cnt[mask] < k)
                {
                    res[i] += dp[mask] * p[i] / sum;
                }
                dp[mask | (1 << i)] += dp[mask] * p[i] / sum;

            }
        }
    }

    FOR(i,0,n)
    {
        printf("%.12f " , res[i]);

    }
    cout << endl;
    return 0;
}