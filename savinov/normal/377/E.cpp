#include <bits/stdc++.h>
#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define For(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define in(x) int (x); input((x));
#define x first
#define y second
#define less(a,b) ((a) < (b) - EPS)
#define more(a,b) ((a) > (b) + EPS)
#define eq(a,b) (fabs((a) - (b)) < EPS)
#define remax(a, b) ((a) = (b) > (a) ? (b) : (a))
#define remin(a, b) ((a) = (b) < (a) ? (b) : (a))
using namespace std;
typedef long double ld; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1-9; char TEMPORARY_CHAR; typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(int a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[10]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

using namespace std;

struct Building
{
    ll speed;
    ll cost;
    bool operator<(const Building & r) const
    {
        return speed < r.speed || (speed == r.speed && cost < r.cost);
    }
};

struct Point
{
    ll x, y, slope;
    bool operator<(const Point & r) const
    {
        return y < r.y;
    }
};

const ll inf = LLONG_MAX / 2;


ll mul(ll a, ll b)
{
    double res = (double)a * b;
    if (res > inf)
        return inf;
    else
        return a * b;
}

int main()
{
    in(n);
    ll s;
    cin >> s;

    Building buildings[n];

    for(int i = 0; i < n; ++i)
    {
        buildings[i].speed = nxt();
        buildings[i].cost = nxt();
    }
    sort(buildings, buildings + n);

    vector <Point> z;

    for(int i = 0; i < n; ++i)
    {
        if (i && buildings[i].speed == buildings[i - 1].speed)
            continue;
        if (z.empty() && buildings[i].cost)
            continue;
        if (!buildings[i].cost)
        {
            z.clear();
            z.push_back(Point{0, 0, buildings[i].speed});
        }
        else
        {
            int pos = upper_bound(all(z), Point{0, buildings[i].cost, 0}) - z.begin() - 1;

            ll x0 = z[pos].x + (buildings[i].cost - z[pos].y + z[pos].slope - 1) / z[pos].slope;

            ll y0 = z[pos].y + (x0 - z[pos].x) * z[pos].slope - buildings[i].cost;

            if (pos + 1 != (int)z.size())
            {
                if (x0 >= z[pos + 1].x)
                {
                    x0 = z[pos + 1].x;
                    y0 = z[pos + 1].y - buildings[i].cost;
                }
            }

            //cout << time << endl;

            while(z.back().y <= y0 + mul(z.back().x - x0, buildings[i].speed))
                z.pop_back();

            ll xx = (z.back().y - y0 + x0 * buildings[i].speed - z.back().x * z.back().slope + buildings[i].speed - z.back().slope - 1) / (buildings[i].speed - z.back().slope);
            ll yy = y0 + (xx - x0) * buildings[i].speed;
            //cout << xx << endl;
            //cout << yy << endl;
            z.push_back(Point{xx, yy, buildings[i].speed});
        }
    }

    for(int i = 0; i < (int)z.size(); ++i)
    {
        //cout << z[i].x << " " << z[i].y << " " << z[i].slope << endl;
    }

    int pos = upper_bound(all(z), Point{0, s, 0}) - z.begin() - 1;

    ll time = z[pos].x + (s - z[pos].y + z[pos].slope - 1) / z[pos].slope;

    if (pos + 1 != (int)z.size())
        remin(time, z[pos + 1].x);
    cout << time << endl;

    return 0;
}