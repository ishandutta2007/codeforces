#include <bits/stdc++.h>
using namespace std;

const int MAXN = 102;
const int MAXS = 5001;
const long long MOD = 1e9 + 7;

int main()
{
    map<int, int> ct;
    int n, A[MAXN];
    long long dp1[MAXN/2][MAXS][MAXN/2], dp2[MAXN/2][MAXS][MAXN/2], binom[MAXN][MAXN];
    binom[0][0] = 1;
    for(int i = 0; i < MAXN/2; i++)
    {
        for(int j = 0; j < MAXS; j++)
        {
            for(int k = 0; k < MAXN/2; k++)
            {
                dp1[i][j][k] = 0;
                dp2[i][j][k] = 0;
            }
        }
    }
    for(int i = 0; i < MAXN - 1; i++)
    {
        binom[i][0] = binom[i][i] = 1;
    }
    for(int i = 2; i < MAXN; i++)
    {
        for(int j = 1; j < i; j++)
        {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j])%MOD;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
        ct[A[i]]++;
    }
    if(ct.size() == 2)
    {
        cout << n << endl;
        return 0;
    }
    dp1[0][0][0] = 1;
    dp2[0][0][0] = 1;
    for(int i = 1; i <= min(n, 50); i++)
    {
        int b = A[i - 1];
        for(int s = 0; s < MAXS; s++)
        {
            for(int k = 0; k <= min(n, 50); k++)
            {
                dp1[i][s][k] = dp1[i - 1][s][k];
                if(s >= b && k > 0)
                    dp1[i][s][k] = (dp1[i][s][k] + dp1[i - 1][s - b][k - 1])%MOD;

            }
        }
    }
    if(n > 50)
    {
        for(int i = 1; i <= n - 50; i++)
        {
            int b = A[i + 49];
            for(int s = 0; s < MAXS; s++)
            {
                for(int k = 0; k <= min(n - 50, 50); k++)
                {
                    dp2[i][s][k] = dp2[i - 1][s][k];
                    if(s >= b && k > 0)
                        dp2[i][s][k] = (dp2[i][s][k] + dp2[i - 1][s - b][k - 1])%MOD;

                }
            }
        }
    }
    /*for(int i = 0; i < 50; i++)
    {
        for(int k = 0; k <= 6; k++)
            cout << i << " " << k << " " << dp[n][i][k] << endl;
    }*/
    int ans = 0;
    for(auto p : ct)
    {
        int num = p.first, amt = p.second;
        for(int cop = 1; cop <= amt; cop++)
        {
            int sum = num * cop;
            long long app = 0;
            for(int s = max(sum - MAXS, 0); s < min(sum + 1, MAXS); s++)
            {
                for(int k = max(0, cop - 50); k <= min(cop, 50); k++)
                {
                    /*if(sum == s && k == cop)
                    {
                        cout << "here u go: " << dp1[min(n, 50)][s][k] << " " << dp2[max(n - 50, 0)][sum - s][cop - k] << endl;
                    }
                    if(sum - s < 0 || cop - k < 0)
                        cout << sum - s << " " << cop - k;*/
                    //assert(sum - s >= 0 && cop - k >= 0);
                    app = (app + (dp1[min(n, 50)][s][k]*dp2[max(n - 50, 0)][sum - s][cop - k])%MOD)%MOD;
                }
            }
            /*if(app != binom[amt][cop])
                cout << amt << " " << cop << " " << app << " " << binom[amt][cop] << endl;*/
            //if(cop > 0)
            //cout << num << " " << cop << endl;
            //assert(app);
            if(app == binom[amt][cop])
            {
                //cout << 3 << endl;
                ans = max(ans, cop);
            }
        }
    }
    cout << ans << endl;
}