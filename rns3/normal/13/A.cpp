///a
#include<stdio.h>
int main()
{
    int n,sum=0,y;
    scanf("%d",&n);
    for(int i=2;i<n;i++){
        int nn=n;
        while(nn){
            sum+=nn%i;
            nn/=i;
        }
    }
    y=n-2;
    for(int i=2;i<=y;i++){
        while(y%i==0 && sum%i==0){
            y/=i;
            sum/=i;
        }
    }
    printf("%d/%d\n",sum,y);
    return 0;
}