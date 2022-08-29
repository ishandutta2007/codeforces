#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
typedef long long ll;
const double eps=1e-9;
const int N=2e5+5;
char s[N],t[N];
int f[N],b[N],n,m;
int main(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    int pos=1;f[0]=0;
    rep(i,m){
        while(s[pos]!=t[i])++pos;
        f[i]=pos;
        ++pos;
    }
    pos=n;b[m+1]=n+1;
    for(int i=m;i;--i){
        while(s[pos]!=t[i])--pos;
        b[i]=pos;
        --pos;
    }
    int ans=0;
    for(int i=0;i<=m;++i)ans=max(ans,b[i+1]-f[i]-1);
    printf("%d\n",ans);
    return 0;
}