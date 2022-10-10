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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> cnt(1005);
    int a;
    for (int i=0; i<n*n; i++) {
        cin >> a;
        cnt[a]++;
    }

    if (n == 1) {
        cout << "YES\n" << a << "\n";
        return 0;
    }

    vector<int> groups(1005);
    vector<vector<int>> ret(n, vector<int>(n, -1));
    int one = -1;
    vector<int> two;
    // odd: all 4's except for 2's, 1 in the middle
    // even: all 4's
    for (int i=1; i<=1000; i++) {
        if (cnt[i] % 4 == 3) {
            if (one != -1) {
                DEBUG("THREE")
                cout << "NO\n";
                return 0;
            }
            one = i;
            two.push_back(i);
        }
        if (cnt[i] % 4 == 1) {
            if (n % 2 == 0 || one != -1) {
                DEBUG("ONE")
                cout << "NO\n";
                return 0;
            }
            one = i;
        }
        groups[i] = cnt[i] / 4;
        if (cnt[i] % 4 == 2) {
            two.push_back(i);
            if (n % 2 == 0) {
                DEBUG("TWO")
                cout << "NO\n";
                return 0;
            }
        }
    }
    DEBUG("RET")
    int idx = 0;
    while (idx <= 1000 && !groups[idx]) idx++;
    for (int i=0; i<n/2; i++) {
        for (int j=0; j<n/2; j++) {
            // plant 4's
            if (idx > 1000) {
                cout << "NO\n";
                return 0;
            }
            ret[i][j] = ret[i][n-j-1] = ret[n-i-1][j] = ret[n-i-1][n-j-1] = idx;
            groups[idx]--;
            while (idx <= 1000 && !groups[idx]) idx++;
        }
    }
    DEBUG(ret)
    if (n % 2) {
        int veg = 0;
        for (int i=1; i<=1000; i++)
            groups[i] *= 2;
        for (int i=0; i<n/2; i++) {
            if (idx <= 1000) {
                ret[i][n/2] = ret[n-i-1][n/2] = idx;
                groups[idx]--;
                while (idx <= 1000 && !groups[idx]) idx++;
            } else {
                if (veg >= (int) two.size()) {
                    cout << "NO\n";
                    return 0;
                }
                ret[i][n/2] = ret[n-i-1][n/2] = two[veg++];
            }
        }
        for (int j=0; j<n/2; j++) {
            if (idx <= 1000) {
                ret[n/2][j] = ret[n/2][n-j-1] = idx;
                groups[idx]--;
                while (idx <= 1000 && !groups[idx]) idx++;
            } else {
                if (veg >= (int) two.size()) {
                    cout << "NO\n";
                    return 0;
                }
                ret[n/2][j] = ret[n/2][n-j-1] = two[veg++];
            }
        }
        ret[n/2][n/2] = one;
        assert(veg >= (int) two.size());
    }

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            assert(ret[i][j] != -1);

    cout << "YES\n";
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cout << ret[i][j] << " \n"[j==n-1];

    return 0;
}