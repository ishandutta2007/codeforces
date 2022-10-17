# include <bits/stdc++.h>
# define rr register
const int N=110;
int sum0,sum1;
int a[N];
int n;
int main(void){
    scanf("%d",&n);
    for(rr int i=1;i<=n;++i){
        scanf("%1d",&a[i]);
        if(!a[i]){
            ++sum0;
        }
        else{
            ++sum1;
        }
    }
    if(sum0==sum1){
        printf("2\n");
        printf("%d ",a[1]);
        for(rr int i=2;i<=n;++i)
            printf("%d",a[i]);
    }
    else{
        printf("1\n");
        for(rr int i=1;i<=n;++i){
            printf("%d",a[i]);
        }       
    }

    return 0;
}