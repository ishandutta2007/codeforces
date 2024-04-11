#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N=200000+10;
typedef long long LL;
map<int,int> mp,now;
int n,m,x[N],y[N];

int solve(int dep,int pos,int len,int dir){
    //printf("pos=%d,len=%d,dir=%d\n", pos,len,dir);
    if(dep>=100) return pos;
    int tmp=len;
    if(dir==+1) {
        int nex=upper_bound(x+1,x+1+n, x[pos]+len) - x - 1;
        if(2*(x[nex]-x[pos]) > len) return solve(dep+1,nex,len-(x[nex]-x[pos]),-1);
        int pre=lower_bound(x+1,x+1+n, x[pos]-(len - 2*(x[nex]-x[pos]))) - x;
        //printf("[%d,%d]\n", pre,nex);
        len -= (x[nex]-x[pos]); if(x[nex]-x[pre]>0) len %= 2*(x[nex]-x[pre]);
        return solve(dep+1,nex,len,-1);
    }
    if(dir==-1) {
        int pre=lower_bound(x+1,x+1+n,x[pos]-len)-x;
        if(2*(x[pos]-x[pre]) > len) return solve(dep+1,pre,len-(x[pos]-x[pre]),+1);
        int nex=upper_bound(x+1,x+1+n, x[pos]+(len - 2*(x[pos]-x[pre]))) - x - 1;
        len -= (x[pos]-x[pre]); if(x[nex]-x[pre]>0) len %= 2*(x[nex]-x[pre]);
        return solve(dep+1,pre,len,+1);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&x[i]); mp[x[i]]=i; y[i]=x[i];
    }
    sort(x+1,x+1+n);
    for(int i=1;i<=n;i++) now[x[i]]=i;
    for(int i=1;i<=m;i++) {
        int pos,len; 
        scanf("%d%d",&pos,&len); 
        pos=now[y[pos]];
        printf("%d\n", mp[x[solve(0,pos,len,1)]]);
    }

}