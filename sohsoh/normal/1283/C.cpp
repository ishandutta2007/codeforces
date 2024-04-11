/*
    Soheil Mohammadkhani
    hello friend :)
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e17;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool recive[MAXN] = {false};
ll a[MAXN], n;

ll aa[MAXN], bb[MAXN], aas = 0, bbs = 0;
ll nxt(ll i) {
    if (i + 1 == bbs) return 0;
    return i + 1;
}

int main() {
    fast_io;
    queue<ll> f, nr;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            aa[aas] = i;
            aas++;
        }
        recive[a[i]] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!recive[i]) {
            bb[bbs] = i;
            bbs++;
        }
    }

    for (int i = 0; i < aas; i++) {
        if (aa[i] == bb[i]) {
            swap(aa[i], aa[nxt(i)]);
        }
    }

    for (int i = 0; i < aas; i++) {
        a[aa[i]] = bb[i];
    }

    for (int i = 1; i <= n; i++) cout << a[i] << sep; cout << endl;
}