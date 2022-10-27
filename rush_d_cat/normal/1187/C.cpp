#include <iostream>
#include <vector>
using namespace std;
const int N=1000+10;
typedef long long LL;
int n,m,a[N],t[N],l[N],r[N];
bool vis[N];
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&t[i],&l[i],&r[i]);
        if(t[i]==1) for(int j=l[i];j<r[i];j++) vis[j]=1;
    }
    a[1]=n;
    for(int i=1;i<n;i++){
        if(vis[i]==0) a[i+1]=a[i]-1;
        else  a[i+1]=a[i];
    }
    for(int i=1;i<=m;i++){
        if(t[i]==0){
            bool ok=0;
            for(int j=l[i];j<r[i];j++)if(vis[j]==0)ok=1;
            if(!ok) return !printf("NO\n");
        }
    }
    printf("YES\n");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
}