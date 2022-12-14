#include <iostream>
#define FOR(i,l,r) for(int i=(l); i<=(r); ++i)
#define REP(i,l,r) for(int i=(l); i<(r); ++i)
#define FORD(i,r,l) for(int i=(r); i>=(l); --i)
#define REPD(i,r,l) for(int i=(r)-1; i>=(l); --i)
using namespace std;
const int N = 1e5 + 5;
int n, m, x, y, vx, vy;

void Enter() {
    cin >> n >> m >> x >> y >> vx >> vy;
}

long long modul(long long x, long long mod) {
    return (x % mod + mod) % mod;
}

long long Extended_Euclidean(int a, int b, long long &x, long long &y) {
    if (a == 0) {
        x = 0;
        y = (b < 0 ? -1 : 1);
        return abs(b);
    }
    long long x1, y1;
    long long gcd = Extended_Euclidean(b%a, a, x1, y1);

    /// x1 * (b - b/a * a) + y1 * a = gcd
    /// a * (y1 - b/a * x1) + b * x1 = gcd
    x = y1 - b/a * x1;
    y = x1;
    return gcd;
}

void Process() {
    /// first_distx + a * n = first_disty + b * m
    /// a * n + b * (-m) = first_disty - first_distx = c
    /// wait
    if (vx == 0 || vy == 0) {
        if (vx == 0) {
            if (x != 0 && x != n) cout << "-1\n";
            else {
                if (vy == -1) cout << x << ' ' << 0 << '\n';
                else cout << x << ' ' << n << '\n';
            }
        }
        else {
            if (y != 0 && y != m) cout << "-1\n";
            else {
                if (vx == -1) cout << 0 << ' ' << y << '\n';
                else cout << m << ' ' << y << '\n';
            }
        }
        return;
    }
    int first_distx, first_disty;
    if (vx == -1) first_distx = x; else first_distx = n - x;
    if (vy == -1) first_disty = y; else first_disty = m - y;
    int c = first_disty - first_distx;

    long long x, y;
    long long gcd = Extended_Euclidean(n, -m, x, y);
    if (c % gcd) return void(cout << "-1\n");

    n /= gcd; m /= gcd; c /= gcd;
    x = modul(modul(x, m) * c, m);
    y = (c - x * n) / -m;

    int ansx = 0, ansy = 0;
    if ((x&1) == (vx==-1)) ansx = n * gcd; else ansx = 0;
    if ((y&1) == (vy==-1)) ansy = m * gcd; else ansy = 0;
    cout << ansx << ' ' << ansy << '\n';
}

int main()
{
    #define file ""
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if (fopen(file".inp","r")) {
        freopen(file".inp","r",stdin);
        freopen(file".out","w",stdout);
    }
    Enter();
    Process();
}