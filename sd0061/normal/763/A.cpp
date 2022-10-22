#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
typedef long long LL;
int n , a[N] , b[N];
vector<int> e[N];

int pre[N] , ncnt;
int suf[N];
int mx[N];
int size[N];

LL pp[N] , ss[N] , mm[N];

int f[N];

int L[N] , R[N];

void dfs(int x , int fa) {
    L[x] = ++ ncnt;
    b[ncnt] = a[x];
    f[x] = fa;
    mm[x] = mx[x] = a[x];
    size[x] = 1;
    for (auto &y : e[x]) {
        if (y != fa) {
            dfs(y , x);
            size[x] += size[y];
            mm[x] += mm[y];
            mx[x] = max(mx[x] , mx[y]);
        }
    }
    R[x] = ncnt;
}

int main() {
    scanf("%d" , &n);
    for (int i = 1 ; i < n ; ++ i) {
        int x , y;
        scanf("%d%d" , &x , &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d" , &a[i]);
    }
    dfs(1 , 0);
    for (int i = 1 ; i <= n ; ++ i) {
        pp[i] = pp[i - 1] + b[i];
        pre[i] = max(pre[i - 1] , b[i]);
    }
    for (int i = n ; i > 0 ; -- i) {
        ss[i] = ss[i + 1] + b[i];
        suf[i] = max(suf[i + 1] , b[i]);
    }
    for (int x = 1 ; x <= n ; ++ x) {
        if ((LL)pre[L[x] - 1] * (L[x] - 1) != pp[L[x] - 1]) continue;
        if ((LL)suf[R[x] + 1] * (n - R[x]) != ss[R[x] + 1]) continue;
        if (L[x] > 1 && R[x] < n && b[1] != b[n]) continue;
        bool flag = 1;
        //cout << x << endl;
        for (auto &y : e[x]) {
            if (y != f[x]) {
                if ((LL)mx[y] * size[y] != mm[y]) {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) {
            printf("YES\n%d\n" , x);
            return 0;
        }
    }
    puts("NO");
}