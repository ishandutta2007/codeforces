#include <iostream>
using namespace std;
typedef long long LL;
const LL inf = 1e18;
const int N=5002;
int n,k,x,a[N];
LL dp[N];
struct Queue {
    int head,tail;
    pair<LL,int> que[N];
    Queue(){head=1,tail=0;}
    void push(LL x,int pos){
        while(head<=tail && que[tail].first <= x) --tail;
        que[++tail]=make_pair(x,pos);
        while(head<=tail && que[tail].second-que[head].second>=k) ++head;
    }
    LL querymax(){
        return head<=tail?que[head].first:-inf;
    }
} q;

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)dp[i]=-inf; dp[0]=0;
    LL ans=-inf;
    for(int j=1;j<=x;j++){
        q=Queue();
        for(int i=0;i<=n;i++){
            LL tmp=dp[i];
            dp[i]=a[i]+q.querymax();
            q.push(tmp,i);
            if(i>n-k)ans=max(ans,dp[i]);
        }
    }
    if(ans<-1e16) ans=-1; 
    printf("%lld\n", ans);
}