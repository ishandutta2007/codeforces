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

int cnt[200001], c[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        int m;
        cin >> m;
        cnt[m]++;
    }
    for (int i=1; i<=k; i++)
        cin >> c[i];

    int ret = 0, tot = 0;
    for (int i=k; i>0; i--) {
        tot += cnt[i];
        ret = max(ret, (tot + c[i] - 1) / c[i]);
    }

    cout << ret << "\n";
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<int>> v(ret);
    for (int i=0; i<ret; i++)
        pq.push({0, i});

    for (int i=k; i>0; i--)
        while (cnt[i] > 0) {
            int pos = pq.top().second;
            pq.pop();

            int add = min(cnt[i], c[i] - (int) v[pos].size());
            cnt[i] -= add;
            while (add--)
                v[pos].push_back(i);
            pq.push({v[pos].size(), pos});
        }

    for (auto &vv : v) {
        cout << vv.size();
        for (int i : vv)
            cout << " " << i;
        cout << "\n";
    }

    return 0;
}