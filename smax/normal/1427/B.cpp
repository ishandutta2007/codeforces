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

int huh(int g, vector<int> gaps, int k) {
    if (g == -1) return 0;
    int change, ret = 0;
    for (int x : gaps) {
        change = min(k, x);
        k -= change;
        ret += 2 * change + (change == x);
    }
    change = min(k, g);
    ret += 2 * change;
    k -= change;
    return ret;
}

int huh2(int g, int h, vector<int> gaps, int k) {
    if (g == -1 || h == -1) return 0;
    int change = min(k, g);
    int ret = 2 * change;
    k -= change;
    change = min(k, h);
    ret += 2 * change;
    k -= change;
    for (int x : gaps) {
        change = min(k, x);
        k -= change;
        ret += 2 * change + (change == x);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int ret = 0;
        bool hasW = false;
        for (int i=0; i<n; i++) {
            ret += (s[i] == 'W') + (i > 0 && s[i] == 'W' && s[i-1] == 'W');
            hasW |= s[i] == 'W';
        }
        if (k == 0) {
            cout << ret << "\n";
            continue;
        }
        if (!hasW) {
            cout << 2 * k - 1 << "\n";
            continue;
        }
        int cur = ret, num = 0, lgap = -1, rgap = -1;
        vector<int> gaps;
        for (int i=0; i<n;) {
            if (s[i] == 'L') {
                int st = i;
                while (i < n && s[i] == 'L')
                    i++;
                if (st == 0) lgap = i - st;
                else if (i == n) rgap = i - st;
                else gaps.push_back(i - st);
            } else {
                i++;
            }
        }
        sort(gaps.begin(), gaps.end());
        int ret1 = huh(lgap, gaps, k);
        int ret2 = huh(rgap, gaps, k);
        int ret3 = huh(lgap + rgap, gaps, k);
        int ret4 = 0;
        for (int x : gaps) {
            int change = min(k, x);
            k -= change;
            ret4 += 2 * change + (change == x);
        }
        // DEBUG(ret1, ret2, ret3, ret4, ret)
        cout << max({ret1, ret2, ret3, ret4}) + ret << "\n";
    }

    return 0;
}