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

const int N = 100000;

int p[N];
ll s[N];

int get(int v)
{
    if (p[v] != v)
        return p[v] = get(p[v]);
    else
        return v;
}

void unite(int a, int b, ll len)
{
    a = get(a);
    b = get(b);
    if (a == b)
    {
        s[a] += len;
    }
    else
    {
        p[a] = b;
        s[b] += s[a] + len;
    }
}

struct cmp
{
    bool operator()(int a, int b)
    {
        return s[a] > s[b];
    }
};

int main()
{
    in(n); in(m); in(need); in(con);
    for(int i = 0; i < n; ++i)
    {
        p[i] = i;
        s[i] = 0;
    }
    while(m--)
    {
        int from = nxt() - 1;
        int to = nxt() - 1;
        ll len = nxt();
        unite(from, to, len);
    }

    priority_queue<int, vector<int>, cmp> q;

    for(int i = 0; i < n; ++i)
    {
        if (p[i] == i)
            q.push(i);
    }

    vector <PII> ans;

    while((int)q.size() > con)
    {
        if (need == 0)
        {
            puts("NO");
            return 0;
        }
        --need;
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();

        ll len = min(1000000000ll, s[a] + s[b] + 1);

        unite(a, b, len);

        ans.pb(mp(a, b));

        if (p[a] == a)
            q.push(a);
        else
            q.push(b);
    }

    if ((int)q.size() != con)
    {
        puts("NO");
        return 0;
    }

    if (need > 0)
    {
        int found = -1;
        for(int i = 0; i < n; ++i)
            if (p[i] != i)
                found = i;
        if (found == -1)
        {
            puts("NO");
            return 0;
        }
        while(need--)
        {
            ans.pb(mp(found, p[found]));
        }
    }

    puts("YES");

    for(auto v : ans)
    {
        cout << v.x + 1 << " " << v.y + 1 << endl;
    }

    return 0;
}