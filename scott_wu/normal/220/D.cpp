#include <iostream>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const int MAXN = 4010;

int W, H;
int nw[2], nh[2];
int gcf[MAXN][MAXN];
ll ans;

int main()
{
    for (int i = 0; i < MAXN; i++)
        gcf[0][i] = gcf[i][0] = i;
    for (int i = 1; i < MAXN; i++)
        for (int j = 1; j < MAXN; j++)
        {
            if (i < j)
                gcf[i][j] = gcf[i][j-i];
            else
                gcf[i][j] = gcf[j][i-j];
        }
    ans = 0;
    
    cin >> W >> H;
    nw[0] = W / 2 + 1;
    nw[1] = W + 1 - nw[0];
    nh[0] = H / 2 + 1;
    nh[1] = H + 1 - nh[0];
    
    for (int i = 0; i < 64; i++)
    {
        int par[6];
        for (int j = 0; j < 6; j++)
            par[j] = ((i & (1 << j)) ? 1 : 0);
        
        int lsum = 0;
        for (int j = 0; j < 3; j++)
            for (int k = 3; k < 6; k++)
            {
                if (k == j + 3)
                    continue;
                
                lsum += par[j] * par[k];
            }
        
        if (lsum % 2 == 0)
        {
            ll nval = 1;
            for (int j = 0; j < 3; j++)
                nval = (nval * nw[par[j]]) % MOD;
            for (int j = 3; j < 6; j++)
                nval = (nval * nh[par[j]]) % MOD;
            
            ans = (ans + nval) % MOD;
        }
    }
    
    ll lans = 0;
    for (int i = 1; i <= W; i++)
    {
        int v = W - i + 1;
        for (int j = 1; j <= H; j++)
            lans = (lans - (v * (H - j + 1) * (ll) gcf[i][j]));
    }
    ans = (ans + 12 * lans);
    
    for (int i = 1; i <= W; i++)
        ans = (ans + MOD - (((6 * (W - i + 1) * 
            (H + 1)) * ((ll) i)) % MOD));
    for (int i = 1; i <= H; i++)
        ans = (ans + MOD - (((6 * (W + 1) * 
            (H - i + 1)) * ((ll) i)) % MOD));
    
    ans = (ans + MOD * MOD - (W + 1) * (H + 1)) % MOD;
    
    cout << ans << "\n";
    //system ("Pause");
    return 0;
}