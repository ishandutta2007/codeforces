#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=3000+10;
int n,m,a,b;
LL g[N*N],h[N][N],meow[N][N];
pair<int,int> que[N];
int main() {
    scanf("%d%d%d%d",&n,&m,&a,&b);
    LL x,y,z; scanf("%lld%lld%lld%lld",&g[0],&x,&y,&z);
    for(int i=1;i<=n*m;i++) g[i]=(g[i-1]*x+y)%z;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)h[i][j]=g[(i-1)*m+j-1];
    for(int j=1;j<=m;j++){
        int head=1,tail=0;
        for(int i=1;i<=n;i++){
            // add h[i][j]
            while(head<=tail && que[tail].first>=h[i][j])--tail;
            que[++tail]=make_pair(h[i][j],i);
            while(head<=tail && i-que[head].second+1>a)++head;
            if(i>=a) {
                //printf("meow (%d %d) = %d\n", i-a+1,j,que[head].first);
                meow[i-a+1][j]=que[head].first;
            }
        }   
    }

    LL ans=0;
    for(int i=1;i<=n-a+1;i++){
        int head=1,tail=0;
        for(int j=1;j<=m;j++){
            // add meow[i][j]
            while(head<=tail && que[tail].first>=meow[i][j])--tail;
            que[++tail]=make_pair(meow[i][j],j);
            while(head<=tail && j-que[head].second+1>b)++head;
            if(j>=b) ans+=que[head].first;            
        }
    }
    cout<<ans<<endl;
}