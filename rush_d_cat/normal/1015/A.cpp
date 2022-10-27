#include <iostream>
#include <vector>
using namespace std;
int n,m;
int l,r,vis[1002];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&l,&r);
        for(int x=l;x<=r;x++) vis[x]=1;
    }
    vector<int> ans;
    for(int i=1;i<=m;i++) if(vis[i]==0) ans.push_back(i);
    printf("%d\n", ans.size());
    for(auto x:ans) printf("%d ",x);
}