#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type* = nullptr>
ostream& operator << (ostream &os, const C &c) {bool f = true; os << "["; for (const auto &x : c) {if (!f) os << ", "; f = false; os << x;} return os << "]";}
template<typename T> void debug(string s, T x) {cerr << s << " = " << x << "\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {cerr << s.substr(0, s.find(',')) << " = " << x << " | "; debug(s.substr(s.find(',') + 2), args...);}

long long sum(long long a, long long b) {
    return (a + b) * (b - a + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    long long ret = 0;
    for (long long x=a; x<=b; x++) {
        // B <= y <= C
        // C <= z <= min(x + y - 1, D)

        // Case 1: x + y - 1 >= D
        // y >= D - x + 1
        // y = max(D - x + 1, B) ... C
        // Add D - C + 1
        long long low = max(d - x + 1, b), high = c;
        if (low <= high)
            ret += (high - low + 1) * (d - c + 1);

        // Case 2: x + y - 1 < D
        // y < D - x + 1
        // y <= D - x
        // y = B ... min(D - x, C)
        // Sum x + y - C
        // x + y - C >= 0
        // y >= C - x
        low = max(b, c - x), high = min(c, d - x);
        if (low <= high)
            ret += (high - low + 1) * (x - c) + sum(low, high);
    }
    cout << ret << "\n";

    return 0;
}