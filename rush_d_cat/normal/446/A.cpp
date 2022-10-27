#include <iostream>
using namespace std;
const int N=100000+10;
int n,a[N],pre[N],suf[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1]) pre[i]=pre[i-1]+1; else pre[i]=1;
    }
    a[n+1]=1e9+7;
    for(int i=n;i>=1;i--){
        if(a[i]<a[i+1]) suf[i]=suf[i+1]+1; else suf[i]=1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(a[i-1]+2<=a[i+1]) ans=max(ans,pre[i-1]+suf[i+1]+1);
        else {
            ans=max(ans, pre[i-1]+1);
            ans=max(ans, suf[i+1]+1);
        }
    }
    cout<<ans<<endl;
}