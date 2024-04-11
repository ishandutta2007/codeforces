#include <bits/stdc++.h>
using namespace std;

#define N 1000005

template <class T> bool chkmax(T &a, T b) { return a < b ? 1, a = b : 0; }
int k, cnt, n, mx;
char s[N];
int l[N];

bool test(int m) {
    if (mx > m) return 0;
    int rtn = 0;
    for (int i = 0, j = 0; i < cnt; ) {
        if (l[i] + (i<cnt-1) > j) {
            rtn ++;
            j = m;
        }
        else {
            j -= l[i] + (i<cnt-1);
            i ++;
        }
    }
    return rtn <= k;
}

int main() {
    scanf("%d ", &k);
    gets(s);
    n = strlen(s);
    s[n] = '-';
    for (int i = 0, j = 0; i <= n; i ++) {
        if (s[i] == '-' || s[i] == ' ') {
            l[cnt++] = j;
            j = 0;
        }
        else j ++;
    }
    mx = l[cnt-1];
    for (int i = 0; i < cnt - 1; i ++) chkmax(mx, l[i] + 1);
    int st = 1, en = N;
    while (st < en) {
        int mid = st + en >> 1;
        if (test(mid)) en = mid;
        else st = mid + 1;
    }
    printf("%d\n", st);
    return 0;
}