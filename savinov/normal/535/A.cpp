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

random_device device;
mt19937 generator(device());

unsigned int nextRandom() {
    return generator();
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


long long pw(long long a, long long n, long long mod) {
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

    map <int, string> X;

    X[0] = "zero";
    X[1] = "one";
    X[2] = "two";
    X[3] = "three";
    X[4] = "four";
    X[5] = "five";
    X[6] = "six";
    X[7] = "seven";
    X[8] = "eight";
    X[9] = "nine";
    X[10] = "ten";
    X[11] = "eleven";
    X[12] = "twelve";
    X[13] = "thirteen";
    X[14] = "fourteen";
    X[15] = "fifteen";
    X[16] = "sixteen";
    X[17] = "seventeen";
    X[18] = "eighteen";
    X[19] = "nineteen";
    X[20] = "twenty";
    X[21] = "twenty-one";
    X[22] = "twenty-two";
    X[23] = "twenty-three";
    X[24] = "twenty-four";
    X[25] = "twenty-five";
    X[26] = "twenty-six";
    X[27] = "twenty-seven";
    X[28] = "twenty-eight";
    X[29] = "twenty-nine";
    X[30] = "thirty";
    X[31] = "thirty-one";
    X[32] = "thirty-two";
    X[33] = "thirty-three";
    X[34] = "thirty-four";
    X[35] = "thirty-five";
    X[36] = "thirty-six";
    X[37] = "thirty-seven";
    X[38] = "thirty-eight";
    X[39] = "thirty-nine";
    X[40] = "forty";
    X[41] = "forty-one";
    X[42] = "forty-two";
    X[43] = "forty-three";
    X[44] = "forty-four";
    X[45] = "forty-five";
    X[46] = "forty-six";
    X[47] = "forty-seven";
    X[48] = "forty-eight";
    X[49] = "forty-nine";
    X[50] = "fifty";
    X[51] = "fifty-one";
    X[52] = "fifty-two";
    X[53] = "fifty-three";
    X[54] = "fifty-four";
    X[55] = "fifty-five";
    X[56] = "fifty-six";
    X[57] = "fifty-seven";
    X[58] = "fifty-eight";
    X[59] = "fifty-nine";
    X[60] = "sixty";
    X[61] = "sixty-one";
    X[62] = "sixty-two";
    X[63] = "sixty-three";
    X[64] = "sixty-four";
    X[65] = "sixty-five";
    X[66] = "sixty-six";
    X[67] = "sixty-seven";
    X[68] = "sixty-eight";
    X[69] = "sixty-nine";
    X[70] = "seventy";
    X[71] = "seventy-one";
    X[72] = "seventy-two";
    X[73] = "seventy-three";
    X[74] = "seventy-four";
    X[75] = "seventy-five";
    X[76] = "seventy-six";
    X[77] = "seventy-seven";
    X[78] = "seventy-eight";
    X[79] = "seventy-nine";
    X[80] = "eighty";
    X[81] = "eighty-one";
    X[82] = "eighty-two";
    X[83] = "eighty-three";
    X[84] = "eighty-four";
    X[85] = "eighty-five";
    X[86] = "eighty-six";
    X[87] = "eighty-seven";
    X[88] = "eighty-eight";
    X[89] = "eighty-nine";
    X[90] = "ninety";
    X[91] = "ninety-one";
    X[92] = "ninety-two";
    X[93] = "ninety-three";
    X[94] = "ninety-four";
    X[95] = "ninety-five";
    X[96] = "ninety-six";
    X[97] = "ninety-seven";
    X[98] = "ninety-eight";
    X[99] = "ninety-nine";


    int x;
    cin >> x;
    cout << X[x] << "\n";

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}