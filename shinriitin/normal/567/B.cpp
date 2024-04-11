#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXN 1000005
using namespace std;

int n,a[MAXN],ans;

bool vis[MAXN];

int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;++i){
        char c;
        while(c=getchar(),c!='+'&&c!='-');
        scanf("%d",&x);
        if(c=='+'){
            a[i]=1;
            vis[x]=1;
        }
        else{
            a[i]=-1;
            if(!vis[x])++a[0];
            vis[x]=0;
        }
    }
    for(int i=0;i<=n;++i){
        if(i)a[i]+=a[i-1];
        ans=max(a[i],ans);
    }
    printf("%d\n",ans);
    return 0;
}