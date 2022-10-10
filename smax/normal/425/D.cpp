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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator () (uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int MAX = 1e5 + 5;
const int SZ = 320;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i=0; i<n; i++)
        cin >> x[i] >> y[i];

    int ret = 0;
    vector<bool> vis(n);
    for (int rep=0; rep<2; rep++) {
        vector<vector<int>> lines(MAX);
        vector<gp_hash_table<int, null_type>> table(MAX);
        for (int i=0; i<n; i++)
            if (!vis[i]) {
                lines[x[i]].push_back(i);
                table[x[i]].insert(y[i]);
            }
        for (int i=0; i<n; i++)
            if ((int) lines[i].size() < SZ) {
                for (int j=0; j<(int)lines[i].size(); j++) {
                    for (int k=j+1; k<(int)lines[i].size(); k++) {
                        int d = abs(y[lines[i][j]] - y[lines[i][k]]);
                        if (i >= d && table[i-d].find(y[lines[i][j]]) != table[i-d].end() && table[i-d].find(y[lines[i][k]]) != table[i-d].end())
                            ret++;
                        if (i + d < MAX && table[i+d].find(y[lines[i][j]]) != table[i+d].end() && table[i+d].find(y[lines[i][k]]) != table[i+d].end())
                            ret++;
                    }
                    vis[lines[i][j]] = true;
                    table[i].erase(y[lines[i][j]]);
                }
            }
        for (int i=0; i<n; i++)
            swap(x[i], y[i]);
    }
    cout << ret << "\n";

    return 0;
}