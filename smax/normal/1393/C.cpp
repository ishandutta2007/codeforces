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
        cin >> n;
        vector<int> cnt(n + 1);
        for (int i=0; i<n; i++) {
            int a;
            cin >> a;
            cnt[a]++;
        }

        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        sort(perm.begin(), perm.end(), [&] (int a, int b) {
            if (cnt[a] == cnt[b])
                return a > b;
            return cnt[a] > cnt[b];
        });

//        int ptr = 0, ret = INT_MAX;
//        vector<int> last(n + 1, -1);
//        for (int i=0; i<n; i++) {
//            if (last[perm[ptr]] != -1)
//                ret = min(ret, i - last[perm[ptr]] - 1);
//            last[perm[ptr]] = i;
//            cnt[perm[ptr++]]--;
//            if (ptr == n || cnt[perm[ptr]] == 0)
//                ptr = 0;
//        }

        // use maximal freq element as divider
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<cnt[perm[0]]-1; i++)
            pq.push(0);
        for (int i=1; i<n; i++)
            for (int j=0; j<min(cnt[perm[i]], cnt[perm[0]]-1); j++) {
                int u = pq.top();
                pq.pop();
                pq.push(u + 1);
            }

        cout << pq.top() << "\n";
    }

    return 0;
}