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
        vector<bool> vis(26);
        string s;
        cin >> s;
        vector<vector<int>> v(26, vector<int>(2));
        char pred = s[0];
        vis[pred-'a'] = true;
        bool possible = true;
        for (int i=1; i<(int)s.size(); i++) {
            char cur = s[i];
            vis[cur-'a'] = true;
            if (v[pred-'a'][0] == cur - 'a' + 1 || v[pred-'a'][1] == cur - 'a' + 1) {
                pred = cur;
                continue;
            }
            if (v[pred-'a'][0] == 0) {
                if (v[cur-'a'][0] != 0) {
                    possible = false;
                    break;
                }
                v[pred-'a'][0] = cur - 'a' + 1;
                v[cur-'a'][1] = pred - 'a' + 1;
            } else if (v[pred-'a'][1] == 0) {
                if (v[cur-'a'][1] != 0) {
                    possible = false;
                    break;
                }
                v[pred-'a'][1] = cur - 'a' + 1;
                v[cur-'a'][0] = pred - 'a' + 1;
            } else {
                possible = false;
                break;
            }
            pred = cur;
        }

        if (!possible) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int leftMost = -1;
        for (int i=0; i<26; i++)
            if (vis[i]) {
                if (v[i][0] == 0) {
                    leftMost = i;
                    break;
                }
            }
        assert(leftMost != -1);

        string ret = "";
        int cur = leftMost;
        while (v[cur][1] != 0) {
            ret += char(cur + 'a');
            cur = v[cur][1] - 1;
        }
        ret += char(cur + 'a');
        for (int i=0; i<26; i++)
            if (!vis[i])
                ret += char(i + 'a');
        cout << ret << "\n";
    }

    return 0;
}