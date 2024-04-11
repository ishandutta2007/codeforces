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
        map<int, vector<int>> mp;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            mp[a].push_back(i);
        }

        int ret = 0, cur = 0;
        for (auto it=mp.begin(); it!=mp.end(); it++) {
            if (it == mp.begin() || it->second[0] > prev(it)->second.back())
                cur += it->second.size();
            else {
                auto before = prev(it);
                ret = max(ret, cur + int(it->second.end() - lower_bound(it->second.begin(), it->second.end(), before->second.back())));
                int cnt = 0;
                for (int i : before->second) {
                    cnt++;
                    ret = max(ret, cnt + int(it->second.end() - lower_bound(it->second.begin(), it->second.end(), i)));
                }
                cur = int(lower_bound(before->second.begin(), before->second.end(), it->second[0]) - before->second.begin()) + it->second.size();
            }
        }
        ret = max(ret, cur);

        cout << n - ret << "\n";
    }

    return 0;
}