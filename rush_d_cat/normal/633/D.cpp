#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N=1002;

int n; LL a[N],f[N];
int ans=2;
map<int,int> mp,bu;
set< pair<int,int> > st;

void solve(int i,int j){
    bu.clear();
    bu[a[i]]++, bu[a[j]]++; int res=2;
    f[1]=a[i],f[2]=a[j];
    for(int i=3;i<=n;i++){
        f[i]=f[i-1]+f[i-2]; bu[f[i]]++;
        if(f[i]>=1e12) break;
        if(bu[f[i]]>mp[f[i]])break;
        res++;
    }
    ans=max(res,ans);
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]); mp[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(st.count(make_pair(a[i],a[j]))) continue;
            st.insert(make_pair(a[i],a[j]));
            solve(i,j);
        }
    }
    cout<<ans<<endl;
}