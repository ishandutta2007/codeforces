#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N=1000000+10;
const LL INF = 1e18;
struct Item{
    LL x,y,a;
    bool operator<(const Item&o)const{
        return x<o.x;
    }
    void read(){
        scanf("%lld%lld%lld",&x,&y,&a);
    }
} it[N];

int n,top;LL dp[N];
struct P{
    double x,y; int id;
} p[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)it[i].read();
    sort(it+1,it+1+n);
    LL ans=0;

    p[0] = (P){INF,0,0};
    for(int i=1;i<=n;i++) {
        int l=0,r=top+1;
        while(r-l>1){
            int mid=(l+r)>>1;
            if(p[mid].x >= it[i].y) {
                l=mid;
            } else {
                r=mid;
            }
        }
        int j = p[l].id;

        dp[i]=max(dp[i],dp[j]+(it[i].x-it[j].x)*it[i].y-it[i].a);
        while(top && dp[i]-it[i].x*p[top].x > p[top].y) top--;
        double px,py;
        //printf("(%d-%d)-(%d-%d)\n", dp[p[top].id] ,dp[i],it[p[top].id].x,it[i].x);
        px = 1.0 * (dp[p[top].id] - dp[i]) / (it[p[top].id].x - it[i].x);
        py = dp[i] - px * it[i].x;
        p[++top] = (P){px,py,i};

        ans = max(ans,dp[i]);
     }   

    cout<<ans<<endl;
}