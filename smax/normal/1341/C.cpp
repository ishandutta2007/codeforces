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

int p[100000], pos[100000];
bool visited[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> p[i];
            pos[--p[i]] = i;
        }

        memset(visited, false, sizeof(bool) * n);
        bool ok = true;
        for (int i=0; i<n; i++)
            if (!visited[pos[i]]) {
                int ptr = pos[i];
                visited[ptr] = true;
                while (ptr < n - 1 && !visited[ptr + 1]) {
                    if (p[ptr + 1] != p[ptr] + 1) {
                        ok = false;
                        break;
                    }
                    visited[++ptr] = true;
                }
                if (!ok)
                    break;
            }

        cout << (ok ? "Yes" : "No") << "\n";
    }

    return 0;
}