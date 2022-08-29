#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=1e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
char s[N],t[N],ans[N];
int c[2],u[2];
int kmp[N],len;
void fl(){
    while(c[0]--)ans[++len]='0';
    while(c[1]--)ans[++len]='1';
    puts(ans+1);exit(0);
}
int main(){
    len=0;
    scanf("%s",s+1);int n=strlen(s+1);
    scanf("%s",t+1);int m=strlen(t+1);
    rep(i,n)++c[s[i]-'0'];
    rep(i,m){
        int cur=kmp[i-1];
        while(cur>0&&t[i]!=t[cur+1])cur=kmp[cur];
        if(t[cur+1]==t[i]&&i!=1)kmp[i]=cur+1;else kmp[i]=0;
    }
    u[0]=u[1]=0;
    rep(i,m)++u[t[i]-'0'];
    if(c[0]<u[0]||c[1]<u[1]){
        fl();
    }else{
        rep(i,m)ans[i]=t[i],--c[ans[i]-'0'];
        len=m;
        u[0]=u[1]=0;
        for(int i=kmp[m]+1;i<=m;++i)++u[t[i]-'0'];
            //printf("%d %d\n",u[0],u[1]);
        while(c[0]>=u[0]&&c[1]>=u[1]){
            for(int i=kmp[m]+1;i<=m;++i)ans[++len]=t[i],--c[t[i]-'0'];
        }
        fl();
    }
    return 0;
}