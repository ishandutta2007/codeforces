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
    vector<int> cnt(200005);
    bool ok = true;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        if (++cnt[a[i]] == 3)
            ok = false;
    }
    if (!ok) {
        cout << "NO\n";
        return 0;
    }

    sort(a, a + n);
    vector<int> inc, dec;
    for (int i=0; i<n; i++) {
        if (inc.empty() || a[i] > inc.back())
            inc.push_back(a[i]);
        else
            dec.push_back(a[i]);
    }
    reverse(dec.begin(), dec.end());

    cout << "YES\n" << inc.size() << "\n";
    for (int x : inc)
        cout << x << " ";
    cout << "\n" << dec.size() << "\n";
    for (int x : dec)
        cout << x << " ";
    cout << "\n";

    return 0;
}