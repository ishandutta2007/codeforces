#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int N = 10000 + 10;
int p[N];
int find(int x) {
    return p[x]==x?x:p[x]=find(p[x]);
}
void unite(int x, int y) {
    p[find(x)] = find(y);
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < N; i ++) p[i] = i;
    for (int i = 0; i < n; i ++)
        cin >> x[i] >> y[i];

    vector<vector<int> > d(n, vector<int>(n, 0));
    for (int i = 0; i < n; i ++)
    for (int j = 0; j < n; j ++)
        d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    
    auto id = [&](int x, int y) {
        if (x > y) swap(x, y);
        return x * n + y;
    };
    vector<int> invalid(n*n, 0);
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            bool foul = 0;
            vector<int> idx;
            for (int x = 0; x < n; x ++) if (x != i and x != j) {
                if (d[i][x] < d[i][j] or d[j][x] < d[i][j]) {
                    invalid[id(i,j)] = true;
                }
                if (d[i][x] == d[i][j]) {
                    //printf("unite %d %d, %d %d\n",i,x,i,j);
                    unite(id(i,x), id(i,j));
                }
                if (d[j][x] == d[i][j]) {
                    //printf("unite %d %d, %d %d\n",j,x,i,j);
                    unite(id(j,x), id(i,j));
                }
            }
        }
    }
    vector<vector<int> > vec(n * n, vector<int>(0));
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int x = id(i, j);
            vec[find(x)].emplace_back(x);
            if (invalid[x]) invalid[find(x)] = 1;
        }
    }

    vector<int> res;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int x = id(i, j);
            if (find(x) == x and invalid[x] == false) {
                set<int> st;
                for (auto p: vec[x]) {
                    int x = p / n;
                    int y = p % n;
                    st.insert(x);
                    st.insert(y);
                    //cout << x << " " << y << "\n";
                }
                int sz = int(st.size());

                //printf("sz = %d, vec = %d\n", sz, vec[x].size());
                if (sz * (sz - 1) / 2 == vec[x].size()) {
                    res.emplace_back(sz);
                    //cout << "sz = " << sz << "\n";
                }
            } 
        }      
    }

    int tot = accumulate(res.begin(), res.end(), 0);
    vector<int> dp(tot + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < res.size(); i ++) {
        vector<int> nex(tot + 1, 0);
        for (int j = 0; j <= tot; j ++) {
            if (j + 1 <= tot) (nex[j+1] += dp[j]) %= mod;
            if (j + res[i] <= tot) (nex[j+res[i]] += dp[j]) %= mod;
        }
        swap(nex, dp);
    }
    ll ans = 0;
    int rem = n - tot;
    vector<ll> fac(102);
    fac[0] = 1;
    for (int i = 1; i <= 100; i ++) fac[i] = fac[i-1] * i % mod;
    for (int i = 0; i <= tot; i ++) {
        ll tmp = 1;
        for (int j = n; j >= n - (i+rem) + 1; j --) tmp = tmp * j % mod;
        ans += 1ll * dp[i] * tmp % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}