#include <bits/stdc++.h>

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define in(x) int (x); input((x));
#define x first
#define y second
typedef int itn;

#define next next12345
#define prev prev12345
#define left lefdsf232
#define right rig43783
#define x1 x12345
#define y1 y12345

using namespace std;

template<typename T>
T gcd(T x, T y) {
    while (y > 0) {
        x %= y;
        swap(x, y);
    }
    return x;
}

template<class _T>
inline _T sqr(const _T &x) {
    return x * x;
}

template<class _T>
inline string tostr(const _T &a) {
    ostringstream os("");
    os << a;
    return os.str();
}

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
const long double PI = 3.1415926535897932384626433832795L;

template<typename T>
inline void input(T &a) {
    static int ed;
    a = 0;
    while (!isdigit(ed = getchar()) && ed != '-') { }
    char neg = 0;
    if (ed == '-') {
        neg = 1;
        ed = getchar();
    }
    while (isdigit(ed)) {
        a = 10 * a + ed - '0';
        ed = getchar();
    }
    if (neg) a = -a;
}

template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

mt19937 generator;

long long mod = 1000000007;

void fib(unsigned long long n, long long &x, long long &y) {
    if (n == 1) {
        x = 0, y = 1;
        return;
    }
    if (n & 1ull) {
        fib(n - 1, y, x);
        y += x;
        y %= mod;
    } else {
        long long a, b;
        fib(n / 2, a, b);
        x = (a * a + b * b) % mod;
        y = (2 * a + b) * b % mod;
    }
}

long long pw(long long a, long long n) {
    long long res = 1;
    while (n) {
        if (n & 1ll) {
            res = res * a % mod;
        }
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

struct Convex {
    int pointer = 0; //Keeps track of the best line from previous query
    vector<long long> M; //Holds the slopes of the lines in the envelope
    vector<long long> B; //Holds the y-intercepts of the lines in the envelope
//Returns true if either line l1 or line l3 is always better than line l2
    bool bad(int l1,int l2,int l3)
    {
        /*
        intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1)
        intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1)
        set the former greater than the latter, and cross-multiply to
        eliminate division
        */
        return (B[l3]-B[l1])*(M[l1]-M[l2])<(B[l2]-B[l1])*(M[l1]-M[l3]);
    }
//Adds a new line (with lowest slope) to the structure
    void add(long long m,long long b)
    {
        //First, let's add it to the end
        M.push_back(m);
        B.push_back(b);
        //If the penultimate is now made irrelevant between the antepenultimate
        //and the ultimate, remove it. Repeat as many times as necessary
        while (M.size()>=3&&bad(M.size()-3,M.size()-2,M.size()-1))
        {
            M.erase(M.end()-2);
            B.erase(B.end()-2);
        }
    }
//Returns the minimum y-coordinate of any intersection between a given vertical
//line and the lower envelope
    double query(double x)
    {
        //If we removed what was the best line for the previous query, then the
        //newly inserted line is now the best for that query
        if (pointer>=M.size())
            pointer=M.size()-1;
        //Any better line must be to the right, since query values are
        //non-decreasing
        while (pointer + 1<M.size()&&
               M[pointer+1]*x+B[pointer+1]<M[pointer]*x+B[pointer])
            pointer++;
        return M[pointer]*x+B[pointer];
    }
};

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "race"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif


    int n = nxt();

    long long s[n + 1];
    clr(s);

    for (int i = 0; i < n; ++i) {
        s[i + 1] = s[i] + nxt();
    }

    Convex mi, ma;

    for (int i = 0; i <= n; ++i) {
        mi.add(-i, s[i]);
    }

    for (int i = n; i >= 0; --i) {
        ma.add(i, -s[i]);
        //cout << "MI " << -i << " " << s[i] << "\n";
    }

//    cout << mi.B.size() << "\n";
//    cout << ma.B.size() << "\n";

    vector <double> events;

    for (int i = 0; i + 1 < mi.B.size(); ++i) {
        events.push_back((double)(mi.B[i + 1] - mi.B[i]) / (mi.M[i] - mi.M[i + 1]));
    }
//    for (int i = 0; i < mi.B.size(); ++i) {
//        cout << mi.M[i] << " " << mi.B[i] << "\n";
//    }

    for (int i = 0; i + 1 < ma.B.size(); ++i) {
        events.push_back((double)(ma.B[i + 1] - ma.B[i]) / (ma.M[i] - ma.M[i + 1]));
    }

    stable_sort(all(events));

    long double res = LDBL_MAX;

    for (const double & x : events) {
        long double ans = -mi.query(x) - ma.query(x);
        //cerr << x << " " << ans << "\n";
        res = min(res, ans);
    }

    cout << setprecision(10) << fixed;
    cout << res << endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}