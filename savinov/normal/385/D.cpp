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


bool doubleEqual(double a, double b) //     eps,  1-9   
{
        return fabs(a - b) < 1e-9;
}


bool doubleLessOrEqual(double a, double b) // <=  eps
{
        return a < b || doubleEqual(a, b);
}


bool doubleLess(double a, double b) // <  eps
{
        return a < b && !doubleEqual(a, b);
}


bool doubleGreaterOrEqual(double a, double b) // >=  eps
{
        return a > b || doubleEqual(a, b);
}


bool doubleGreater(double a, double b) // >  eps
{
        return a > b && !doubleEqual(a, b);
}


double mySqrt(double a) // mySqrt  ,   
{
        if(doubleLess(a, 0) ) // 
        {
                throw "sqrt(-1)";
        }
        if(a < 0) return 0; //   
        return sqrt(a);
}


struct Point{ //    ,       
                                //   (  )     (A, B, C, D, ...)
                                //  - (v, u, w,...)
double x, y; // 2  ,   
        Point(): x(0), y(0) {} //   

        Point(double x, double y): x(x), y(y) {} //      Point(x = 0...)                                                                                      //      Point A = 2;

        Point operator+(const Point & p) const //  2 
        {
                return Point(x + p.x, y + p.y);
        }

        Point operator-(const Point & p) const //  2 
        {
                return Point(x - p.x, y - p.y);
        }

        Point operator-() const //  
        {
                return Point(-x, -y);
        }

        Point operator*(double k) const //    
        {
                return Point(x * k, y * k);
        }

        Point operator/(double k) const //    
        {
                return Point(x / k, y / k);
        }

        double operator%(const Point & p) const //  
        {
                return x * p.x + y * p.y;
        }

        double operator*(const Point & p) const //  
        {
                return x * p.y - y * p.x;
        }

        Point rotate() const //   90     ( )
        {
                return Point(-y, x);
        }

        Point rotate(double alpha) const //    alpha   
                                                                        // (  ,  alpha < 0)
        {
                return rotate(cos(alpha), sin(alpha) ); //     
        }

        Point rotate(double cosa, double sina) const //      
        {
                Point v = *this;
                Point u = v.rotate(); // ,  v,  (v, u) - ,     
                Point w = v * cosa + u * sina; //     (v, u),  w
                return w;
        }
};

int x[20], y[20], a[20];

int l, r;

double solve(int pos, double xx)
{
    Point U(xx - x[pos], -y[pos]);
    Point B = U.rotate(PI * a[pos] / 180);


    if (B.y > -1e-9)
    {
        return r;
    }

    double t = -y[pos] / B.y;

    double res = x[pos] + B.x * t;

    return min((double)r, res);
}


int main()
{
    in(n);
    input(l);
    input(r);


    for(int i = 0; i < n; ++i)
    {
        x[i] = nxt();
        y[i] = nxt();
        a[i] = nxt();
    }

    double dp[1 << n];

    for(int i = 0; i < (1 << n); ++i)
    {
        if (i == 0)
        {
            dp[i] = l;
        }
        else
        {
            dp[i] = l;
            for(int j = 0; j < n; ++j)
            {
                if ((i >> j) & 1)
                {
                    dp[i] = max(dp[i], solve(j, dp[i ^ (1 << j)]));
                }
            }
        }
    }

    cout << setprecision(13) << fixed;
    cout << (dp[(1 << n) - 1] - l) << endl;


    return 0;
}