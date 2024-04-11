#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
int main(){
    int k,a,b;scanf("%d%d%d",&k,&a,&b);
    int ans=a/k+b/k;
    if((a<k&&b<k)||(b<k&&(a%k!=0))||(a<k&&(b%k!=0)))printf("-1");
    else{
        printf("%d\n",ans);
    }
    return 0;
}