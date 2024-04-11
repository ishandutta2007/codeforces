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

typedef vector <int> poly;

struct m_complex {
    float x, y;
    m_complex operator*(const m_complex & r) const {
        return m_complex{x * r.x - y * r.y, x * r.y + y * r.x};
    }
    m_complex operator+(const m_complex & r) const {
        return m_complex{x + r.x, y + r.y};
    }
    m_complex operator-(const m_complex & r) const {
        return m_complex{x - r.x, y - r.y};
    }
    m_complex operator/(const double & r) const {
        return m_complex{x / r, y / r};
    }
};

const int N = 1 << 20;

m_complex pw[N];

void fft(m_complex * a, int n, bool inv) {

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }


    for (int len = 2; len <= n; len <<= 1) {
        int len2 = len / 2;
        double angle = 2 * PI / len * (inv ? -1 : 1);
        m_complex w = m_complex{cos(angle), sin(angle)};
        pw[0] = m_complex{1, 0};
        for (int i = 1; i < len2; ++i) {
            pw[i] = {cos(angle * i), sin(angle * i)};
//            if (i & 1) {
//                pw[i] = pw[i / 2] * pw[i / 2] * w;
//            } else {
//                pw[i] = pw[i / 2] * pw[i / 2];
//            }
        }
        for (int i = 0; i < n; i += len) {
            for (int j = 0; j < len2; ++j) {
                m_complex u = a[i + j], v = a[i + j + len2] * pw[j];
                a[i + j] = u + v;
                a[i + j + len2] = u - v;
            }
        }
    }

    if (inv) {
        for (int i = 0; i < n; ++i) {
            a[i] = a[i] / n;
        }
    }
}
m_complex A[1 << 19];
m_complex B[1 << 19];


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
    int a = nxt(), b = nxt(), k = nxt();

    int id[256];

    id['A'] = 0;
    id['C'] = 1;
    id['G'] = 2;
    id['T'] = 3;

    string s;
    string t;
    cin >> s >> t;

    int cnt[s.length() + 1][4];
    clr(cnt);

    for (int i = 0; i < (int)s.length(); ++i) {
        for (int j = 0; j < 4; ++j) {
            cnt[i + 1][j] = cnt[i][j];
        }
        cnt[i + 1][id[s[i]]]++;
    }


    int can[s.length()];

    clr(can);

    for (int i = 0; i < (int)s.length(); ++i) {
        int l = max(0, i - k), r = min((int) s.length(), i + k + 1);
        for (int j = 0; j < 4; ++j) {
            if (cnt[r][j] - cnt[l][j]) {
                can[i] |= 1 << j;
            }
        }
    }
    int ans[a];
    clr(ans);
    for (int i = 0; i < 4; ++i) {
        clr(A);
        clr(B);
        for (int j = 0; j < t.length(); ++j) {
            if (id[t[j]] == i) A[t.length() - j - 1] = {1, 0};
        }
        for (int j = 0; j < s.length(); ++j) {
            if (can[j] & (1 << i)) {
                B[j] = {1, 0};
            }
        }

//        for (int j = 0; j < t.length(); ++j) {
//            cout << A[j].x << " ";
//        }
//        cout << "\n";
//        for (int j = 0; j < s.length(); ++j) {
//            cout << B[j].x << " ";
//        }
//        cout << "\n";

        fft(A, 1 << 19, false);
        fft(B, 1 << 19, false);
        for (int j = 0; j < (1 << 19); ++j) {
            A[j] = A[j] * B[j];
        }

        fft(A, 1 << 19, true);
//        for (int j = 0; j <= s.length(); ++j) {
//            cout << A[j].x << " ";
//        }
//        cout << endl;
        for (int j = 0; j <= s.length() - t.length(); ++j) {
            ans[j] += (int)(A[j + t.length() - 1].x + 0.5);
        }
    }

//    for (int j = 0; j <= s.length() - t.length(); ++j) {
//        cout << ans[j] << " ";
//    }
//    cout << "\n";

    int res = 0;
    for (int j = 0; j <= s.length() - t.length(); ++j) {
        res += ans[j] == t.length();
    }
    cout << res << "\n";


#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}