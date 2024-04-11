/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size());
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define bug(x)                      cerr << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define forr(n)                     for (int i = 0; i < n; i++)

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); //cout << "__________________________________________" << endl;
    string ss;
    cin >> ss;
    ll n = ss.size();
    ll* s = new ll[n];
    forr(n) {
        s[i] = ss[i] - 'a';
    }
    ll a[26] = {0};
    forr(n) a[s[i]]++;
    ll m = *max_element(a, a + 26);

    ll c[26][26] = {0};

    for (int i = 0; i < n; i++) {
        a[s[i]]--;
        for (int j = 0; j < 26; j++) {
            c[s[i]][j] += a[j];
            m = max(c[s[i]][j], m);
        }
    }

    cout << m << endl;

    return 0;
}