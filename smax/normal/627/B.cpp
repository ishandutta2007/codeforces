#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) cerr << #__VA_ARGS__ << ": ", debug(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

template<typename T, typename S> ostream& operator << (ostream &os, const pair<T, S> &p) {return os << "(" << p.first << ", " << p.second << ")";}
template<typename T> ostream& operator << (ostream &os, const vector<T> &v) {os << "["; for (int i=0; i<(int)v.size(); i++) {if (i) os << ", "; os << v[i];} return os << "]";}
void debug() {cerr << "\n";} template<typename T, typename... Args> void debug(T x, Args... args) {cerr << x << "; "; debug(args...);}

int n, bit[2][200001] = {};

int query(int t, int x) {
    int ret = 0;
    for (int i=x; i>0; i-=i&-i)
        ret += bit[t][i];
    return ret;
}

void update(int t, int x, int val) {
    for (int i=x; i<=n; i+=i&-i)
        bit[t][i] += val;
}

int orders[200001] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k, a, b, q;
    cin >> n >> k >> a >> b >> q;
    while (q--) {
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            int x;
            cin >> x;
            update(0, p, -min(orders[p], a));
            update(1, p, -min(orders[p], b));
            orders[p] += x;
            update(0, p, min(orders[p], a));
            update(1, p, min(orders[p], b));
        } else
            cout << query(1, p-1) + query(0, n) - query(0, p+k-1) << "\n";
    }

    return 0;
}