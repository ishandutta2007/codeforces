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

int a[100005], b[100005];
long long suff[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> v;
        for (int i=0; i<m; i++) {
            cin >> a[i] >> b[i];
            v.push_back(a[i]);
        }

        sort(v.begin(), v.end());
        suff[m] = 0;
        for (int i=m-1; i>=0; i--)
            suff[i] = suff[i+1] + v[i];
        long long ret = 0;
        for (int i=0; i<m; i++) {
            long long cur;
            int pos = lower_bound(v.begin(), v.end(), b[i]) - v.begin();
            if (a[i] >= b[i]) {
                if (m - pos <= n)
                    cur = suff[pos] + (long long) (n - (m - pos)) * b[i];
                else
                    cur = suff[m-n];
            } else {
                if (m - pos + 1 <= n)
                    cur = suff[pos] + a[i] + (long long) (n - (m - pos + 1)) * b[i];
                else
                    cur = suff[m-n];
            }
            DEBUG(i, pos, a[i], b[i], cur)
            ret = max(ret, cur);
        }

        cout << ret << "\n";
    }

    return 0;
}