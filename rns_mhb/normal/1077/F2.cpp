#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 5010

struct IS {
    ll b[N];
    int id[N];
    int st, ed;
    void init() {st = ed = 0;}
    void insert(ll x, int idx) {
        while(ed > st && b[ed-1] <= x) ed --;
        id[ed] = idx;
        b[ed ++] = x;
    }
    void erase(int idx) {if(id[st] == idx) st ++;}
    ll front() {return b[st];}
} q;

ll f[N], g[N];
int a[N];

int main() {
    int n, k, x;
    scanf("%d%d%d", &n, &k, &x);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= k; i ++) f[i] = a[i];
    for(int i = k + 1; i <= n; i ++) f[i] = -1;
    for(int i = 2; i <= x; i ++) {
        q.init();
        g[1] = -1;
        for(int j = 2; j <= n; j ++) {
            q.insert(f[j-1], j-1);
            if(j > k+1) q.erase(j-k-1);
            g[j] = (q.front() == -1 ? -1 : q.front() + a[j]);
        }
        swap(f, g);
    }
    ll ans = -1;
    for(int i = n-k+1; i <= n; i ++) if(f[i] > ans) ans = f[i];
    printf("%I64d\n", ans);
}