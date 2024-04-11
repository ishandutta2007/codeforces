/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s1 = "";
        string s2 = "";

        while (n--) {
            char c;
            cin >> c;
            int k = c - '0';

            if (s2 < s1) swap(s1, s2);

            if (k == 0) {
                s1.push_back('0');
                s2.push_back('0');
            } else if (k == 1) {
                s1.push_back('1');
                s2.push_back('0');
            } else if (k == 2) {
                if (s1 < s2) {
                    s1.push_back('2');
                    s2.push_back('0');
                } else {
                    s1.push_back('1');
                    s2.push_back('1');
                }
            }
        }

        cout << s1 << endl;
        cout << s2 << endl;
    }
    return 0;
}