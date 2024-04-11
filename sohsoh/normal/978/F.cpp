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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define debug2(x)                   cerr << #x << ": " <<  x <<  " ";
#define debug_p(x)                  cerr << #x << ": " <<  x.X <<  " " << x.Y << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define FOR(n)                      for (int i = 0; i < n; i++)
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define kill(x)                     return cout << x << endl, 0;

ll poww(ll a, ll b, ll md) {
    if (b == -1) return poww(a, md - 2, md);
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll bq[MAXN] = {0};
pll skill[MAXN];
pll score[MAXN];

bool comp(pll a, pll b) {
    return a.Y < b.Y;
}

int main() {
    fast_io;
    ll n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> skill[i].X;
        skill[i].Y = i;
    }

    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        x--; y--;

        if (skill[x].X > skill[y].X) bq[x]++;
        else if (skill[y].X > skill[x].X) bq[y]++;
    }

    sort(skill, skill + n);
    for (int i = 0; i < n; i++) {
        score[i].Y = skill[i].Y;
        if (i != 0 && skill[i].X == skill[i - 1].X) score[i].X = score[i - 1].X;
        else score[i].X = i;
    }

    sort(score, score + n, comp);
    for (int i = 0; i < n; i++) {
        cout << score[i].X - bq[i] << sep;
    }

    cout << endl;
    return 0;
}