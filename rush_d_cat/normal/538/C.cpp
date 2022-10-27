#include <iostream>
#include <cmath>
using namespace std;
const int N=100000+10;
int n,m;int x[N],y[N];
int main(){
    scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x[i],&y[i]);
        if(i>=2) {
            if(abs(y[i]-y[i-1]) > abs(x[i]-x[i-1])) return !printf("IMPOSSIBLE\n");
            ans = max(ans, (x[i]-x[i-1] + y[i-1] + y[i]) / 2);
        }
    }
    ans=max(ans, y[m]+n-x[m]);
    ans=max(ans, y[1]+x[1]-1);
    cout<<ans<<endl;
}