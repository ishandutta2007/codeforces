#include <iostream>
using namespace std;
const int N=202;
int n,a[N],vis[N],ans;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
        scanf("%d",&a[i]);

    for(int i=1;i<=2*n;i+=2) {
        int pos=-1;
        for(int j=i+1;j<=2*n;j++){
            if(a[j]==a[i]) {
                pos=j;
            }
        }
        for(int j=pos;j>=i+2;j--) swap(a[j],a[j-1]), ans++;
    }
    cout<<ans<<endl;
}