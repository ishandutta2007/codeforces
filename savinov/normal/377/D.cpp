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

int res[1 << 20];
int pos[1 << 20];
int add[1 << 20];


void build(int v, int tl, int tr)
{
    //cout << v << " " << tl << " " << tr << endl;
    pos[v] = tl;
    res[v] = 0;
    if (tl == tr)
        return;
    int tm = (tl + tr) >> 1;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
}

void update(int v, int tl, int tr, int l, int r, int ad)
{
    if (l > r) return;
    if (tl == l && tr == r)
    {
        add[v] += ad;
        return;
    }
    int tm = (tl + tr) >> 1;
    update(v + v, tl, tm, l, min(tm, r), ad);
    update(v + v + 1, tm + 1, tr, max(tm + 1, l), r, ad);

    res[v] = res[v + v] + add[v + v];
    pos[v] = pos[v + v];

    if (res[v] < res[v + v + 1] + add[v + v + 1])
    {
        res[v] = res[v + v + 1] + add[v + v + 1];
        pos[v] = pos[v + v + 1];
    }
}


const int N = 300000;

vector <int> insert[N + 1];
vector <int> erase[N + 1];

int main()
{
    in(n);

    build(1, 0, N);
    int l[n], v[n], r[n];

    for(int i = 0; i < n; ++i)
    {
        l[i] = nxt();
        v[i] = nxt();
        r[i] = nxt();
        insert[v[i]].pb(i);
        erase[l[i] - 1].pb(i);
    }

    int cur_l = -1, cur_r = -1, ans = 0;

    for(int i = N; i >= 1; --i)
    {
        for(int g : erase[i])
            update(1, 0, N, v[g], r[g], -1);
        for(int g : insert[i])
            update(1, 0, N, v[g], r[g], 1);

        if (res[1] > ans)
        {
            cur_l = i;
            cur_r = pos[1];
            ans = res[1];
        }
    }

    vector <int> an;

    for(int i = 0; i < n; ++i)
    {
        if (l[i] <= cur_l && r[i] >= cur_r && v[i] >= cur_l && v[i] <= cur_r)
            an.pb(i);
    }

    cout << an.size() << endl;


    for(int i = 0; i < (int)an.size(); ++i)
    {
        if (i) cout << " ";
        cout << an[i] + 1;
    }

    cout << endl;

    return 0;
}