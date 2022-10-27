#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1002;
typedef long long LL;
LL n,m,k,d;
LL a[N][N];
LL r[N],c[N];
vector<LL> R,C;
LL preR[N*N],preC[N*N];

priority_queue<LL> qR,qC;

bool cmp(int x,int y){
    return x>y;
}
int main(){
    scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            r[i]+=a[i][j],c[j]+=a[i][j];
        }
    }   
    for(int i=1;i<=n;i++){
        qR.push(r[i]);
    }
    for(int i=1;i<=k;i++){
        LL tmp = qR.top(); qR.pop();
        R.push_back(tmp); tmp -= 1LL*m*d;
        qR.push(tmp);
    }
    
    for(int i=1;i<=m;i++){
        qC.push(c[i]);
    }
    for(int i=1;i<=k;i++){
        LL tmp = qC.top(); qC.pop();
        C.push_back(tmp); tmp -= 1LL*n*d;
        qC.push(tmp);
    }

    for(int i=1;i<=k;i++) {
        //printf("%d %d\n", R[i-1],C[i-1]);
        preR[i]=preR[i-1]+R[i-1], preC[i]=preC[i-1]+C[i-1];
    }

    LL ans = -1e18;
    for(int i=0;i<=k;i++){
        ans=max(ans, preR[i]+preC[k-i]-d*(k-i)*i);
    }
    
    cout<<ans<<endl;
}