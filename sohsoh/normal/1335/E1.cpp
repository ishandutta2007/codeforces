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
#define debug(x)                    cout << #x << ": " <<  x << endl;
#define bug(x)                      cout << #x << ": " <<  x <<  " ";
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;


ll dataa[MAXN] = {0};

int solve() {
    int n;
    cin >> n;
    int* a = new int[n];

    set<int> h;
    set<int> h2;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        h.insert(a[i]);
        h2.insert(a[i]);
    }


    ll m = 0;
    for (int x : h) {
        ll tmp = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x)  tmp++;
        }
        m = max(m, tmp);

        for (int y : h2) {
            ll bc = 0;
            ll ac = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == y) bc++;
                if (a[i] == x) ac++;
            }

            if (ac < 2 || bc == 0 || x == y) continue;


//             bug(x)
//            bug(y)
//            bug(ac)
//            debug(bc)

            ac /= 2;
            ll bct = bc;
            ll bn = 0;
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == y) bn++;
                if (a[i] == x) {
                    dataa[j] = bn;
                    j++;
                }
            }

            bc = bct;
            bn = 0;
            reverse(a, a + n);


            j = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == y) bn++;
                if (a[i] == x) {
                    dataa[j] += bn;
                    j++;
                }
            }

//            cout << "D: ";
//            alog(data, ac)

            for (int i = 0; i < ac; i++) {
                if (bc - dataa[i] <= 0) continue;
                m = max(m, (i + 1) * 2 + bc - dataa[i]);
            }
        }
    }

    cout << m << endl;

}

int main() {
    fast_io;
//    cout << "A" << endl;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;
}