#include "bits/stdc++.h"

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
    static int c;
    a = 0;
    while (!isdigit(c = getchar()) && c != '-') {}
    char neg = 0;
    if (c == '-') {
        neg = 1;
        c = getchar();
    }
    while (isdigit(c)) {
        a = 10 * a + c - '0';
        c = getchar();
    }
    if (neg) a = -a;
}


template<typename T = int>
inline T nxt() {
    T res;
    input(res);
    return res;
}

inline string next() {
    static int c;
    string res;
    while (isspace(c = getchar())) {}
    while (!isspace(c)) {
        res = res + (char)c;
        c = getchar();
    }
    return res;
}

const int MAXMEM = 2e8;

char buf[MAXMEM];
char * cur = buf;

void * operator new(size_t n) {
    char * res = cur;
    cur += n;
    assert(cur - buf <= MAXMEM);
    return res;
}

void operator delete(void * x) {
}

string s;
string t;
vector <long long> hashes;
vector <long long> powers;
vector <int> balances;
long long mod = 1000000009;

long long getHash(int pos, int len) {
    return (hashes[pos + len] - hashes[pos] * powers[len] % mod + mod) % mod;
}

int lcp(int a, int b) {
    int l = 0, r = min(t.length() - a, t.length() - b);
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (getHash(a, mid) == getHash(b, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

bool compare(int a, int b) {
    int len = lcp(a, b);
    return t[a + len] < t[b + len];
}

struct queueMin {

    queueMin() {}

    deque <int> q;

    int min() {
        return q.front();
    }

    void push(int x) {
        while (!q.empty() && q.back() > x)
            q.pop_back();
        q.push_back (x);
    }

    void pop(int x) {
        if (!q.empty() && q.front() == x)
            q.pop_front();
    }
};

int main() {
    //#define int long
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
#define fname "a"
    //freopen(fname".in", "r", stdin);
    //freopen(fname".out", "w", stdout);
#endif

    cin >> s;
    t = s + s;
    t += "#";
    hashes.resize(t.length() + 1);
    powers.resize(t.length() + 1);
    hashes[0] = 0;
    powers[0] = 1;
    for (int i = 0; i < t.length(); ++i) {
        hashes[i + 1] = (hashes[i] * 137 + t[i]) % mod;
        powers[i + 1] = powers[i] * 137 % mod;
    }
    balances.resize(2 * s.length());
    int b = 0;
    for (int i = 0; i < 2 * s.length(); ++i) {
        b += t[i] == '(' ? 1 : -1;
        balances[i] = b;
    }

    int balance = 0;

    for (char c : s) {
        balance += c == '(' ? 1 : -1;
    }

    queueMin q;

    int best = -1;
    int curBalance = 0;
    for (int i = 0, j = 0; i < s.length(); ++i) {
        while (j < i + s.length()) {
            q.push(balances[j++]);
        }
        if (q.min() - curBalance - min(balance, 0) >= 0) {
            if (best == -1 || compare(i, best)) {
                best = i;
            }
        }
        q.pop(balances[i]);
        curBalance = balances[i];
    }
    rotate(s.begin(), s.begin() + best, s.end());
    s = string(max(0, -balance), '(') + s + string(max(0, balance), ')');

    cout << s << "\n";



#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}