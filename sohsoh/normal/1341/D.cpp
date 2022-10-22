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
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 2000 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, m;
string dig[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string a[MAXN];
ll mn[MAXN];

int change(string s, int k) {
    ll mov = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1' && dig[k][i] == '0') {
            return INF;
        }

        if (s[i] != dig[k][i]) {
            mov++;
        }
    }

    return mov;
}

int min_change(string s) {
    ll res = INF;
   for (int j = 0; j < 10; j++) {
        ll mov = 0;
        bool can = true;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1' && dig[j][i] == '0') {
                mov = INF;
                break;
            }

            if (s[i] != dig[j][i]) {
                mov++;
//                if (j == 1) debug(i);
            }
        }

        res = min(res, mov);
   }

   return res;
}

int main() {
    fast_io;
    cin >> n >> m;

    fill(mn, mn + MAXN, INF);

    for (int i = 0; i < n; i++) cin >> a[i];

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll k = min_change(a[i]);
        if (k > 100) {
            return cout << "-1" << endl, 0;
        }

        mn[i] = k;
        sum += k;
    }

//    cout << sum << endl;

    if (sum > m) return cout << "-1" << endl, 0;

    string res = "";
    for (int i = 0; i < n; i++) {
        sum -= mn[i];
        string s = a[i];
        for (int j = 9; j >= 0; j--) {
            if (change(s, j) + sum <= m) {
                m -= change(s, j);
                res.push_back(j + '0');
                break;
            }
        }
    }


    string res_end = "";
    while (m > 0 && !res.empty()) {
        ll ma = 0;
        ll mai = 0;


        string s = a[res.size() - 1];
        m += change(s, res.back() - '0');

        res.pop_back();
        for (int i = 0; i < 10; i++) {
            if (change(s, i) <= m && change(s, i) > ma) {
                ma = change(s, i);
                mai = i;
            }
        }


        res_end.insert(res_end.begin(), char(mai + '0'));
        m -= ma;
    }

    if (m > 0) return cout << "-1" << endl, 0;
    cout << res + res_end << endl;

    return 0;
}