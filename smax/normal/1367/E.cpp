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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> cnt(26);
        for (char c : s)
            cnt[c-'a']++;
        sort(cnt.rbegin(), cnt.rend());

        for (int len=n; len>0; len--) {
            vector<int> cycle;
            vector<bool> visited(len);
            for (int i=0; i<len; i++) {
                if (visited[i])
                    continue;
                int need = 0, p = i;
                while (!visited[p]) {
                    need++;
                    visited[p] = true;
                    p = (p + k) % len;
                }
                cycle.push_back(need);
            }

            bool ok = true;
            priority_queue<int> pq;
            for (int i : cnt)
                pq.push(i);
            for (int i : cycle) {
                int x = pq.top();
                pq.pop();
                if (x >= i) {
                    x -= i;
                } else {
                    ok = false;
                    break;
                }
                pq.push(x);
            }
            if (ok) {
                cout << len << "\n";
                break;
            }
        }
    }

    return 0;
}