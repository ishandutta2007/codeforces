#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000005;

int n , m;
int c[N][2] , cnt;
int Lm[N] , Ln[N] , Rm[N] , Rn[N];
bool flag;
vector<int> res;
void dfs(int l , int r) {
    if (flag) return;
    ++ cnt;
    if (Lm[l]) {
        if (Ln[l] <= cnt)
            flag = 1;
        dfs(cnt + 1 , Lm[l]);
    }
    res.push_back(l);
    if (Rm[l]) {
        if (Rn[l] <= cnt)
            flag = 1;
        dfs(cnt + 1 , max(Rm[l] , r));
    } else if (cnt < r) {
        dfs(cnt + 1 , r);
    }
}

void work() {
    int i , x , y;
    char str[10];
    scanf("%d%d",&n,&m);
    for (i = 1 ; i <= n ; ++ i) {
        Ln[i] = Rn[i] = n + 1;
        Lm[i] = Rm[i] = 0;
    }
    for (i = 0 ; i < m ; ++ i) {
        scanf("%d%d%s" , &x , &y , str);
        if (*str == 'L') {
            Lm[x] = max(Lm[x] , y);
            Ln[x] = min(Ln[x] , y);
        } else {
            Rm[x] = max(Rm[x] , y);
            Rn[x] = min(Rn[x] , y);
        }
    }
    dfs(1 , n);
    if (flag)
        puts("IMPOSSIBLE");
    else {
        for (auto it : res)
            printf("%d " , it);
    }
        
}

int main() {
//    freopen("1" , "r" , stdin);
    work();
    return 0;
}