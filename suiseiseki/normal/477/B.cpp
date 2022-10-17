#include <cstdio>
int d[10005][4],n,k;
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        d[i][0]=6*i-5;
        d[i][1]=6*i-4;
        d[i][2]=6*i-3;
        d[i][3]=6*i-1;
    }
    printf("%d\n",d[n][3]*k);
    for(int i=1;i<=n;i++){
        for(int j=0;j<4;j++){
        	printf("%d ",d[i][j]*k);
		}
        printf("\n");
    }
    return 0;
}