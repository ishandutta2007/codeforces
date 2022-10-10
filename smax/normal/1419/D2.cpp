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

    sort(a, a + n);
    vector<int> ret(n);
    int j = 0;
    for (int i=1; i<n; i+=2)
        ret[i] = a[j++];
    for (int i=0; i<n; i+=2)
        ret[i] = a[j++];

    int ans = 0;
    for (int i=1; i<n-1; i++)
        ans += (ret[i] < ret[i-1] && ret[i] < ret[i+1]);
    cout << ans << "\n";
    for (int x : ret)
        cout << x << " ";
    cout << "\n";

    return 0;
}