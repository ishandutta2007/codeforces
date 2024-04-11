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

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> k(n), c(m);
        for (int i=0; i<n; i++) {
            cin >> k[i];
            k[i]--;
        }
        for (int j=0; j<m; j++)
            cin >> c[j];

        // initially give everyone money
        long long ret = 0;
        sort(k.begin(), k.end());
        for (int i=0; i<n; i++)
            ret += c[k[i]];

        // add in presents one by one
        priority_queue<pair<int, int>> pq;
        for (int i=n-1, j=m-1; j>=0; j--) {
            while (i >= 0 && k[i] >= j) {
                pq.emplace(c[k[i]], i);
                i--;
            }
            DEBUG(i, j, c[j], pq.empty() ? make_pair(0, 0) : pq.top())
            if (!pq.empty() && c[j] < pq.top().first) {
                auto [val, idx] = pq.top();
                pq.pop();
                DEBUG(c[j], val)
                ret += c[j] - val;
                pq.emplace(c[j], idx);
            }
        }
        cout << ret << "\n";
    }

    return 0;
}