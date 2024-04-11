#include <iostream>
#include <map>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,q,x,a[N];
map<int,LL> mp[N],ans;
int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(int i=1;i<=n;i++){
        mp[i][a[i]] ++;
        for(auto p: mp[i-1]) {
            mp[i][gcd(a[i],p.first)] += p.second; 
        }
        for(auto p: mp[i]) {
            ans[p.first] += p.second;
        }
    }   

    scanf("%d",&q);
    while(q--){
        scanf("%d",&x);
        printf("%lld\n", ans[x]);
    }
}