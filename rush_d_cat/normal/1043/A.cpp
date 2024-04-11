#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int N=200000+10;
int n,a[N];
int main(){
    scanf("%d",&n); int sum=0,mx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]); sum+=a[i];
        mx = max(mx,a[i]);
    }
    sum=2*sum+1;
    int ans=sum/n; 
    if(sum%n) ans++;
    ans=max(ans,mx);
    cout<<ans<<endl;
}