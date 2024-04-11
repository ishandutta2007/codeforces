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

    int n;
    cin >> n;
    vector<int> odd, even;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a % 2) odd.push_back(a);
        else even.push_back(a);
    }

    if (abs((int) odd.size() - (int) even.size()) <= 1)
        cout << "0\n";
    else {
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        while (!odd.empty() && !even.empty()) {
            odd.pop_back();
            even.pop_back();
        }
        int ret = 0;
        if (!odd.empty()) {
            odd.pop_back();
            for (int x : odd)
                ret += x;
        } else {
            even.pop_back();
            for (int x : even)
                ret += x;
        }
        cout << ret << "\n";
    }

    return 0;
}