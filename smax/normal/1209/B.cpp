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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        pq.emplace(b[i], i);
    }

    int cur = (int) count(s.begin(), s.end(), '1');

    auto update = [&] (int i) -> void {
        if (s[i] == '1') {
            s[i] = '0';
            cur--;
        } else {
            s[i] = '1';
            cur++;
        }
    };

    int ret = cur;
    for (int rep=0; rep<10000; rep++) {
        auto [t, i] = pq.top();
        pq.pop();
        update(i);
        pq.emplace(t + a[i], i);
        while (!pq.empty() && pq.top().first == t) {
            int j = pq.top().second;
            pq.pop();
            update(j);
            pq.emplace(t + a[j], j);
        }
        ret = max(ret, cur);
    }
    cout << ret << "\n";

    return 0;
}