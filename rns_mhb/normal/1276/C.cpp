#include<bits/stdc++.h>
using namespace std;

#define N 400010

int a[N], b[N], cnt[N], id[N], c[N], s[N];

bool cmp(int i, int j) {
    return cnt[i] < cnt[j];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) b[i] = a[i];
    sort(b+1, b+n+1);
    int m = unique(b+1, b+n+1) - b-1;
    for(int i = 1; i <= n; i ++) a[i] = lower_bound(b+1, b+m+1, a[i]) - b;
    for(int i = 1; i <= n; i ++) cnt[a[i]] ++;
    for(int i = 1; i <= m; i ++) c[i] = cnt[i];
    sort(c+1, c+m+1);
    for(int i = 1; i <= m; i ++) s[i] = s[i-1] + c[i];
    for(int i = 1; i <= m; i ++) id[i] = i;
    sort(id + 1, id + m + 1, cmp);
    int sz = 0;
    int R, C;
    for(int r = 1; r <= n; r ++) {
        int i = lower_bound(c+1, c+m+1, r) - c;
        int tot = s[i-1] + (m-i+1) * r;
        int w = tot / r;
        if(r > w) continue;
        if(r * w > sz) {
            sz = r * w;
            R = r, C = w;
        }
    }
    vector <vector<int> > ans;
    ans.resize(R);
    for(int i = 0; i < R; i ++) ans[i].resize(C);
    int st = m, g = 0;
    for(int j = 0; j < C; j ++) for(int i = 0; i < R; i ++) {
        ans[i][(i+j)%C] = b[id[st]];
        g ++;
        if(g == cnt[id[st]] || g == R) {
            st --;
            g = 0;
        }
    }
    printf("%d\n%d %d\n", R*C, R, C);
    for(int i = 0; i < R; i ++) {
        for(int j = 0; j < C; j ++) printf("%d ", ans[i][j]);
        puts("");
    }
}