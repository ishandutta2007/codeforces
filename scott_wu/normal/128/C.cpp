#include <iostream>

using namespace std;
typedef long long ll;
const int MAXN = 2100;
const ll MOD = 1000000007;

ll ptri[MAXN][MAXN];
int n, m, k;

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            ptri[i][j] = 0;
    ptri[0][0] = 1;
    cin >> n >> m >> k;
    for (int i = 1; i <= max (n, m); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ptri[i][j] = ptri[i-1][j];
            if (j >= 1)
                ptri[i][j] += ptri[i-1][j-1];
            ptri[i][j] %= MOD;
        }
    }
    cout << (ptri[n-1][2*k] * ptri[m-1][2*k]) % MOD << "\n";
    //system ("Pause");
    return 0;
}