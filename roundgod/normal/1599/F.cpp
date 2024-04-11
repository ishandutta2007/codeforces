#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;

int value[maxn];
int pre[4][maxn];

int two(int x) {
    return 1ll * x * x % mod;
}

int three(int x) {
    return 1ll * x * x % mod * x % mod;
}

int n, m;

void add(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

int bel[maxn];

struct node {
    int l, r, d, id;
    bool operator <(const node &rhs) const{
        return bel[l] ^ bel[rhs.l] ? l < rhs.l : (bel[l] & 1 ? r < rhs.r : r > rhs.r);
    }
}q[maxn];

int id[maxn];
int cnt[maxn];
int res[maxn];
bool vis[maxn];
const int N = 400;

int power(int q, int w) {
    int ret = 1;
    while(w) {
        if(w & 1) ret = 1ll * ret * q % mod;
        q = 1ll * q * q % mod;
        w >>= 1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<int> lst;
    lst.emplace_back(-1e9);
    for (int i = 1; i <= n; i += 1){
        bel[i] = i / N + 1;
        cin >> value[i];
        lst.emplace_back(value[i]);
        for (int j = 1; j <= 3; j += 1) {
            pre[j][i] = pre[j][i - 1];
        }
        add(pre[1][i], value[i]);
        add(pre[2][i], two(value[i]));
        add(pre[3][i], three(value[i]));
    }
    sort(lst.begin(), lst.end());
    lst.erase(unique(lst.begin(), lst.end()), lst.end());
    for (int i = 1; i <= n; i += 1){
        id[i] = lower_bound(lst.begin(), lst.end(), value[i]) - lst.begin();
    }
    
    for (int i = 1; i <= m; i += 1){
        cin >> q[i].l >> q[i].r >> q[i].d;
        q[i].id = i;
        res[i] = 1;
    }
    sort(q + 1, q + m + 1);
    int l = 1, r = 0;
    int geq = 0;
    int last = 0;
    int inv6 = power(6, mod - 2);
    for (int i = 1; i <= m; i += 1){
        while(r < q[i].r) {
            r += 1;
            last = r;
            cnt[id[r]] += 1;
            if(cnt[id[r]] == 1) vis[id[r]] = 1;
            if(cnt[id[r]] == 2) geq += 1;
        }
        while(l > q[i].l) {
            l -= 1;
            last = l;
            cnt[id[l]] += 1;
            if(cnt[id[l]] == 2) geq += 1;
            if(cnt[id[l]] == 1) vis[id[l]] = 1;
        }
        while(r > q[i].r) {
            cnt[id[r]] -= 1;
            if(cnt[id[r]] == 1) geq -= 1;
            if(cnt[id[r]] == 0) vis[id[r]] = 0;
            r -= 1;
        }
        while(l < q[i].l) {
            cnt[id[l]] -= 1;
            if(cnt[id[l]] == 1) geq -= 1;
            if(cnt[id[l]] == 0) vis[id[l]] = 0;
            l += 1;
        }
        res[q[i].id] &= geq == 0;
        int lo = 0, hi = r - l, ans = 0;
        while(hi >= lo) {
            int mid = lo + hi >> 1;
            int cur = (value[l] - 1ll * mid * q[i].d % mod + mod) % mod;
            if(!binary_search(lst.begin(), lst.end(), cur) || 
            !vis[lower_bound(lst.begin(), lst.end(), cur) - lst.begin()]) hi = mid - 1;
            else {
                lo = mid + 1;
                ans = mid;
            }
        }
        int mn = (value[l] - 1ll * ans * q[i].d % mod + mod) % mod;
        lo = 0, hi = r - l, ans = 0;
        while(hi >= lo) {
            int mid = lo + hi >> 1;
            
            int cur = (value[l] + 1ll * mid * q[i].d) % mod;
            if(!binary_search(lst.begin(), lst.end(), cur) || 
            !vis[lower_bound(lst.begin(), lst.end(), cur) - lst.begin()]) hi = mid - 1;
            else {
                lo = mid + 1;
                ans = mid;
            }
        }
        int mx = (value[l] + 1ll * ans * q[i].d) % mod;
        //cerr << "test: " << mn << " " << mx << endl;
        if((mx - mn + mod) % mod != 1ll * q[i].d * (r - l) % mod) {
            res[q[i].id] = 0;
        }
        else{
            int len = r - l + 1;
            res[q[i].id] &= (1ll * (r - l + 1) * mn + 
                            1ll * q[i].d * (1ll * (r - l) * (r - l + 1) / 2 % mod)) % mod
                            == (pre[1][r] - pre[1][l - 1] + mod) % mod;
            int go = 1ll * (len - 1) * len % mod * (2 * len - 1) % mod * inv6 % mod;
            res[q[i].id] &= (1ll * two(mn) * len + 1ll * two(q[i].d) * go + 
                            1ll * mn * q[i].d % mod * (1ll * (r - l) * (r - l + 1) % mod)) % mod
                            == (pre[2][r] - pre[2][l - 1] + mod) % mod;
        }
        res[q[i].id] |= geq == 1 && cnt[id[last]] == r - l + 1 && q[i].d == 0;
    }
    for (int i = 1; i <= m; i += 1){
        cout << (res[i] ? "Yes" : "No") << "\n";
    }
    return 0;
}