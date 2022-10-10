#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

const int INF = 1e9;
string digits[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

string s[2000];
bool dp[2001][2001];

int check(int i, int d) {
    int ret = 0;
    for (int j=0; j<7; j++) {
        if (s[i][j] == '1' && digits[d][j] == '0')
            return INF;
        if (s[i][j] == '0' && digits[d][j] == '1')
            ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++)
        cin >> s[i];

    dp[n][k] = true;
    for (int i=n-1; i>=0; i--)
        for (int d=0; d<10; d++) {
            int need = check(i, d);
            for (int j=need; j<=k; j++)
                dp[i][j-need] |= dp[i+1][j];
        }

    if (!dp[0][0]) {
        cout << "-1\n";
        return 0;
    }

    int j = 0;
    for (int i=0; i<n; i++)
        for (int d=9; d>=0; d--) {
            int need = check(i, d);
            if (j + need <= k && dp[i+1][j+need]) {
                cout << d;
                j += need;
                break;
            }
        }
    cout << "\n";

    return 0;
}