#include <iostream>
using namespace std;
const int N=502;
int n,k;
int a[N][N];
int main(){
    scanf("%d%d",&n,&k);
    int tot=n*n,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=n;j>=k;j--){
            a[i][j]=tot--;
            if(j==k)ans+=a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=k-1;j>=1;j--){
            a[i][j]=tot--;
            if(j==k)ans+=a[i][j];
        }
    }
    printf("%d\n", ans);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)printf("%d ", a[i][j]);
        printf("\n");
    }
}