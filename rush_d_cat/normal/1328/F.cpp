#include <bits/stdc++.h>
using namespace std;
const int N=200000+10;
typedef long long LL;
int n,k,a[N]; LL s[N];
set<int> st; map<int,int> mp; 
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n+1;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++) {
        st.insert(a[i]); mp[a[i]]++;
    }

    LL ans=1e18;
    for(auto x: st) {
        int p1=upper_bound(a+1,a+1+n,x)-a;
        int c1=n-p1+1;
        LL cost1=(s[n]-s[p1-1])-1LL*c1*(x+1);
        //printf("x=%d, p1=%d,c1=%d,cost1=%lld\n", x,p1,c1,cost1);
        int p2=lower_bound(a+1,a+1+n,x)-a-1;

        int c2=p2;
        LL cost2=1LL*c2*(x-1) - s[p2];
        //printf("x=%d, p2=%d,c2=%d,cost2=%lld\n", x,p2,c2,cost2);
        int need=k-mp[x];
        //printf("need=%d\n", need);
        assert(c1+c2+mp[x]==n);
        if(need<=0){
            ans=0; break;
        }
        if(c1>=need){
            ans=min(ans,cost1+need);
        }
        if(c2>=need){
            ans=min(ans,cost2+need);
        }
        ans=min(ans,cost1+cost2+need);
        
    }
    cout<<ans<<endl;
}