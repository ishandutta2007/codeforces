#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000], n;
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=2;i<=n+1;i++){
        for(j=i+i;j<=n+1;j+=i){
            w[j] = 1;
        }
    }
    if(n<=2){
        printf("1\n");
        for(i=1;i<=n;i++)printf("%d ",1);
        return 0;
    }
    printf("2\n");
    for(i=1;i<=n;i++){
        if(!w[i+1])printf("1 ");
        else printf("2 ");
    }
}