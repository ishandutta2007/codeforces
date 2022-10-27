#include <iostream>
#include <cstring>
using namespace std;
const int N=1000000+10;
int n,k,a[N],c[N];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),c[a[i]]++;
    bool fg=0;int mn=1e9;
    for(int i=1;i<=n;i++){
        if(a[i]>k)fg=1;
        mn=min(mn,a[i]);
    }
    if(!fg)return !printf("%d\n",mn);
    for(int i=1;i<=1000000;i++)c[i]+=c[i-1];
    int ans=1;
    for(int i=1;i<=1000000;i++){
        int tot=0;
        for(int j=i;j<=1000000;j+=i){
            int l=j,r=min(min(j+i-1,j+k),1000000);
            tot+=c[r]-(l?c[l-1]:0);
        }
        if(tot==n)ans=i;
    }
    cout<<ans<<endl;
}