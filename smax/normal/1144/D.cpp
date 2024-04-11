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

int a[200000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int mx = 0, mxA = -1;
    vector<int> cnt(200005);
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (++cnt[a[i]] > mx) {
            mx = cnt[a[i]];
            mxA = a[i];
        }
    }

    cout << n - mx << "\n";
    vector<array<int, 3>> v;
    int j = 0;
    for (int i=0; i<n; i++) {
        if (a[i] == mxA) {
            while (j < i) {
                v.push_back({a[j] < mxA ? 1 : 2, j + 1, j + 2});
                j++;
            }
            j++;
        }
    }
    for (int k=n-1; k>=j; k--)
        v.push_back({a[k] < mxA ? 1 : 2, k + 1, k});

    reverse(v.begin(), v.end());
    for (auto &p : v)
        cout << p[0] << " " << p[1] << " " << p[2] << "\n";

    return 0;
}