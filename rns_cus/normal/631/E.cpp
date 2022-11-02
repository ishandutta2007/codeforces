#include <bits/stdc++.h>

using namespace std;

#define N 200200

typedef long long LL;

LL a[N], ans, rt, tp, s[N];
int n, q[N];

LL g(int i, int j) {
    return rt + a[i] * (j - i) - s[j - 1] + s[i - 1];
}

LL f(int i, int j) {
    return rt + a[i] * (j - i) - s[j] + s[i];
}

bool chk(int i, int j, int k) {
    return (k - j) * (s[j] - s[i]) <= (j - i) * ( s[k] - s[j]);
}

bool CHK(int i, int j, int k) {
    return (k - j) * (s[j-1] - s[i-1]) <= (j - i) * ( s[k-1] - s[j-1]);
}

bool chk1(int i, int j, int k) {
    return f(i, j) < f(i, k);
}

bool chk2(int i, int j, int k) {
    return g(i, j) < g(i, k);
}

int main() {
    //freopen("E3.in","r",stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%I64d", a + i);
        ans += i * a[i];
        s[i] = s[i-1] + a[i];
    }
    rt = ans;
    int st = 0, en = 0;
    q[en ++] = n;
    for(int i = n - 1; i; i --) {
        int l = st, r = en - 1;
        while(l != r) {
            int md = (l + r) >> 1;
            if(chk1(i, q[md], q[md + 1])) l = md + 1; else r = md;
        }
        ans = max(ans, f(i, q[l]));
        while(st + 1 < en) {
            if(!chk(i, q[en-1], q[en-2])) en --;
            else break;
        }
        q[en ++] = i;
    }
    st = en = 0;
    q[en ++] = 1;
    for(int i = 2; i <= n; i ++) {
        int l = st, r = en - 1;
        while(l != r) {
            int md = (l + r) >> 1;
            if(chk2(i, q[md], q[md + 1])) l = md + 1; else r = md;
        }
        ans = max(ans, g(i, q[l]));
        while(st + 1 < en) {
            if(!CHK(q[en-2], q[en - 1], i)) en --;
            else break;
        }
        q[en ++] = i;
    }
    printf("%I64d\n", ans);
    return 0;
}