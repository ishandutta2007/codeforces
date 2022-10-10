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
template<typename T> void debug(string s, T x) {cerr << "\033[1;35m" << s << "\033[0;32m = \033[33m" << x << "\033[0m\n";}
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << "\033[1;35m" << s.substr(0, i) << "\033[0;32m = \033[33m" << x << "\033[31m | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int query(int l, int r, const vector<int> &v) {
    if (l > r) return 0;
    return v[r] - (l > 0 ? v[l-1] : 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        vector<vector<int>> b(m);
        vector<long long> tot(m);
        for (int i=0; i<m; i++) {
            int k;
            cin >> k;
            b[i].resize(k);
            for (int j=0; j<k; j++) {
                cin >> b[i][j];
                tot[i] += b[i][j];
            }
        }

        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&] (int i, int j) -> bool {
            return tot[i] * b[j].size() < tot[j] * b[i].size();
        });
        sort(a.begin(), a.end());
        a.erase(a.begin(), a.begin() + n - m);

        vector<int> up(m), down(m), same(m), pos(m);
        for (int i=0; i<m; i++) {
            up[i] = (i + 1 < m && tot[order[i]] <= a[i+1] * (long long) b[order[i]].size()) + (i > 0 ? up[i-1] : 0);
            down[i] = (i > 0 && tot[order[i]] <= a[i-1] * (long long) b[order[i]].size()) + (i > 0 ? down[i-1] : 0);
            same[i] = (tot[order[i]] <= a[i] * (long long) b[order[i]].size()) + (i > 0 ? same[i-1] : 0);
            pos[order[i]] = i;
        }

        for (int i=0; i<m; i++)
            for (int x : b[i]) {
                int l = 0, r = m;
                while (l < r) {
                    int y = (l + r) / 2;
                    if (tot[i] - x <= a[y] * (long long) (b[i].size() - 1))
                        r = y;
                    else
                        l = y + 1;
                }
                DEBUG(i, x, l, a);
                cout << (l < m && ((pos[i] <= l && query(pos[i] + 1, l, down) == l - pos[i]) || (l < pos[i] && query(l, pos[i] - 1, up) == pos[i] - l)) && query(0, min(pos[i], l) - 1, same) == min(pos[i], l) && query(max(pos[i], l) + 1, m - 1, same) == m - max(pos[i], l) - 1);
            }
        cout << "\n";
    }

    return 0;
}