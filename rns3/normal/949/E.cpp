#include <bits/stdc++.h>
using namespace std;

#define N 100010

int a[N], ans;
int pw[20] = {1};
int n, c[20];
bool b[20][1<<18];
vector <int> v;

void func(int k, int ds) {
    if (k == 17) {
        if (b[k][0]) c[17] = -1, ds ++;
        else if (b[k][2]) c[17] = 1, ds ++;
        else c[17] = 0;
        if (ds >= ans) return;
        ans = ds;
        v.clear();
        for (int i = 0; i <= 17; i ++) {
            if (c[i] == 1) v.push_back(1<<i);
            else if (c[i] == -1) v.push_back(-(1<<i));
        }
        c[17] = 0;
        return;
    }
    bool flag = 0;
    for (int i = 1; i <= pw[18 - k] && !flag; i += 2) {
        if (b[k][i]) flag = 1;
    }
    if (!flag) {
        for (int i = 0; i <= pw[17-k]; i ++) b[k+1][i] = b[k][i<<1];
        c[k] = 0;
        return func(k+1, ds);
    }
    for (int i = pw[17-k], j = 0; i <= pw[18-k]; i += 2, j ++) b[k+1][pw[16-k]+j] = b[k][i] | b[k][i+1];
    for (int i = pw[17-k]-1, j = 1; i >= 0; i -= 2, j ++) b[k+1][pw[16-k]-j] = b[k][i] | b[k][i-1];
    c[k]=1;
    func(k+1, ds+1);
    for (int i = pw[17-k], j = 0; i >= 0; i -= 2, j ++) b[k+1][pw[16-k]-j] = b[k][i] | b[k][i-1];
    for (int i = pw[17-k]+1, j = 1; i <= pw[18-k]; i += 2, j ++) b[k+1][pw[16-k]+j] = b[k][i] | b[k][i+1];
    c[k] = -1;
    func(k+1, ds + 1);
}

int main() {
    ans = 30;
    for (int i = 1; i < 20; i ++) pw[i] = pw[i-1] << 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        b[0][a[i] + pw[17]] = 1;
    }
    func(0, 0);
    printf("%d\n", ans);
    for (int i = 0; i < v.size(); i ++) printf("%d ", v[i]);
	return 0;
}