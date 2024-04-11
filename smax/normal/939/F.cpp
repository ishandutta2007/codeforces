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

#define MAXN 100001
#define INF 1000000000

template<int SZ>
struct SegmentTree {
    int n, st[2*SZ];

    void build(vector<int> &a) {
        n = a.size();
        for (int i=0; i<n; i++)
            st[i+n] = a[i];
        for (int i=n-1; i>0; i--)
            st[i] = min(st[i<<1], st[i<<1|1]);
    }

    int query(int l, int r) {
        int ret = INF;
        for (l+=n, r+=n; l<r; l>>=1, r>>=1) {
            if (l&1) ret = min(ret, st[l++]);
            if (r&1) ret = min(ret, st[--r]);
        }
        return ret;
    }
};

int l[100], r[100];
SegmentTree<MAXN> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> dp(n + 1, INF);
    for (int i=0; i<k; i++) {
        cin >> l[i] >> r[i];
        if (i == 0) {
            if (l[i] <= n)
                dp[l[i]] = 0;
        } else {
            for (int j=min(l[i], n); j>=0; j--)
                dp[j] = min({st.query(max(j + l[i-1] - l[i], 0), min(j + r[i-1] - l[i], n) + 1) + 2,
                             st.query(max(l[i] - j - r[i-1] + l[i-1], 0), min(l[i] - j, n) + 1) + 1,
                             j >= l[i] - l[i-1] ? dp[j-(l[i]-l[i-1])] : INF});
        }
        st.build(dp);
    }

    int ret = INF;
    for (int j=0; j<=min(l[k-1], n); j++) {
        if (l[k-1] <= n + j && n + j <= r[k-1])
            ret = min(ret, dp[j] + 2);
        if (l[k-1] + n - j <= r[k-1])
            ret = min(ret, dp[j] + 1);
        if (l[k-1] - j == n)
            ret = min(ret, dp[j]);
    }

    if (ret == INF)
        cout << "Hungry\n";
    else
        cout << "Full\n" << ret << "\n";

    return 0;
}