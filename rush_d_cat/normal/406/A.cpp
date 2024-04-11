#include <iostream>
using namespace std;
typedef long long LL;
const int N=1002;
int n,a[N][N];
int main(){
    scanf("%d",&n);
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][i]==1 && i==j)cnt++;
        }
    }
    int q; scanf("%d",&q);
    while(q--){
        int op; scanf("%d",&op);
        if(op==1||op==2) {
            int x; scanf("%d",&x);
            cnt++;
        } else {
            printf("%d", cnt%2);
        }
    } printf("\n");
}