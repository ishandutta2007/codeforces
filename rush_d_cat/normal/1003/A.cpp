#include <iostream>
using namespace std;
int n,c[102],x;
int main() {
    scanf("%d",&n);
    int ans=0;
    for(int i=1;i<=n;i++) {
        scanf("%d",&x); c[x]++;
        ans=max(ans,c[x]);
    }
    cout<<ans<<endl;

}