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

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<vector<int>> buckets(n, vector<int>(2));
        for (int i=0; i<n; i++) {
            int c;
            cin >> c;
            c--;
            buckets[c][i >= l]++;
        }

        vector<queue<int>> q(2), p(2);
        for (int i=0; i<n; i++) {
            if ((buckets[i][0] + buckets[i][1]) % 2)
                q[buckets[i][0] > buckets[i][1]].push(i);
            else if (buckets[i][0] != buckets[i][1])
                p[buckets[i][0] > buckets[i][1]].push(i);
        }

        int ret = 0;
        while (!q[0].empty() || !q[1].empty()) {
            if (q[0].empty()) {
                assert(q[1].size() >= 2);
                int i = q[1].front();
                q[1].pop();
                int j = q[1].front();
                q[1].pop();
                if (!p[0].empty()) {
                    int k = p[0].front();
                    p[0].pop();
                    buckets[i][0]--;
                    buckets[j][0]--;
                    buckets[k][0] += 2;
                    ret++;
                    if (buckets[k][0] != buckets[k][1])
                        p[buckets[k][0] > buckets[k][1]].push(k);
                } else {
                    buckets[i][0]--;
                    buckets[j][0]++;
                }
                for (int k : {i, j})
                    if (buckets[k][0] != buckets[k][1])
                        p[buckets[k][0] > buckets[k][1]].push(k);
            } else if (q[1].empty()) {
                assert(q[0].size() >= 2);
                int i = q[0].front();
                q[0].pop();
                int j = q[0].front();
                q[0].pop();
                if (!p[1].empty()) {
                    int k = p[1].front();
                    p[1].pop();
                    buckets[i][1]--;
                    buckets[j][1]--;
                    buckets[k][1] += 2;
                    ret++;
                    if (buckets[k][0] != buckets[k][1])
                        p[buckets[k][0] > buckets[k][1]].push(k);
                } else {
                    buckets[i][1]--;
                    buckets[j][1]++;
                }
                for (int k : {i, j})
                    if (buckets[k][0] != buckets[k][1])
                        p[buckets[k][0] > buckets[k][1]].push(k);
            } else {
                int i = q[0].front();
                q[0].pop();
                int j = q[1].front();
                q[1].pop();
                buckets[i][0]++;
                buckets[j][0]--;
                for (int k : {i, j})
                    if (buckets[k][0] != buckets[k][1])
                        p[buckets[k][0] > buckets[k][1]].push(k);
            }
            ret++;
        }

        for (int i=0; i<n; i++)
            ret += abs(buckets[i][0] - buckets[i][1]) / 2;
        cout << ret << "\n";
    }

    return 0;
}