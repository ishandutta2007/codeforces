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
        vector<int> in(n);
        for (int i=0; i<n; i++) {
            if (s[i] == 'L') in[(i+n-1)%n]++;
            else in[(i+1)%n]++;
        }
        int idx = -1;
        vector<bool> illegal(n);
        for (int i=0; i<n; i++) {
            if (in[i] == 1 && s[s[i] == 'L' ? (i+n-1)%n : (i+1)%n] != (s[i] == 'L' ? 'R' : 'L'))
                illegal[i] = true;
            else
                idx = i;
        }
//        DEBUG(illegal, idx)
        if (idx == -1) {
            cout << (n + 2) / 3 << "\n";
            continue;
        }
        rotate(in.begin(), in.begin() + idx, in.end());
        rotate(illegal.begin(), illegal.begin() + idx, illegal.end());
        int ret = 0, cur = 0;
        for (int i=0; i<n; i++) {
            if (illegal[i])
                cur++;
            else {
                ret += (cur + 2) / 3;
                cur = 0;
            }
        }
        ret += (cur + 2) / 3;
        cout << ret << "\n";
    }

    return 0;
}