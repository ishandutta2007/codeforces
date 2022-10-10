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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++; else
if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> bucket(2);
        for (int i=0; i<3; i++) {
            string s;
            cin >> s;
            int cnt = 0;
            for (char c : s)
                cnt += c - '0';
            bucket[cnt >= n].push_back(s);
        }
        if (bucket[0].size() >= 2) {
            vector<string> part(n + 1);
            for (int i=0; i<2; i++) {
                int idx = 0;
                for (char c : bucket[0][i]) {
                    if (c == '0' && idx < n)
                        idx++;
                    else
                        part[idx] += c;
                }
            }
            for (int i=0; i<n; i++)
                cout << part[i] << '0';
            cout << part[n] << "\n";
        } else {
            assert(bucket[1].size() >= 2);
            vector<string> part(n + 1);
            for (int i=0; i<2; i++) {
                int idx = 0;
                for (char c : bucket[1][i]) {
                    if (c == '1' && idx < n)
                        idx++;
                    else
                        part[idx] += c;
                }
            }
            for (int i=0; i<n; i++)
                cout << part[i] << '1';
            cout << part[n] << "\n";
        }
    }

    return 0;
}