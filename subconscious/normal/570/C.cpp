#include <algorithm>
#include <cstdio>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 300005
using namespace std;
char s[N],c[2];
int n,m,ans=0;
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);int x,t;
    rep(i,n-1)if(s[i]=='.'&&s[i+1]=='.')++ans;
    rep(i,m){
        scanf("%d%s",&x,c);
        if(x>1&&s[x]=='.'&&s[x-1]=='.')--ans;
        if(x<n&&s[x]=='.'&&s[x+1]=='.')--ans;
        s[x]=c[0];
        if(x>1&&s[x]=='.'&&s[x-1]=='.')++ans;
        if(x<n&&s[x]=='.'&&s[x+1]=='.')++ans;
        printf("%d\n",ans);
    }
    return 0;
}