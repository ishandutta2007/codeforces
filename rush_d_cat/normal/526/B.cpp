#include <iostream>
using namespace std;
const int N=100000+10;
int n,a[N],len[N];
int ans;
void solve(int u){
    if(u<=(1<<n)-1) {
        solve(u<<1);
        solve(u<<1|1);
        ans += max(len[u<<1]+a[u<<1],len[u<<1|1]+a[u<<1|1]) - min(len[u<<1]+a[u<<1],len[u<<1|1]+a[u<<1|1]);
        len[u] = max(len[u<<1]+a[u<<1],len[u<<1|1]+a[u<<1|1]);
        //printf("len[%d] = %d\n", u,len[u]);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=(1<<(n+1)) - 1;i++)
        scanf("%d",&a[i]);
    solve(1);
    cout<<ans<<endl;
}