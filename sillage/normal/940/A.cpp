#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,x[110],ans=1e9;
int main(){
    scanf("%d%d",&n,&d);
    for (int i=1; i<=n; i++) scanf("%d",&x[i]);
    sort(x+1,x+1+n);
    for (int i=1; i<=n; i++){
        int cnt=1;
        for (int j=i-1; j>=1; j--) if (x[i]-x[j]<=d) cnt++;
        ans=min(ans,n-cnt);
    }
    printf("%d\n",ans);
}