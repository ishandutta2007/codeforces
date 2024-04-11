#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

#define fr(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;

const ll N = 1e6 + 7;
const ll M = 1e3 + 3;
const ll md = 1e9+7;

using namespace std;

vector <ll> es[N];
ll ks[N], kk[N];
ll n, m, h, t, kol, ans, a1 = 1;
string s, k;
bool big, smal;

ll st(ll a, ll ste){
    if (ste == 0) return 1;
    if (ste == 1) return a;
    if (ste % 2 == 0){
        ll q = st(a, ste / 2);
        return (q * q) % md;
    }
    return (a * st(a, ste - 1)) % md;
}

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> n;
    if (n == 1){
        cout << "0";
        return 0;

    }
    cin >> s >> k;

    fr(i, n){
        if ('0' <= s[i] && '9' >= s[i] && '0' <= k[i] && '9' >= k[i])
            if (s[i] > k[i])
                big = true;
            else
                smal = true;
        else
            if (s[i] == '?' && k[i] == '?') kol++;
            else if (s[i] == '?') ks[k[i] - '0']++;
            else kk[s[i] - '0']++;
        if (s[i] == '?') h++;
        if (k[i] == '?') h++;
    }

    ans = st(10, h);

    if (true){
        a1 = 1;
        fr(i, n){
            if (s[i] == '?' && k[i] == '?') a1 = (a1 * 55) % md;
            else if (s[i] == '?') a1 = (a1 * ('9' - k[i] + 1)) % md;
            else if (k[i] == '?') a1 = (a1 * (s[i] - '0' + 1)) % md;
            else if (s[i] < k[i]) a1 = 0;
        }

        ans = (ans - a1 + md) % md;

    }

    if (true){
        a1 = 1;
        fr(i, n){
            if (s[i] == '?' && k[i] == '?') a1 = (a1 * 55) % md;
            else if (s[i] == '?') a1 = (a1 * (k[i] - '0' + 1)) % md;
            else if (k[i] == '?') a1 = (a1 * ('9' - s[i] + 1)) % md;
            else if (k[i] < s[i]) a1 = 0;
        }

        ans = (ans - a1 + md) % md;
    }

    a1 = 1;
    fr(i, n){
        if (s[i] == '?' && k[i] == '?') a1 = (a1 * 10) % md;
        if ('0' <= s[i] && '9' >= s[i] && '0' <= k[i] && '9' >= k[i] && s[i] != k[i]) a1 = 0;
    }
    ans = (ans + a1 + md) % md;

    cout << ans;

    return 0;
}