#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 100010
#define L 18

ll wrk[N];
int a[N], prv[N], rnk[L][N], c[N], n;

bool cmp(int i, int j) {return wrk[i] < wrk[j];}

void get_rank(int *r) {
    sort(c + 1, c + n + 1, cmp);
    int i, R = 0;
    for(i = 1; i <= n; i ++) {
        if(wrk[c[i]] != wrk[c[i - 1]]) R ++;
        r[c[i]] = R;
    }
    for(i = 1; i <= n; i ++) wrk[i] = 1ll * N * r[i] + r[i + 1];
}

void build() {
    int i, bit = 1;
    wrk[0] = -1;
    for(i = 1; i <= n; i ++) c[i] = i, wrk[i] = 1ll * a[i];
    for(i = 0; bit <= n; bit <<= 1, i ++) get_rank(rnk[i]);
}

bool repeat(int l, int r) {
    if(2 * r - l - 1 > n) return 0;
    int bit = 1 << L, st = l, ed = r, lz = L;
    while(st < r) {
        if(bit <= r - st) {
            if(rnk[lz][ed] != rnk[lz][st]) return 0;
            else st += bit, ed += bit;
        }
        bit >>= 1;
        lz --;
    }
    return 1;
}

map<int, int> mp;

int main() {
    int i, j, k, st;
    scanf("%d", &n);
    for(i = 1; i <= n; i ++) scanf("%d", a + i);
    build();
    for(i = 1; i <= n; i ++) {
        prv[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    st = 1;
    for(i = 1; i <= n; i ++) {
        for(j = prv[i]; j >= st; j = prv[j]) if(repeat(j, i)) {
            st = i;
            break;
        }
    }
    printf("%d\n", n - st + 1);
    for(i = st; i <= n; i ++) {
        if(i > st) putchar(' ');
        printf("%d", a[i]);
    } puts("");
}