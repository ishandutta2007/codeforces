#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const int MAXN = 2100;

int N;
int mat[MAXN][MAXN];
ll derange;
ll dpow[MAXN];
ll dfac[MAXN][MAXN]; // # derange with N guys and K free
bool nseen[MAXN], oseen[MAXN];

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

int main()
{
    scanf("%d", &N);

    dfac[0][0] = 1;
    dfac[1][0] = derange = 0;
    for (int i = 2; i <= N; i++)
    {
        derange = i * derange;
        if (i % 2 == 0) derange++;
        else derange += MOD - 1;
        derange %= MOD;
        dfac[i][0] = derange;
    }

    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            dfac[j][i] = (dfac[j][i-1] + dfac[j-1][i-1]) % MOD;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &mat[i][j]);
        }

    dpow[0] = 1;
    for (int i = 1; i <= N; i++)
        dpow[i] = (dpow[i-1] * derange) % MOD;

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N; j++)
            nseen[j] = oseen[j] = false;

        ll cder = dpow[N-1-i];
        oset sl, st;
        for (int j = N - 1; j >= 0; j--)
        {
            oseen[mat[i][j]] = true;
            sl.insert(mat[i][j]);
            if (nseen[mat[i][j]])
                st.insert(mat[i][j]);
            if (i > 0 && j < N - 1)
            {
                nseen[mat[i-1][j+1]] = true;
                if (oseen[mat[i-1][j+1]])
                    st.insert(mat[i-1][j+1]);
            }

            int nn = st.size();
            int ndub = st.order_of_key(mat[i][j]);
            int nsol = sl.order_of_key(mat[i][j]) - ndub;
            ans += ndub * (((ll) dfac[N-1-j][N-1-j-(nn-1)] * cder) % MOD);
            ans += nsol * (((ll) dfac[N-1-j][N-1-j-nn] * cder) % MOD);
            if (i > 0 && mat[i-1][j] < mat[i][j] && oseen[mat[i-1][j]])
                ans -= dfac[N-1-j][N-1-j-nn] * cder;
            ans = (ans % MOD + MOD) % MOD;
        }
    }
    cout << ans << "\n";
}