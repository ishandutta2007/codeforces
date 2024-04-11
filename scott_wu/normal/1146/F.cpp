#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const ll MOD = 998244353;

int N;
int par[MAXN];
ll F[MAXN], NF[MAXN], C[MAXN];
bool is_par[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        is_par[i] = false;

    for (int i = 1; i < N; i++)
    {
        cin >> par[i];
        par[i]--;
        is_par[par[i]] = true;
    }

    for (int i = 0; i < N; i++)
    {
        if (is_par[i])
        {
            F[i] = 0;
            NF[i] = 1;
            C[i] = 0;
        }
        else
        {
            F[i] = 1;
            NF[i] = 0;
            C[i] = 0;
        }
    }

    for (int i = N - 1; i >= 1; i--)
    {
        C[i] += F[i];
        int j = par[i];
        ll fnew = (F[i] + C[i] + NF[i]) * F[j] + C[i] * C[j];
        ll nfnew = (F[i] + NF[i]) * NF[j];
        ll cnew = (F[i] + NF[i]) * C[j] + C[i] * NF[j];
        F[j] = fnew % MOD;
        NF[j] = nfnew % MOD;
        C[j] = cnew % MOD;
    }
    //for (int i = N - 1; i >= 0; i--)
    //    cout << i << " " << F[i] << " " << NF[i] << " " << C[i] << "\n";

    cout << (F[0] + NF[0]) % MOD << "\n";
}