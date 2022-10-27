#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100000+10;
typedef long long LL;
int n,a[N],mu[N],c[N];
int stk[N],top;
vector<LL> divs[N],vec[N];
bool cmp(LL x, LL y) {
    return x>y;
}
LL gcd(LL x, LL y){
    return y==0?x:gcd(y,x%y);
}
LL lcm(LL x, LL y){
    return x*y/gcd(x,y);
}
LL solve(vector<LL> vec){
    sort(vec.begin(),vec.end(),cmp);

    top=0;
    LL ans=0;
    for(auto x: vec) {
        int sum=0;
        for(auto y: divs[x]) {
            sum+=c[y]*mu[y];
           // printf("y=%d, c=%d, mu=%d\n", y,c[y],mu[y]);
        }
       // printf("sum=%d\n", sum);
        while(sum && top>=1){
            for(auto y: divs[stk[top]]){
                if(x%y==0) sum-=mu[y]; 
                --c[y];
            }
            ans=max(ans,lcm(x,stk[top]));
            -- top;
        }
        stk[++top]=x;ans=max(ans,lcm(x,stk[top]));
        //printf("add %d\n", x);
        for(auto y: divs[x]) c[y]++;
    }
    //printf("%lld\n", ans);
    return ans;
}
int main() {
    mu[1]=1;for(int i=1;i<N;i++)for(int j=i+i;j<N;j+=i)mu[j]-=mu[i];
    for(int i=1;i<N;i++)if(mu[i])for(int j=i;j<N;j+=i)divs[j].push_back(i);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(auto x: divs[a[i]]) {
            vec[x].push_back(a[i]/x);
        }
    }

    LL ans=0;
    for(int i=1;i<N;i++)ans=max(ans,solve(vec[i])*i);
    cout<<ans<<endl;
}