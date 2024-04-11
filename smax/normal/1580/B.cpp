#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__)
#else
#define DEBUG(...) 6
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

// https://github.com/kth-competitive-programming/kactl/blob/main/content/various/FastMod.h
typedef unsigned long long ull;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(-1ULL / b) {}
	ull reduce(ull a) { // a % b + (0 or b)
		return a - (ull)((__uint128_t(m) * a) >> 64) * b;
	}
};

const int MAXN = 105;

int choose[MAXN][MAXN], dp[MAXN][MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, p;
    cin >> n >> m >> k >> p;

    if (p == 1) {
        cout << "0\n";
        return 0;
    }

    FastMod mod(p);

    auto add = [&] (int a, int b) -> int {
        return a + b >= p ? a + b - p : a + b;
    };

    auto mul = [&] (int a, int b) -> int {
        return (int) mod.reduce((ull) a * b);
    };

    for (int i=0; i<=n; i++)
        choose[i][0] = 1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            choose[i][j] = add(choose[i-1][j], choose[i-1][j-1]);

    dp[0][0][0] = 1;
    for (int i=1; i<=n; i++) {
        dp[i][0][0] = mul(dp[i-1][0][0], i);
        dp[0][i][0] = 1;
    }
    int fact = 1;
    for (int len=1; len<=n; len++) {
        fact = mul(fact, len);
        for (int cntMax=1; cntMax<=len && cntMax<=m; cntMax++)
            for (int good=0; good<=len && good<=k; good++)
                for (int pos=1; pos<=len; pos++)
                    for (int goodL=0; goodL<pos && goodL+(cntMax==1)<=good; goodL++)
                        dp[len][cntMax][good] = add(dp[len][cntMax][good], mul(choose[len-1][pos-1], mul(dp[pos-1][cntMax-1][goodL], dp[len-pos][cntMax-1][good-goodL-(cntMax==1)])));
        for (int cntMax=len+1; cntMax<=m; cntMax++)
            dp[len][cntMax][0] = fact;
    }
    cout << dp[n][m][k] << "\n";

    return 0;
}