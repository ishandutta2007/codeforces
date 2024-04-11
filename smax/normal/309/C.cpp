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

int cnt[30], b[30];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        for (int j=0; j<30; j++)
            if (a & (1 << j))
                cnt[j]++;
    }
    for (int i=0; i<m; i++) {
        int x;
        cin >> x;
        b[x]++;
    }

    int ret = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=0; i<30; i++) {
        while (b[i]--)
            pq.push(i);
        while (cnt[i] > 0 && !pq.empty()) {
            int tot = 0;
            while (!pq.empty() && tot + (1 << pq.top()) <= 1 << i) {
                tot += 1 << pq.top();
                pq.pop();
                ret++;
            }
            cnt[i]--;
        }
    }

    cout << ret << "\n";

    return 0;
}