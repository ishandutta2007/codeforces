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

const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> pos(n + 1);
        set<pair<int, int>> st;
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            pos[a] = i;
            st.emplace(i, a);
        }

        vector<int> b(n);
        vector<bool> ban(n + 1);
        for (int i=0; i<k; i++) {
            cin >> b[i];
            ban[b[i]] = true;
        }

        long long ret = 1;
        for (int i=0; i<k; i++) {
            auto it = st.find({pos[b[i]], b[i]});
            int cnt = 0;
            DEBUG(*it)
            if (it != st.begin() && !ban[prev(it)->second])
                cnt++;
            if (next(it) != st.end() && !ban[next(it)->second])
                cnt++;
            if (cnt == 0)
                ret = 0;
            else if (cnt == 2)
                ret = ret * 2 % MOD;
            DEBUG(b[i], cnt, st)
            ban[b[i]] = false;
            st.erase({pos[b[i]], b[i]});
        }
        cout << ret << "\n";
    }

    return 0;
}