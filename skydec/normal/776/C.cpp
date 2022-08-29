#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=110000;
map<LL,int>num;
int n;LL sum[N];int k;
LL aa(LL x){if(x<0)return -x;else return x;}
int main(){
    scanf("%d%d",&n,&k);
    rep(i,1,n)scanf("%I64d",&sum[i]);
    rep(i,1,n)sum[i]+=sum[i-1];
    LL ans=0;
    rep(i,1,n){
        num[sum[i-1]]++;
        if(k==1){
            ans+=num[sum[i]-1];
        }
        else
        if(k==-1){
            ans+=num[sum[i]-1];
            ans+=num[sum[i]+1];
        }
        else{
            LL now=1;
            while(aa(now)<=(LL)(1e15)){
                ans+=num[sum[i]-now];
                now*=k;
            }
        }
    }
    printf("%I64d\n",ans);
    return 0;
}