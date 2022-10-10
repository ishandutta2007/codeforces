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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;

        vector<int> cnt(n), fCnt(n);
        for (int i=0; i<n; i++) {
            int a, f;
            cin >> a >> f;
            a--;

            cnt[a]++;
            if (f) fCnt[a]++;
        }

        vector<vector<int>> level(n + 1);
        for (int i=0; i<n; i++)
            level[cnt[i]].push_back(fCnt[i]);

        int ret = 0, f = 0;
        priority_queue<int> pq;
        for (int i=n; i>0; i--) {
            for (int x : level[i])
                pq.push(x);
            if (!pq.empty()) {
                int x = pq.top();
                pq.pop();
                ret += i;
                f += min(i, x);
            }
        }

        cout << ret << " " << f << "\n";
    }

    return 0;
}