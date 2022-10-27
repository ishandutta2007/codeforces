#include <iostream>
using namespace std;
int n,x[5],y[5];

int main() {
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i];
    if(n==1) return !printf("-1\n");
    int mnx=1002,mxx=-1002;
    int mny=1002,mxy=-1002;
    for(int i=1;i<=n;i++) {
        mnx=min(mnx,x[i]); mxx=max(mxx,x[i]);
        mny=min(mny,y[i]); mxy=max(mxy,y[i]);
    }
    int ans=(mxx-mnx)*(mxy-mny);
    printf("%d\n", ans==0?-1:ans);
}