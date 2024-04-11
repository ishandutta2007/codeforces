#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
const int N=100000+10;
map< pair<int,int>, int > mp;
int n,m,a[N],b[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u,v; scanf("%d%d",&u,&v);
        mp[make_pair(u,v)]=mp[make_pair(v,u)]=1;
    }
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
        if(mp[make_pair(i,j)] == 0 && mp[make_pair(j,i)] == 0) {
            printf("YES\n");
            int tot=0;
            for(int x=1;x<=i;x++)a[x]=++tot; a[j]=++tot;
            for(int x=i+1;x<j;x++)a[x]=++tot;
            for(int x=j+1;x<=n;x++)a[x]=++tot;
            for(int x=1;x<=n;x++)b[x]=a[x];
            b[j]=b[i];
            for(int x=1;x<=n;x++)printf("%d ", a[x]);printf("\n");
            for(int x=1;x<=n;x++)printf("%d ", b[x]);printf("\n");
            return 0;
        }
    }
    printf("NO\n");
}