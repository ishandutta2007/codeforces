#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 1005;
ll c[MAX][MAX];
ll sumn, summ, summn, sumfk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < m; j++) {
            cin >> c[i][j];
        }
    }

    for(ll p = 2; p <= 4*n - 2; p += 4) {
        for(ll q = 2; q <= 4*m - 2; q += 4) {
            ll r = (p - 2)/4, s = (q - 2)/4;
            summn += c[r][s] * (p*p + q*q);
            summ += -2LL*p*c[r][s];
            sumn += -2LL*q*c[r][s];
            sumfk += c[r][s];
        }
    }

    ll ans = LLONG_MAX;
    ll xx = -1, yy = -1;
    for(ll x = 0; x <= 4*n; x += 4) {
        for(ll y = 0; y <= 4*m; y += 4) {

            ll wtf = summn + summ * x + sumn * y + sumfk * (x*x + y*y);
            if(wtf < ans) {
                ans = wtf;
                xx = x/4;
                yy = y/4;
            }
        }
    }
    cout << ans << '\n';
    cout << xx << " " << yy << '\n';
}