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

const int SZ = 450;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> x(n), y(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    vector<vector<int>> small(SZ);
    for (int i=2; i<SZ; i++)
        small[i].resize(i);

    vector<int> big(m + 1), addTime(n);
    for (int i=1; i<=m; i++) {
        int op, k;
        cin >> op >> k;
        k--;
        big[i] += big[i-1];
        if (op == 1) {
            if (x[k] + y[k] < SZ) {
                for (int j=x[k]; j<x[k]+y[k]; j++)
                    small[x[k]+y[k]][(i+j)%(x[k]+y[k])]++;
            } else {
                for (int j=i+x[k]; j<=m; j+=x[k]+y[k]) {
                    big[j]++;
                    if (j + y[k] <= m)
                        big[j+y[k]]--;
                }
            }
            addTime[k] = i;
        } else {
            if (x[k] + y[k] < SZ) {
                for (int j=x[k]; j<x[k]+y[k]; j++)
                    small[x[k]+y[k]][(addTime[k]+j)%(x[k]+y[k])]--;
            } else {
                for (int j=addTime[k]+x[k]; j<=m; j+=x[k]+y[k]) {
                    big[j]--;
                    if (j < i)
                        big[i]--;
                    if (j + y[k] <= m) {
                        big[j+y[k]]++;
                        if (j + y[k] < i)
                            big[i]++;
                    }
                }
            }
        }
        int ret = big[i];
        for (int j=2; j<SZ; j++)
            ret += small[j][i%j];
        cout << ret << "\n";
    }

    return 0;
}