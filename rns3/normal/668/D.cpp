#include <bits/stdc++.h>
using namespace std;

const int M = 2000001;

struct dat{
    int x, y, z;
    dat(int x = 0, int y = 0, int z = 0):x(x), y(y), z(z){}
};

vector<dat> v[M];
int a[M], t[M], x[M];
int sto[M];
int bit[M];
int ans[M];
int m;
int A[M];

void add(int x, int val) {
    while(x <= m) {
        bit[x] += val;
        x += x & -x;
    }
    return;
}

int calc(int x) {
    int tp = 0;
    while(x) {
        tp += bit[x];
        x -= x & -x;
    }
    return tp;
}

int main() {
    ///freopen("D.in", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) {
        scanf("%d %d %d", &a[i], &t[i], &x[i]);
        sto[cnt ++] = x[i];
    }
    sort(sto, sto + cnt);
    cnt = unique(sto, sto + cnt) - sto;
    for(int i = 1; i <= n; i ++) {
        x[i] = lower_bound(sto, sto + cnt, x[i]) - sto + 1;
        v[x[i]].push_back(dat(a[i], t[i], i));
    }
    for(int i = 1; i <= cnt; i ++) {
        m = 0;
        for(int j = 0; j < v[i].size(); j ++) A[m ++] = v[i][j].y;
        sort(A, A + m);
        m = unique(A, A + m) - A;
        for(int j = 0; j <= m; j ++) bit[j] = 0;
        for(int j = 0; j < v[i].size(); j ++) {
            int x = lower_bound(A, A + m, v[i][j].y) - A + 1;
            if(v[i][j].x == 1) add(x, 1);
            else if(v[i][j].x == 2) add(x, -1);
            else {
                ans[v[i][j].z] = calc(x);
            }
        }
    }
    for(int i = 1; i <= n; i ++) if(a[i] == 3) printf("%d\n", ans[i]);
}