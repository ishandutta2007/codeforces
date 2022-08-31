#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define rev(i,n) for(int i=n;i;--i)
#define x0 fuck
#define y0 fuxk
#define y1 fxck
#define x1 fxxk
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e6+5,inf=0x3f3f3f3f,MOD=998244353;
const ld eps=1e-9;
int a[N],b[N*3],n;char s[N];
int main(){
    scanf("%d",&n);int top=0;bool f0,f1;
    rep(i,n){
        scanf("%s",s+1);int l=strlen(s+1);
        f0=f1=0;int x=0;
        rep(j,l){
            if(s[j]=='(')++x;else--x;
        }
        if(x<0){
            reverse(s+1,s+l+1);
            rep(j,l)s[j]=(s[j]=='(')?')':'(';
            f1=1;
        }
        x=0;
        rep(j,l){
            if(s[j]=='(')++x;else--x;
            if(x<0)f0=1;
        }
        if(!f0)a[++top]=x*(f1?-1:1);
    }
    //rep(i,top)printf("%d ",a[i]);
    rep(i,top)++b[a[i]+N];
    int ans=0;
    for(int i=-N;i<0;++i){
        //if(b[i+N]>0||b[N-i]>0)printf("%d\n",i);
        ans+=min(b[i+N],b[N-i]);
    }
    ans+=b[N]/2;
    printf("%d\n",ans);
}