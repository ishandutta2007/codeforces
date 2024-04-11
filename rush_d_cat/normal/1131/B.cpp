#include <iostream>
using namespace std;

const int N=10000+10;
int n,x[N],y[N];
int ans=0;
int main(){
    scanf("%d",&n);
    x[0]=0, y[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        if(max(x[i-1],y[i-1]) <= min(x[i],y[i])) {
            ans += min(x[i],y[i]) - max(x[i-1],y[i-1]) + 1;
        }
        if(x[i]==y[i]) ans --;
    }
    if(x[n]==y[n]) ans++;
    cout<<ans<<endl;
}
/*
1 3
2 4
*/