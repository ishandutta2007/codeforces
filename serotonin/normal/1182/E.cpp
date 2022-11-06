#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;

int dim = 5;

struct matrix {
    int v[5][5];

    matrix() {
        memset(v, 0, sizeof v);
    }

    matrix operator *(const matrix &b) {
        matrix ans = matrix();
        for(int i=0; i<dim; i++) {
            for(int j=0; j<dim; j++) {
                for(int k=0; k<dim; k++) {
                    ans.v[i][j] += 1LL * v[i][k] * b.v[k][j] % (mod - 1);
                    ans.v[i][j] >= mod ? ans.v[i][j] -= mod - 1 : 1;
                }
            }
        }
        return ans;
    }

    matrix operator ^(ll p) {
        matrix ans = matrix(), b = *this;
        for(int i=0; i<dim; i++) ans.v[i][i] = 1;

        while(p) {
            if(p&1) ans = ans * b;
            p >>= 1;
            b = b * b;
        }
        return ans;
    }
};

ll iBigmod(ll b, ll p)
{
    ll ans = 1;
    while(p) {
        if(p&1) ans = (ans * b) % mod;
        p >>= 1;
        b = (b * b) % mod;
    }
    return ans;
}

int main()
{
    ll n, c, fara[5];
    cin >> n;
    for(int i=2; i>=0; i--) cin >> fara[i];
    cin >> c;

    matrix m = matrix();
    for(int i=0; i<3; i++) m.v[0][i] = 1;
    m.v[1][0] = m.v[2][1] = 1;

    matrix mf = m ^ (n-3);

    ll ans = 1;
    for(int i=0; i<3; i++) {
        ans *= iBigmod(fara[i], mf.v[0][i]);
        ans %= mod;
    }

    matrix mc = m;
    mc.v[0][3] = mc.v[3][3] = mc.v[3][4] = mc.v[4][4] = 1;
    mc = mc ^ (n-3);

    ll cp = mc.v[0][3] + mc.v[0][4] % (mod - 1);
    cp = (cp << 1) % (mod - 1);
    ans *= iBigmod(c, cp);
    ans %= mod;

    cout << ans << endl;
}