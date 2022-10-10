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

    int n, k;
    cin >> n >> k;

    vector<int> dist(n + 1, -1), par(n + 1);
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j=0; j<=min(u, k); j++)
            if (k - j <= n - u && u + k - 2 * j >= 0 && u + k - 2 * j <= n && dist[u+k-2*j] == -1) {
                dist[u+k-2*j] = dist[u] + 1;
                par[u+k-2*j] = j;
                q.push(u + k - 2 * j);
            }
    }
    if (dist[n] == -1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> off(n), on;
    iota(off.begin(), off.end(), 1);
    int u = n, ret = 0;
    while (u != 0) {
        int j = par[u];
        vector<int> toOff, toOn;
        cout << "?";
        for (int i=0; i<j; i++) {
            cout << " " << on.back();
            toOff.push_back(on.back());
            on.pop_back();
        }
        for (int i=0; i<k-j; i++) {
            cout << " " << off.back();
            toOn.push_back(off.back());
            off.pop_back();
        }
        cout << endl;
        int x;
        cin >> x;
        ret ^= x;
        off.insert(off.end(), toOff.begin(), toOff.end());
        on.insert(on.end(), toOn.begin(), toOn.end());
        u -= k - 2 * j;
    }
    cout << "! " << ret << endl;

    return 0;
}