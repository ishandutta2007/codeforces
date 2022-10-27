#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int N=100000+10;
int n,m,x,y;
int a[N],b[N],vis[N];
vector< pair<int,int> > ans;
int main() {
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int l=1,r=1;l<=n;l++) {
        while(r<=m && (b[r]<a[l]-x||vis[r]==1)) r++;
        //printf("%d %d\n", l,r);
        if(r>m) break;
        if(b[r]<=a[l]+y && vis[r]==0) {
            vis[r] = 1;
            ans.push_back(make_pair(l,r));
        }   
    }
    printf("%d\n", ans.size());
    for(auto p:ans)
        printf("%d %d\n", p.first,p.second);
}