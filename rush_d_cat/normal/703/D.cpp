#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int NICO = 1000000+10;
int n, m, l[NICO], r[NICO], a[NICO], pre[NICO], s[NICO], ans[NICO], id[NICO];
int bit[NICO]; 
map<int, int> mp;

bool cmp(int x, int y) {
    return r[x] < r[y];
}

void add(int i, int x) {
    //printf("add(%d, %d)\n", i, x);
    while(i <= n) {
        bit[i] ^= x;
        i += i&(-i);
    }
}

int sum(int i) {
    int res = 0;
    //printf("sum(%d) = ", i);
    while(i > 0) {
        res ^= bit[i];
        i -= i&(-i);
    }
    //printf("%d\n", res);
    return res;
}

int main() {
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        if(mp[a[i]]) pre[i] = mp[a[i]];
        mp[a[i]] = i; s[i] = s[i-1] ^ a[i];
    }
    scanf("%d", &m);
    for(int i=1;i<=m;i++) {
        scanf("%d %d", &l[i], &r[i]); 
        id[i] = i;
    }
    sort(id+1, id+1+m, cmp);
    int j = 1;
    for(int i=1;i<=m;i++) {
        for(; j<=r[id[i]]; j++) {
            if(pre[j]) {
                add(pre[j], a[j]);
            } 
            add(j, a[j]);
        }
        ans[id[i]] = s[r[id[i]]] ^ s[l[id[i]] - 1] ^ sum(r[id[i]]) ^ sum(l[id[i]] - 1);
        //printf("solve(%d, %d) = %d\n", l[id[i]], r[id[i]], ans[id[i]]);
    }
    for(int i=1;i<=m;i++) {
        printf("%d\n", ans[i]);
    }
}