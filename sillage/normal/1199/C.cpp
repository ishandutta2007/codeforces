#include<cstdio>
#include<algorithm>
using namespace std;
int n,mx,a[400110];
int main(){
    scanf("%d%d",&n,&mx);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    int res=mx*8/n;
    if (res>20){
        puts("0");
        return 0;
    }
    a[n+1]=-1;
    mx=1<<res;
    sort(a+1,a+1+n);
    int l=1,r=1;
    while (a[r+1]==a[r]) r++;
    int cnt=1,ans=r-l+1;
    while (r<=n){
        while(cnt<mx){
            cnt++;
            r++;
            if (r>n) break;
            while (a[r+1]==a[r]) r++;
            if (r-l+1>ans) ans=r-l+1;
        }
        cnt--;
        while (a[l+1]==a[l]) l++;
        l++;
    }
    printf("%d\n",n-ans);
    return 0;
}