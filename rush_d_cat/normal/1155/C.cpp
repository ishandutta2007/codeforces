#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N=300000+10;
typedef long long LL;
LL gcd(LL x,LL y){
    return y==0?x:gcd(y,x%y);
}
int n,m;
LL x[N],p[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
    for(int i=1;i<=m;i++)scanf("%lld",&p[i]);
    LL g=0;
    for(int i=2;i<=n;i++){
        g=gcd(g,x[i]-x[i-1]);
    }
    for(int i=1;i<=m;i++){
        if(g%p[i]==0){
            return !printf("YES\n%lld %d\n", x[1],i);
        }
    }
    return !printf("NO\n");
}