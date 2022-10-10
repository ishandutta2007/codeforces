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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> ret;
    // step 1: break up into powers of 2
    vector<int> power;
    int cur = n, two = 1;
    while (cur > 0) {
        if (cur % 2) power.push_back(two);
        for (int i=0; i+2*two<=n; i+=2*two)
            for (int j=i; j<i+two; j++)
                ret.emplace_back(j, j + two);
        cur /= 2;
        two *= 2;
    }

    // step 2: merge powers of 2
    reverse(power.begin(), power.end());
    int head = 0;
    while (power.size() > 2) {
        // slam last into first
        for (int i=0; i<power.back(); i++) {
            if (i < head) ret.emplace_back(head + i, i);
            else ret.emplace_back(head + i, n - (i - head) - 1);
        }
        head += power.back();
        power[0] -= power.back();
        power.back() *= 2;
        while (power.size() > 2 && power.back() == power[(int) power.size() - 2]) {
            for (int i=0; i<power.back(); i++) {
                if (i < head) ret.emplace_back(i, n - i - (power.back() - head) - 1);
                else ret.emplace_back(n - (i - head) - 1, n - i - (power.back() - head) - 1);
            }
            power.pop_back();
            power.back() *= 2;
        }
    }

    assert(ret.size() <= 500000);
    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}