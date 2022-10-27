#include <iostream>

using namespace std;
const int N=100000+10;
int n,M;
int a[N], pre[N];

int main() {
    scanf("%d%d",&n,&M);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    a[++n] = M;
    for(int i=1;i<=n;i++) {
        if(i%2==1)
            pre[i]=pre[i-1]+a[i]-a[i-1];
        else
            pre[i]=pre[i-1];
    }

    int ans=pre[n];
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++) {
        int tmp;
        if(i%2==1) {
            // a[i]-1
            tmp=(pre[i]-1) + (M-a[i])-(pre[n]-pre[i]);
        } else {
            // a[i-1]+1
            tmp=pre[i-1]+(a[i]-a[i-1]-1) + (M-a[i])-(pre[n]-pre[i]);
        }
        ans = max(ans,tmp);
    }
    cout<<ans<<endl;
}