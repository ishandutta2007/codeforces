#include <iostream>
#include <algorithm>
using namespace std;
int t,n,m,a[5][102];
int col[102],mx[102];
bool cmp(int x,int y){
    return mx[x] > mx[y];
}
int ans = 0;
void dfs(int dep, int val[]) {
    //printf("dep = %d\n", dep);
    if(dep == 6 || dep > m) {
        int sum = 0;
        for(int i=1;i<=n;i++) sum += val[i];
        ans = max(ans, sum);
        return;
    }
    for(int i=1;i<=n;i++) {
        int tmp[5] = {0};
        for(int j=i;j<i+n;j++) {
            int pos = j<=n ? j : j-n;
            tmp[j-i+1] = max(a[pos][col[dep]], val[j-i+1]); 
        }
        dfs(dep+1, tmp);
    }
}
int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++) mx[i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                //a[i][j] = rand() % 10;
                mx[j] = max(mx[j], a[i][j]);
            }
        }
        for(int i=1;i<=m;i++) col[i]=i;
        sort(col+1,col+1+m,cmp);
        /*
        for(int i=1;i<=3;i++)
            printf("# %d\n", col[i]);

        printf("ok\n");
        */
        ans = 0;
        int val[5] = {0};
        dfs(1, val);
        printf("%d\n", ans);
    }
}