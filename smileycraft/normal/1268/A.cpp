
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n, k;
    string s;
    cin >> n >> k >> s;
    string r = s;
    for (ll i = 0; i < k; ++i) for (ll j = 0; i + j * k < n; ++j) r[i + j * k] = s[i];
    if (r < s){
        for (ll i = k - 1; (++s[i]) == ':'; --i) s[i] = '0';
        for (ll i = 0; i < k; ++i) for (ll j = 0; i + j * k < n; ++j) r[i + j * k] = s[i];
    }
    cout << r.size() << endl;
    cout << r << endl;
    return 0;
}