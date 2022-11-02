//D
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define N 555
#define ll long long

map <ll, int> mp;
int n, m;
int a[N], b[N];

int f(int en, int x, int y){
    ll TT = 1ll * en * N * N + 1ll * x * N + y;
    if(mp[TT]) return mp[TT] - 1;

    while(a[x] <= en) x ++;
    while(b[y] <= en) y ++;
    if(x >= n || y >= m) {
        mp[TT] = 1;
        return 0;
    }

    int ans = f(en, x+1, y);
    for(int j=y; j<m; j++) if(b[j] == a[x]) {
        int r = 1 + f(a[x], x+1, j+1);
        if(r > ans) ans = r;
        break;
    }

    mp[TT] = ans + 1;
    return ans;
}

void dfs(int en, int x, int y){
    while(a[x] <= en) x ++;
    while(b[y] <= en) y ++;

    if(x >= n || y >= m) return;

    int ans = f(en, x+1, y);
    for(int j=y; j<m; j++) if(b[j] == a[x]) {
        int r = 1 + f(a[x], x+1, j+1);
        if(r > ans) {
            printf("%d ", a[x]);
            dfs(a[x], x+1, j+1);
            return ;
        }
        break;
    }
    dfs(en, x+1, y);
}

int main(){
    //freopen("d.in", "r", stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=0; i<m; i++) scanf("%d", &b[i]);

    printf("%d\n", f(-1, 0, 0));
    dfs(-1, 0, 0);
}