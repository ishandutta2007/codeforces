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

int a[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> a[i];

    vector<int> ones;
    for (int i=n-1; i>=0; i--)
        if (a[i] == 1)
            ones.push_back(i);

    int row = 0;
    vector<int> col(n, -1);
    vector<pair<int, int>> ret;
    for (int i=0, j=0; i<n; i++) {
        j = max(j, i + 1);
        while (j < n && (a[j] == 0 || col[j] != -1))
            j++;
        while (!ones.empty() && col[ones.back()] != -1)
            ones.pop_back();
        if (a[i] == 1) {
            if (col[i] == -1) {
                if (row >= n) {
                    cout << "-1\n";
                    return 0;
                }
                ret.emplace_back(row++, i);
            }
            if (ones.back() == i)
                ones.pop_back();
        } else if (a[i] == 2) {
            if (ones.empty()) {
                cout << "-1\n";
                return 0;
            }
            if (col[i] == -1) {
                if (row >= n) {
                    cout << "-1\n";
                    return 0;
                }
                ret.emplace_back(row, i);
                ret.emplace_back(row, ones.back());
                col[ones.back()] = row;
                ones.pop_back();
                row++;
            } else {
                ret.emplace_back(col[i], ones.back());
                col[ones.back()] = col[i];
                ones.pop_back();
            }
        } else if (a[i] == 3) {
            if (j >= n) {
                cout << "-1\n";
                return 0;
            }
            if (col[i] == -1) {
                if (row >= n - 1) {
                    cout << "-1\n";
                    return 0;
                }
                ret.emplace_back(row, i);
                ret.emplace_back(row, j);
                ret.emplace_back(row + 1, j);
                col[j] = row + 1;
                row += 2;
            } else {
                if (row >= n) {
                    cout << "-1\n";
                    return 0;
                }
                ret.emplace_back(col[i], j);
                ret.emplace_back(row, j);
                col[j] = row;
                row++;
            }
        }
    }
    cout << ret.size() << "\n";
    for (auto &p : ret)
        cout << p.first + 1 << " " << p.second + 1 << "\n";

    return 0;
}