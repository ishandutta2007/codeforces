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
template<typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i=0; i<n; i++)
        cin >> b[i];

    vector<int> deg(n);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (i != j && (a[i] & a[j]) != a[i])
                deg[i]++;

    queue<int> q;
    vector<bool> rem(n);
    for (int u=0; u<n; u++)
        if (deg[u] == n - 1) {
            q.push(u);
            rem[u] = true;
        }

    int sz = n;
    long long ret = accumulate(b.begin(), b.end(), 0LL);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        sz--;
        ret -= b[u];
        for (int v=0; v<n; v++) {
            if (u != v && (a[u] & a[v]) != a[v])
                deg[v]--;
            if (!rem[v] && deg[v] == sz - 1) {
                q.push(v);
                rem[v] = true;
            }
        }
    }
    cout << ret << "\n";

    return 0;
}