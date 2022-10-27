#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;
const int INF = 1e9+7;
const int N=200000+10;
int n,x,y;
char s[N];
int preX[N],preY[N],sufX[N],sufY[N];
int solve(int pos) {
    int L=pos-1,R=n;
    while(R-L>1){
        int mid=(L+R)>>1;
        int X=x - (preX[n]-(preX[mid]-preX[pos-1])),Y=y - (preY[n]-(preY[mid]-preY[pos-1]));
        //printf("mid=%d, %d -(%d-%d)\n", mid,preY[n],preY[mid],preY[pos-1]);
        if(abs(X)+abs(Y)<=mid-pos+1) R=mid;
        else L=mid;
    }
    int X=x-(preX[n]-(preX[R]-preX[pos-1])),Y=y-(preY[n]-(preY[R]-preY[pos-1]));
    if(abs(X)+abs(Y)==R-pos+1)
        return R-pos+1;
    return INF;
}
int main() {
    scanf("%d%s%d%d",&n,s+1,&x,&y);
    for(int i=1;i<=n;i++){
        preX[i]=preX[i-1], preY[i]=preY[i-1];
        if(s[i]=='L')preX[i]=preX[i-1]-1;
        if(s[i]=='R')preX[i]=preX[i-1]+1;
        if(s[i]=='U')preY[i]=preY[i-1]+1;
        if(s[i]=='D')preY[i]=preY[i-1]-1;
    }
    if(preX[n]==x && preY[n]==y) return !printf("0\n");
    //solve(5); return 0;
    int ans=INF;
    for(int i=1;i<=n;i++){
        ans=min(ans,solve(i));
    }
    if(ans==INF)ans=-1;
    cout<<ans<<endl;
}