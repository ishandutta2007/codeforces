#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
using namespace std;

#define TRACE(x...) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define PRINT(x...) TRACE(printf(x))

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define FU(i, a, b) for(decltype(a) i = (a); i < (b); ++i)
#define fu(i, n) FU(i, 0, n)

#define mset(c, v) memset(c, v, sizeof(c))
#define mod(a, b) ((((a)%(b))+(b))%(b))
#define pb push_back
#define SZ(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-8;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;
typedef long long ll;


int cmp(double x, double y = 0, double tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a%b);
}
map<ll, ll> mem;
ll f(ll x, vi& b) {
    if (mem.count(x)) return mem[x];
    ll y = 2;
    ll ans = 0;
    while (y*y <= x) {
        if (x % y == 0) {
            bool bad = binary_search(all(b), y);
            mem[x] = (bad?-1:1) + f(x/y, b);
            return mem[x];
        }
        y++;
    }
    mem[x] = 0;
    if (x != 1) mem[x] += binary_search(all(b), x)?-1:1;
    return mem[x];
}

int main() {
    int n, m;
    mem.clear();
    cin >> n >> m;
    vi a(n), b(m);
    int g = 0;
    ll sum = 0;
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    sort(all(b));
    ll count = 1;
    vector<long long> imp;
    for (int x : a) {
        sum += f(x, b);
        g = gcd(g, x);
        imp.push_back(-f(g, b));
        count++;
    }
    ll sofar = 0;
    ll best = 0;
    for (int i = n-1; i >= 0; --i) {
        if ((imp[i] - sofar)*(i+1) > 0) {
            best += (imp[i] - sofar)*(i+1);
            sofar = imp[i];
        }
    }
    cout << sum + best << endl;
    return 0;
}