#include<iostream>
using namespace std;
int n,k,dp[300000+2],pos[300000+2],a[300000+2];//pos0
int main(){
    cin>>n>>k;
    int index=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        dp[n]=0;
        if(a[i]==0) pos[++index]=i;
    }
    if(a[1]==1) dp[1]=1;
    if(a[1]==0&&k>=1) dp[1]=1;
    int tmp=0;
    if(a[1]==0) tmp++;
    for(int i=1;i<=n-1;i++){
        if(a[i+1]==1) dp[i+1]=dp[i]+1;
        else{
            tmp++;
            if(tmp>=k){
                if(k==0) dp[i+1]=0;
                else dp[i+1]=(i+1)-(pos[tmp-k+1])+1;
                int tmp1=pos[tmp-k+1];
                while(a[--tmp1]==1&&tmp1>=1) dp[i+1]++;
                if(k==0) dp[i+1]=0;
            }
            else dp[i+1]=i+1;
        }
    }
    int m=-1,v=1;
    for(int i=1;i<=n;i++){
        if(dp[i]>m){
            m=dp[i];
            v=i;
        }
    }
    printf("%d\n",m);
    for(int i=1;i<=n;i++){
        if(i<=v&&i>=v-m+1) printf("1 ");
        else printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}