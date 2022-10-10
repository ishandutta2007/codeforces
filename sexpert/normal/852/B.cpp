#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<ll>> mat;

const ll MOD = 1e9 + 7;
int n, l, m;
const int MAXN = 1e6 + 5;
ll cini[MAXN], cfin[MAXN];
vector<vector<ll>> owo;

mat mul(mat A, mat B) {
    int n = A.size();
    mat res(n, vector<ll>(n));
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
    return res;
}

mat mexp(mat M, ll e) {
    int n = M.size();
    mat res(n, vector<ll>(n));
    for(int i = 0; i < n; i++)
        res[i][i] = 1;
    for(ll k = 1; k <= e; k *= 2) {
        if(k & e) res = mul(res, M);
        M = mul(M, M);
    }
    return res;
}

int cost[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> m;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cini[x % m]++;
    }
    owo.assign(m, vector<ll>(m));
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cost[i] = x;
        for(int i = 0; i < m; i++) {
            owo[i][(x + i) % m]++;
        }
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cfin[(x + cost[i]) % m]++;
    }
    /*for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            cout << owo[i][j] << " ";
        }
        cout << '\n';
    }*/
    mat res = mexp(owo, l - 2);
    /*for(int i = 0; i < m; i++)
        cout << res[0][i] << " ";
    cout << endl;*/
    ll ans = 0;
    for(int a = 0; a < m; a++) {
        for(int b = 0; b < m; b++) {
            int rem = (a + b) % m;
            if(rem > 0)
                rem = m - rem;
            //cout << cini[a] << " " << cini[b] << " " << res[0][m] << '\n';
            ll te = ((ll)cini[a] * cfin[b]) % MOD;
            ans = (ans + te*res[0][rem]) % MOD;
        }
    }
    cout << ans << endl;
}