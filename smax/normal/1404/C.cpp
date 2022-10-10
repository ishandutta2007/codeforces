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

int n, bit[300005];

int query(int i) {
    int ret = 0;
    for (; i>0; i-=i&-i)
        ret += bit[i];
    return ret;
}

void update(int i, int val) {
    for (; i<=n; i+=i&-i)
        bit[i] += val;
}

int a[300005], ret[300005];
vector<pair<int, int>> queries[300005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = i - a[i];
    }
    for (int i=0; i<q; i++) {
        int x, y;
        cin >> x >> y;
        queries[n-y].emplace_back(x+1, i);
    }

    for (int i=1; i<=n; i++) {
        if (a[i] >= 0) {
            int l = 1, r = i + 1;
            while (l < r) {
                int m = (l + r) / 2;
                if (query(m) >= a[i])
                    l = m + 1;
                else
                    r = m;
            }
            if (l - 1 >= 0) {
                update(1, 1);
                update(l, -1);
            }
        }
        for (auto &p : queries[i])
            ret[p.second] = query(p.first);
    }

    for (int i=0; i<q; i++)
        cout << ret[i] << "\n";

    return 0;
}