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
        int n;
        string s;
        cin >> n >> s;

        vector<int> spots;
        for (int i=0, j=1; i<n; i=j, j++) {
            while (j < n && s[i] == s[j])
                spots.push_back(j++);
        }
        int i = 0, j = 0, ret = 0;
        vector<bool> vis(n);
        while (i < n) {
            while (j < (int) spots.size() && spots[j] < i)
                j++;
            if (j < (int) spots.size()) {
                vis[spots[j]] = true;
                while (i < n && vis[i])
                    i++;
                j++;
            } else {
                i++;
                while (i < n && vis[i])
                    i++;
            }
            ret++;
            if (i < n) {
                char c = s[i];
                while (i < n && (s[i] == c || vis[i]))
                    i++;
            }
        }
        cout << ret << "\n";
    }

    return 0;
}