#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
int n,a[100002],suf[100002],vis[100002];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    set<int> st;
    for(int i=n;i>=1;i--){
        st.insert(a[i]);
        suf[i]=st.size();
    }
    LL ans=0;
    for(int i=1;i<=n;i++){
        if(vis[a[i]]==0){
            ans+=suf[i+1];
            vis[a[i]]=1;
        }
    }
    cout<<ans<<endl;
}