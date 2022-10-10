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

const int LIM = 20;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        int mask = 0;
        set<int> st;
        queue<int> q;
        for (int i=0; i<n; i++) {
            mask = ((mask << 1) + (s[i] == '0')) & ((1 << min(k, LIM)) - 1);
            if (i >= k && s[i-k] == '0')
                q.pop();
            if (i >= k - 1 && (k <= LIM || q.empty() || i - q.front() < LIM))
                st.insert(mask);
            if (s[i] == '0')
                q.push(i);
        }

        mask = 0;
        while (st.count(mask))
            mask++;
        if (k <= LIM && mask == 1 << k) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i=0; i<k-LIM; i++)
            cout << 0;
        vector<bool> ret;
        for (int i=0; i<min(k, LIM); i++)
            ret.push_back(!!(mask & (1 << i)));
        reverse(ret.begin(), ret.end());
        for (bool x : ret)
            cout << x;
        cout << "\n";
    }

    return 0;
}