#include <iostream>
using namespace std;
typedef long long LL;
const int N=3502;
int t,n,m,k,a[N],s[N];
int ok(int x){
    k=min(m-1,k);
    for(int i=1;i<=n;i++){
        s[i]=0;
        if(i+n-m<=n&&(a[i]>=x||a[i+n-m]>=x)){
            s[i]=1;

        }
    }

    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    int rem=m-1-k;
    for(int x=0;x<=k;x++){
       // printf("x=%d, [%d, %d]\n", x, x+1,x+rem+1);
        // a[x+1]+...+a[x+rem+1]
        if(s[x+rem+1]-s[x] == x+rem+1-x) return 1;
    }
    return 0;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        //ok(7); return 0;
        int lef=1,rig=1e9+1;
        while(rig-lef>1){
            int mid=(lef+rig)>>1;
            if(ok(mid)){
                lef=mid;
            }else{
                rig=mid;
            }
        }
        printf("%d\n", lef);
    }
}