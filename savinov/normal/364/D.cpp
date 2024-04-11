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

ll gcd(ll a, ll b)
{
    while(b)
    {
        ll t = a;
        a = b;
        b = t % b;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    //scanf("%d", &n);
    ll a[n];
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    random_shuffle(a, a + n);

    int delta = max(1, n/11);

    ll ans = 0;

    for(int i = 0; i < n; i+=delta)
    {
        vector <ll> d;
        ll j;
        for(j = 1; j * j < a[i]; ++j)
        {
            if (a[i] % j == 0)
            {
                d.pb(j);
                d.pb(a[i] / j);
            }
        }
        if (j * j == a[i])
            d.pb(j);
        sort(all(d));
        int cnt[d.size()];
        clr(cnt);

        for(int p = 0; p < n; ++p)
        {
            ll g = gcd(a[i], a[p]);
            //cout << p << endl;
            cnt[lower_bound(all(d), g) - d.begin()]++;
        }

        for(int k = 0; k < (int)d.size(); ++k)
            for(int l = k + 1; l < (int)d.size(); ++l)
                if (d[l] % d[k] == 0)
                    cnt[k] += cnt[l];
        for(int k = 0; k < (int)d.size(); ++k)
        {
            if (2 * cnt[k] >= n)
                remax(ans, d[k]);
        }
    }

    cout << ans << endl;
    return 0;
}