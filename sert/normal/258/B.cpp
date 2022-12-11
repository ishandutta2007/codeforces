#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 340;
const ll INF = 1e9;
const ll md = 1e9 + 7;
const ll o720 = 301388891;

ll d[15][15][2], n;
ll a[15], l[15];
ll k[15];
ll kol[15][200];
ll ans;
ll kk[15];
ll sum, t;
string s;

ll cnk(ll n1, ll k1) {
    ll an = 1;
    for (int i = 0; i < k1; i++)
        an = (an * (n1 - i)) % md;
    //ans = (ans * o720) % md;
    return an;
}

void rnd(int len) {
    if (len == 6) {
        t = 0;
        for (int i = sum + 1; i < 10; i++) {
            t = (t + k[i]) % md;
        }

        //if (t) {for (int i = 0; i < 10; i++) cout << kk[i] << " "; cout << sum << "\n";}
        
        for (int i = 0; i < 10; i++)
            t = (t * cnk(k[i], kk[i])) % md;
        ans = (ans + t) % md;
        return;
    }
    for (int i = 0; i <= 9; i++) {
        kk[i]++;
        sum += i;
        if (sum < 11)
            rnd(len + 1);
        sum -= i;
        kk[i]--;
    }
}

int main() {

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    //cout << (o720 * 720ll) % md << "\n";

    cin >> s;
    l[4] = l[7] = 1;
    n = s.length();
    for (int i = 0; i < n; i++)
        a[i] = (s[i] == '4' || s[i] == '7');
    d[0][0][1] = 1;
    for (int len = 1; len <= n; len++)
        for (int g = 0; g <= n; g++) {
            if (g >= l[s[len - 1] - '0'])
                d[len][g][1] = d[len - 1][g - l[s[len - 1] - '0']][1];
            d[len][g][0] = (d[len][g][0] + d[len - 1][g][0] * 8 + (g ? d[len - 1][g - 1][0] * 2 : 0)) % md;
            for (int c = 0; c < s[len - 1] - '0'; c++)
                if (g >= l[c])
                    d[len][g][0] = (d[len][g][0] + d[len - 1][g - l[c]][1]) % md;
        }

    /*for (int g = 0; g < 2; g++) {
        cout << d[1][g][0] << " " << d[1][g][1] << "\n";
    }*/

    for (int i = 0; i <= n; i++)
        k[i] = (d[n][i][0] + d[n][i][1]) % md;
    k[0]--;

    rnd(0);

    cout << ans;

    return 0;
}