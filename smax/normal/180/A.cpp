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

int ni[200];
pair<int, int> loc[201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        loc[i] = {-1, -1};
    for (int i=0; i<m; i++) {
        cin >> ni[i];
        for (int j=0; j<ni[i]; j++) {
            int a;
            cin >> a;
            loc[a] = {i, j};
        }
    }

    vector<pair<int, int>> ret;
    for (int i=0, j=0, pos=1; i<m;) {
        if (loc[pos] > make_pair(i, j)) {
            int k = pos;
            while (loc[k].first != -1 && loc[k] >= make_pair(i, j)) k++;
            ret.emplace_back(pos, k);
            loc[k] = loc[pos];
        }
        if (loc[pos] != make_pair(i, j)) {
            int k = pos;
            while (loc[k] != make_pair(i, j)) k++;
            ret.emplace_back(k, pos);
            loc[pos] = loc[k];
        }
        if (++j == ni[i]) {
            i++;
            j = 0;
        }
        pos++;
    }

    cout << ret.size() << "\n";
    for (auto p : ret)
        cout << p.first << " " << p.second << "\n";

    return 0;
}