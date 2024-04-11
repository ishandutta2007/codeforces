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
template <typename T, typename... Args> void debug(string s, T x, Args... args) {for (int i=0, b=0; i<(int)s.size(); i++) if (s[i] == '(' || s[i] == '{') b++;
else if (s[i] == ')' || s[i] == '}') b--; else if (s[i] == ',' && b == 0) {cerr << s.substr(0, i) << " = " << x << " | "; debug(s.substr(s.find_first_not_of(' ', i + 1)), args...); break;}}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        map<char, int> mp;
        for (char c : s)
            mp[c]++;

        vector<pair<char, int>> v(mp.begin(), mp.end());
        if ((v.size() == 2 && v[0].first + 1 == v[1].first)
         || (v.size() == 3 && v[0].first + 1 == v[1].first && v[0].first + 2 == v[2].first)) {
            cout << "No answer\n";
            continue;
        }
        if (v.size() == 2) {
            cout << string(v[0].second, v[0].first) << string(v[1].second, v[1].first) << "\n";
            continue;
        }

        for (int rep=0; rep<1000; rep++) {
            random_shuffle(v.begin(), v.end());
            bool ok = true;
            for (int i=1; i<(int)v.size(); i++)
                if (v[i-1].first + 1 == v[i].first || v[i].first + 1 == v[i-1].first) {
                    ok = false;
                    break;
                }
            if (ok) {
                for (auto &p : v)
                    cout << string(p.second, p.first);
                cout << "\n";
                goto done;
            }
        }
        assert(false);
        done:;
    }

    return 0;
}