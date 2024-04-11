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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int ret = INT_MAX;
        for (int d=0; d<10; d++)
            for (int e=0; e<10; e++) {
                vector<int> cur;
                bool first = true;
                for (char c : s) {
                    if ((c - '0' == d && first) || (c - '0' == e && !first)) {
                        cur.push_back(c - '0');
                        first = !first;
                    }
                }
                if ((int) s.length() - (int) cur.size() == 4)
                    DEBUG(cur)
                if (cur.size() >= 2 && cur.back() != cur[1])
                    cur.pop_back();
                ret = min(ret, (int) s.length() - (int) cur.size());
            }
        cout << ret << "\n";
    }

    return 0;
}