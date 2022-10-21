#include<bits/stdc++.h>
using namespace std;

#define pli pair<long long, int>
#define N 200010

int n, m, a[N], b[N], q;
long long SUM;
multiset<int> A, B;

pli operator + (const pli a, const pli b) {
    return pli(a.first + b.first, a.second + b.second);
}

inline int MIN(multiset<int> &x) {
    return *x.begin();
}

inline int MAX(multiset<int> &x) {
    return *x.rbegin();
}

struct segtree {
    int vol;
    vector<int> member, pos, num;
    vector<long long> sum;
    segtree (int vol) : vol(vol) {
        member.resize(vol + 1);
        num.resize(vol << 2);
        sum.resize(vol << 2);
        pos.resize(vol + 1);
        for(int i = 1; i <= m; i ++) member[b[i] + 1] ++;
        build();
    }
    void push_up(int k) {
        sum[k] = sum[k << 1] + sum[k << 1 ^ 1];
        num[k] = num[k << 1] + num[k << 1 ^ 1];
        return;
    }
    void build() {build(1, vol, 1);}
    void build(int l, int r, int k) {
        if(l == r) {
            pos[l] = k;
            sum[k] = 1ll * member[l] * (l - 1);
            num[k] = member[l];
            return;
        }
        int m = l + r >> 1;
        build(l, m, k << 1);
        build(m + 1, r, k << 1 ^ 1);
        push_up(k);
        return;
    }
    void update(int l, int d) {
        int k = pos[l];
        member[l] += d;
        num[k] += d;
        sum[k] += 1ll * d * (l - 1);
        while(k > 1) {
            k >>= 1;
            push_up(k);
        }
        return;
    }
    pli query(int l, int r, int k, int L, int R) {
        if(L <= l && r <= R) return pli(sum[k], num[k]);
        if(R < l || r < L) return pli(0, 0);
        int m = l + r >> 1;
        return query(l, m, k << 1, L, R) + query(m + 1, r, k << 1 ^ 1, L, R);
    }
    long long query(int x) {
        pli ans = query(1, vol, 1, 1, x + 1);
        return ans.first + 1ll * (m - ans.second) * x;
    }
    long long max_score(int x) {
        long long ans = -1ll << 50;
        int Min = min(MIN(A), MIN(B));
        ans = max(ans, query(MIN(B) - x) - 1ll * n * min(Min, MIN(B) - x));
        ans = max(ans, query(MAX(B) - x) - 1ll * n * min(Min, MAX(B) - x));
        ans = max(ans, query(MIN(A) - x) - (MIN(A) - x) - 1ll * (n - 1) * min(Min, MIN(A) - x));
        auto it = A.lower_bound(MAX(B) + x);
        if(it != A.end()) ans = max(ans, query(*it - x) - (*it - x) - 1ll * (n - 1) * min(Min, *it - x));
        if(it != A.begin()) {
            it --;
            ans = max(ans, query(*it - x) - (*it - x) - 1ll * (n - 1) * min(Min, *it - x));
        }
//        cerr << ans << ' ';
        return SUM + ans;
    }
    void solve() {
        while(q --) {
            int type, pos, x;
            scanf("%d", &type);
            if(type == 3) {
                scanf("%d", &x);
                printf("%lld\n", max_score(x));
            }
            else {
                scanf("%d%d", &pos, &x);
                if(type == 1) {
                    A.erase(A.find(a[pos]));
                    SUM += x - a[pos];
                    a[pos] = x;
                    A.insert(a[pos]);
                }
                else {
                    B.erase(B.find(b[pos]));
                    SUM -= x - b[pos];
                    update(b[pos] + 1, -1);
                    b[pos] = x;
                    B.insert(b[pos]);
                    update(x + 1, 1);
                }
            }
        }
    }
};

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]), SUM += a[i], A.insert(a[i]);
    for(int i = 1; i <= m; i ++) scanf("%d", &b[i]), SUM -= b[i], B.insert(b[i]);
    segtree solver(1e6 + 2);
    solver.solve();
}