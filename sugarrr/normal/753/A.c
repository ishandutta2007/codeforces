#include <stdio.h>


int main(){
    int a[1005];
    int i;
    a[0]=0;
    for(i=1;i<=1001;i++){
        a[i]=i+a[i-1];
    }
    
    int n;
    scanf("%d",&n);
    int ans=0;
    for(i=1;i<=1000;i++){
        if(n<a[i])break;
        else ans++;
    }
    printf("%d\n",ans);
    int sum=0;
    for(i=1;i<=ans-1;i++){
        printf("%d ",i);
        sum+=i;
    }
    printf("%d",n-sum);
    
    return 0;
}