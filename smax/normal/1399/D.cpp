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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int k = 0;
        vector<int> zero, one, ret;
        for (char c : s) {
            if (c == '0') {
                if (!one.empty()) {
                    ret.push_back(one.back());
                    zero.push_back(one.back());
                    one.pop_back();
                } else {
                    k++;
                    zero.push_back(k);
                    ret.push_back(k);
                }
            } else {
                if (!zero.empty()) {
                    ret.push_back(zero.back());
                    one.push_back(zero.back());
                    zero.pop_back();
                } else {
                    k++;
                    one.push_back(k);
                    ret.push_back(k);
                }
            }
        }

        cout << k << "\n";
        for (int x : ret)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}