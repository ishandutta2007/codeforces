#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
using namespace std;

#define M 200001

int f[M],n,m,ans[M],x,id[M],g[M],b[M];

bool cmp(int a,int b) {
    if(f[a]!=f[b]) return f[a]<f[b];
    return a<b;
}

int main() {
    ///freopen("1.in","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) scanf("%d",&f[i]);
    for(int i=0;i<n;i++) id[i] = i;
    sort(id,id+n,cmp);
    for(int i=0;i<n;i++) g[i] = f[id[i]];
    for(int i=1;i<=m;i++) {
        scanf("%d",&b[i]);
        int a = lower_bound(g,g+n,b[i]) - g;
        if(g[a]!=b[i]) {return puts("Impossible");}
        ///if(a+1<n&&g[a+1]==x) {return puts("Ambiguity");}
        ans[i] = id[a];
    }
    for(int i=1;i<=m;i++) {
        ///scanf("%d",&x);
        int a = lower_bound(g,g+n,b[i]) - g;
        ///if(g[a]!=x) {return puts("Impossible");}
        if(a+1<n&&g[a+1]==b[i]) {return puts("Ambiguity");}
        ans[i] = id[a];
    }

    puts("Possible");
    for(int i=1;i<=m;i++) printf("%d ",ans[i] + 1);puts("");
}