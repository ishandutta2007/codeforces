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
        vector<long long> a(n);
        for (int i=0; i<n; i++)
            cin >> a[i];
        vector<vector<long long>> apps(2);
        for (int i=0; i<n; i++) {
            int b;
            cin >> b;
            apps[--b].push_back(a[i]);
        }

        sort(apps[0].rbegin(), apps[0].rend());
        sort(apps[1].rbegin(), apps[1].rend());
        long long sum = accumulate(apps[1].begin(), apps[1].end(), 0LL);
        int j = (int) apps[1].size() - 1;
        while (j >= 0 && sum - apps[1][j] >= m)
            sum -= apps[1][j--];
        int ret = sum >= m ? 2 * (j + 1) : INT_MAX;
        for (int i=0; i<(int)apps[0].size(); i++) {
            sum += apps[0][i];
            DEBUG(i, sum, j)
            while (j >= 0 && sum - apps[1][j] >= m)
                sum -= apps[1][j--];
            if (sum >= m)
                ret = min(ret, i + 1 + 2 * (j + 1));
        }
        cout << (ret == INT_MAX ? -1 : ret) << "\n";
    }

    return 0;
}