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
    vector<int> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];

    map<int, vector<pair<int, int>>> interval;
    for (int i=0; i<n; i++) {
        int sum = 0;
        for (int j=i; j<n; j++) {
            sum += a[j];
            interval[sum].emplace_back(i, j);
        }
    }

    vector<pair<int, int>> ret;
    for (auto &[sum, all] : interval) {
        sort(all.begin(), all.end(), [] (const pair<int, int> &a, const pair<int, int> &b) {
            if (a.second == b.second)
                return a.first > b.first;
            return a.second < b.second;
        });
        vector<pair<int, int>> cur;
        int r = -1;
        for (auto &p : all)
            if (p.first > r) {
                cur.push_back(p);
                r = p.second;
            }
        if (cur.size() > ret.size())
            ret = cur;
    }

    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}