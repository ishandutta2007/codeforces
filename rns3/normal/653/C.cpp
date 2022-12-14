#include <bits/stdc++.h>
using namespace std;

#define N 150010

int a[N], n, b[N], d[N], c, e;

typedef pair<int, int> pii;
map <pii, int> mp;

bool O(int i) {
    if(!i || i >= n) return 1;
    if(i & 1) return a[i] < a[i + 1];
    return a[i] > a[i + 1];
}

bool ok(int j,  int k) {
    if(!O(j)) return 0;
    if(!O(j-1)) return 0;
    if(!O(j+1)) return 0;
    if(!O(k)) return 0;
    if(!O(k-1)) return 0;
    if(!O(k+1)) return 0;
    for(int i = 0; i < e; i ++) if(!O(d[i])) return 0;
    return 1;
}

int main() {
    //freopen("in.txt","r",stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", a + i);
    for(int i = 1; i < n; i ++) {
        if(i & 1) {
            if(a[i] >= a[i + 1]) b[c ++] = i, b[c ++] = i + 1, d[e ++] = i;
        } else {
            if(a[i] <= a[i + 1]) b[c ++] = i, b[c ++] = i + 1, d[e ++] = i;
        }
    }
    sort(b, b + c); c = unique(b, b + c) - b;
    if(e > 4) {
        puts("0"); return 0;
    }
    int ans = 0;
    for(int i = 0; i < c; i ++) {
        int k = b[i];
        for(int j = 1; j <= n; j ++) if(j != k) {
            swap(a[j], a[k]);
            if(ok(j, k)) {
                int x = j, y = k;
                if(x > y) swap(x, y);
                if(!mp.count(pii(x, y))) {
                    ans ++;
                    mp[pii(x, y)] = 1;
                }
            }
            swap(a[j], a[k]);
        }
    }
    printf("%d\n", ans);
    return 0;
}