#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int N = 500000 + 10;
int par[N],sz[N],a[N];
int find(int x){
    return par[x]==x?x:par[x]=find(par[x]);
}
int n,m;

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        par[i]=i,sz[i]=1;
    }
    for(int i=1;i<=m;i++){
        int k; scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d",&a[j]);
        }
        for(int j=2;j<=k;j++){
            if(find(a[j-1]) != find(a[j])) {
                sz[find(a[j])] += sz[find(a[j-1])];
                par[find(a[j-1])] = find(a[j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d ", sz[find(i)]);
    }
}