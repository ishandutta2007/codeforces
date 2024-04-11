#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline int read(){
    char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,a,vis[N],now,ans;
int main(){
    //freopen("in","r",stdin);
    n=read()<<1;
    for(int i=1;i<=n;i++){
        a=read();
        if(!vis[a]) now++,vis[a]=1;
        else now--;
        ans=max(ans,now);
    }
    printf("%d",ans);
}