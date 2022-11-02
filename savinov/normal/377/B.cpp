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

int a[100000], b[100000], c[100000];

int who[100000];

int n, m;
ll s;

int rem[100000];


struct cmp1 {
bool operator()(int i, int j)
{
    return a[i] < a[j] || (a[i] == a[j] && i < j);
}
};

struct cmp2 {
bool operator()(int i, int j)
{
    return b[i] < b[j] || (b[i] == b[j] && i < j);
}
};

struct cmp3 {
bool operator()(int i, int j)
{
    return c[i] > c[j] || (c[i] == c[j] && i < j);
}
};

bool check(int d)
{
    priority_queue<int, VI, cmp3> st;
    priority_queue<int, VI, cmp2> bugs;
    priority_queue<int, VI, cmp1> unused;
    vector <int> bought;
    for(int i = 0; i < n; ++i)
    {
        unused.push(i);
    }
    for(int i = 0; i < m; ++i)
    {
        bugs.push(i);
    }
    ll cost = 0;

    while(!bugs.empty())
    {
        int v = bugs.top();
        bugs.pop();
        if(!bought.empty())
        {
            who[v] = bought.back();
            bought.pop_back();
            continue;
        }
        while(!unused.empty() && a[unused.top()] >= b[v])
        {
            st.push(unused.top());
            unused.pop();
        }
        if (st.empty())
            return false;
        int to_buy = st.top();
        st.pop();
        who[v] = to_buy;
        cost += c[to_buy];
        for(int j = 0; j < d - 1; ++j)
            bought.push_back(to_buy);
    }
    return cost <= s;
}


int main()
{
    input(n); input(m);
    cin >> s;

    for(int i = 0; i < m; ++i)
    {
        b[i] = nxt();
    }

    for(int i = 0; i < n; ++i)
    {
        a[i] = nxt();
    }

    for(int i = 0; i < n; ++i)
    {
        c[i] = nxt();
    }

    int l = 1, r = m + 1;

    while(l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
        //cout << l << " " << r << endl;
    }

    if (l == m + 1)
    {
        puts("NO");
    }
    else
    {
        check(l);
        puts("YES");
        for(int i = 0; i < m; ++i)
        {
            if (i) cout << " ";
            cout << who[i] + 1;
        }
        cout << endl;
    }

    return 0;
}