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

template <typename T>
T gcd(T a, T b) {
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

typedef long double ld; typedef unsigned int uint; template <class _T> inline _T sqr(const _T& x) {return x * x;} template <class _T> inline string tostr(const _T& a) {ostringstream os(""); os << a; return os.str();} const ld PI = 3.1415926535897932384626433832795L; const double EPS = 1e-9; char TEMPORARY_CHAR;

typedef long long ll; typedef unsigned long long ull; typedef set < int > SI; typedef vector < int > VI; typedef vector < vector < int > > VVI; typedef map < string, int > MSI; typedef pair < int, int > PII; const int INF = 1e9; inline void input(int &a) {a = 0; while (((TEMPORARY_CHAR = getchar()) > '9' || TEMPORARY_CHAR < '0') && (TEMPORARY_CHAR != '-')){} char neg = 0; if (TEMPORARY_CHAR == '-') {neg = 1; TEMPORARY_CHAR = getchar();} while (TEMPORARY_CHAR <= '9' && TEMPORARY_CHAR >= '0') {a = 10 * a + TEMPORARY_CHAR - '0'; TEMPORARY_CHAR = getchar();} if (neg) a = -a;} inline void out(long long a) {if (!a) putchar('0'); if (a < 0) {putchar('-'); a = -a;} char s[20]; int i; for(i = 0; a; ++i) {s[i] = '0' + a % 10; a /= 10;} ford(j, i) putchar(s[j]);} inline int nxt() {in(ret); return ret;}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#else
    //string name = "afftar";
    //freopen((name + ".in").c_str(), "r", stdin);
    //freopen((name + ".out").c_str(), "w", stdout);
#endif

    in(n);
    int a[n];
    int c[2][n + 1];
    clr(c);
    for (int i = 0; i < n; ++i) {
        a[i] = nxt() - 1;
        c[0][i + 1] = c[0][i];
        c[1][i + 1] = c[1][i];
        c[a[i]][i + 1]++;
        //cout << c[0][i + 1] << " " << c[1][i + 1] << endl;
    }


    vector <PII> ans;

    for (int i = 1; i <= n; ++i) {
        int pos = 0;
        int w[2];
        clr(w);
        int lastWin = -1;

        while (pos < n) {
            int l = pos, r = n - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (c[0][m + 1] - c[0][pos] < i) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            int PO = l;
            l = pos, r = n - 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (c[1][m + 1] - c[1][pos] < i) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
            PO = min(PO, l);
            int win = -1;
            if (c[0][PO + 1] - c[0][pos] == i) {
                win = 0;
            }
            if (c[1][PO + 1] - c[1][pos] == i) {
                win = 1;
            }
            if (win == -1) {
                goto l1;
            }
            w[win]++;
            lastWin = win;
            pos = PO + 1;
            //cerr << pos << ",";
        }
//        cerr << endl;
//        cerr << i << endl;
//        cerr << w[0] << " " << w[1] << endl;
//        cerr << lastWin << endl;
        if (w[lastWin] > w[lastWin ^ 1]) {
            ans.push_back(mp(w[lastWin], i));
        }
        l1:;
    }

    sort(all(ans));

    cout << ans.size() << endl;

    for (auto x : ans) {
        cout << x.x << " " << x.y << "\n";
    }



#ifdef LOCAL
    cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
#endif // LOCAL




    return 0;
}