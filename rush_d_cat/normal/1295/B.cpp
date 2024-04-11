#include <iostream>
using namespace std;
const int N=100000+10;
int T,n,x;
char s[N];
int sum[N];
int main() {
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%s",&n,&x,s+1);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+(s[i]=='0'?1:-1);
        }
        bool inf=0; int ans=0;
        for(int i=0;i<n;i++){
            int now=sum[i];
            if(now==x && sum[n]==0) {
                inf=1; break;
            }
            if(sum[n])
                if((x-now)%sum[n]==0 && (x-now)/sum[n]>=0) ans++;
        }
        if(inf) printf("-1\n"); else printf("%d\n", ans);
    }
}