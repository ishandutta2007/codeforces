#include<bits/stdc++.h>
using namespace std;

#define fr first
#define se second
#define pb push_back
#define inf 1e9
#define INF 1e18
#define N 200010
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef unsigned long long bll;
template<class T>inline void chkmin(T&x,T y){if(y<x)x=y;}
template<class T>inline void chkmax(T&x,T y){if(x<y)x=y;}

int tree[N], a[N], b[N], n;
bool vis[N];

void update(int x) {for(int i = x; i <= n; i += i & -i) tree[i] ++;}

int query(int x) {
    int ret = 0;
    for(int i = x; i; i -= i & -i) ret += tree[i];
    return ret;
}

int find(int l, int r, int k) {
    if(l == r) return l;
    int mid = l + r >> 1;
    int num = mid - query(mid);
    if(num < k) return find(mid + 1, r, k);
    if(num > k) return find(l, mid - 1, k);
    if(num == k) {
        if(vis[mid]) return find(l, mid - 1, k);
        return mid;
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
        a[i] ++;
        update(a[i]);
        a[i] -= query(a[i]);
    }
    memset(tree, 0, sizeof tree);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", b + i);
        b[i] ++;
        update(b[i]);
        b[i] -= query(b[i]);
    }
    for(int i = 1; i <= n; i ++) a[i] += b[i];
    reverse(a + 1, a + n + 1);
    for(int i = 1; i <= n; i ++) a[i + 1] += a[i] / i, a[i] %= i;
    reverse(a + 1, a + n + 1);
    memset(tree, 0, sizeof tree);
    for(int i = 1; i <= n; i ++) {
        int tmp = find(1, n, a[i] + 1);
        b[i] = tmp - 1;
        update(tmp);
        vis[tmp] = 1;
    }
    for(int i = 1; i <= n; i ++) printf("%d ", b[i]); puts("");
}