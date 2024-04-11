#include<bits/stdc++.h>
using namespace std;
int n,k,a[400005],cnt,ans;
int main(){
    scanf("%d%d",&n,&k);
    k=k*8/n;
    int lim=1;
    for(;k&&lim<=n;lim<<=1,k--);
    if(lim>=n){puts("0");return 0;}
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int l=1,r=1;
    a[0]=-1;
    cnt=1;
    for(l=1;l<=n;++l){
        if(a[l]!=a[l-1]) cnt--;
        for(;r<=n;++r){
            if(a[r]!=a[r-1]){
                cnt++; 
                if(cnt>lim) {cnt--;break;}
            }
        }
        ans=max(ans,r-l);
    }
    printf("%d",n-ans);
    return 0;
}