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

long long split(long long x, int k) {
    long long rem = x % k;
    return (x / k) * (x / k) * (k - rem) + (x / k + 1) * (x / k + 1) * rem;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    k -= n;
    long long ret = 0;
    priority_queue<tuple<long long, long long, int>> pq;
    for (int i=0; i<n; i++) {
        long long a;
        cin >> a;
        ret += a * a;
        pq.emplace(a * a - split(a, 2), a, 2);
    }

    for (int i=0; i<k; i++) {
        auto [ben, a, cuts] = pq.top();
        pq.pop();
        ret -= ben;
        pq.emplace(split(a, cuts) - split(a, cuts + 1), a, cuts + 1);
    }
    cout << ret << "\n";

    return 0;
}