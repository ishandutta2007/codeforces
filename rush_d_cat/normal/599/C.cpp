#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;

const int N=100000+10;
const int MOD=1000000007;
int n,h[N],a[N];

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d",&h[i]);
        a[i]=h[i];
    }
    sort(a+1,a+1+n); 
    int ans=0;
    LL ans1=0,ans2=0; LL p=1;
    for(int i=1;i<=n;i++){
        ans1=(ans1+a[i])%MOD;
        ans2=(ans2+h[i])%MOD; 
        if(ans1==ans2) ans++;
    }
    cout<<ans<<endl;
}