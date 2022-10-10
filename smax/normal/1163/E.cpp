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
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

const int LOG = 20;

int sz = 0, basis[LOG], actual[LOG];

void add(int x) {
    int y = x;
    for (int i=0; i<LOG; i++)
        if (x & (1 << i)) {
            if (!basis[i]) {
                basis[i] = x;
                actual[i] = y;
                sz++;
                return;
            }
            x ^= basis[i];
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> s(n);
    for (int i=0; i<n; i++)
        cin >> s[i];

    sort(s.begin(), s.end());
    int x = 0;
    for (int i=0, j=0; i<LOG; i++) {
        while (j < n && s[j] < 1 << i)
            add(s[j++]);
        if (sz == i)
            x = i;
    }

    memset(basis, 0, sizeof(basis));
    memset(actual, 0, sizeof(actual));
    for (int i=0; i<n; i++)
        if (s[i] < 1 << x)
            add(s[i]);

    vector<int> grayCode{0};
    for (int i=0; i<x; i++) {
        grayCode.insert(grayCode.end(), grayCode.rbegin(), grayCode.rend());
        for (int j=1<<i; j<1<<(i+1); j++)
            grayCode[j] |= 1 << i;
    }

    cout << x << "\n0 ";
    int val = 0;
    for (int i=1; i<1<<x; i++) {
        val ^= actual[__builtin_ctz(grayCode[i-1] ^ grayCode[i])];
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}