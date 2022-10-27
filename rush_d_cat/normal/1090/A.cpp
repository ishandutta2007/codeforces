#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n;
int sz[N],mx[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&sz[i]);
        int x=0;
        for(int j=1;j<=sz[i];j++){
            int s;scanf("%d",&s);x=max(x,s);
        }
        mx[i]=x;
    }
    int k=*max_element(mx+1,mx+1+n);
    LL ans=0;
    for(int i=1;i<=n;i++){
        //printf("mx=%d, sz=%d\n", mx[i],sz[i]);
        ans += 1LL * sz[i] * (k - mx[i]);
    }
    cout<<ans<<endl;
}