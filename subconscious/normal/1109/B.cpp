#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fxaa
#define y0 fxbb
#define x1 fxcc
#define y1 fxdd
#define st first
#define nd second
#define eb emplace_back
using namespace std;
using ll=long long;
using ld=long double;
constexpr int N=2e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
char s[N],t[N];int n;
bool check(){
    bool f=0;
    rep(i,n)if(s[i]!=t[i])f=1;
    if(!f)return 0;
    rep(i,n/2)if(t[i]!=t[n-i+1])return 0;
    return 1;
}
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    bool f=0;
    rep(i,n/2-1)if(s[i]!=s[i+1])f=1;
    if(!f){puts("Impossible");return 0;}
    for(int i=2;i<=n;++i){
        int tmp=0;
        for(int j=i;j<=n;++j)t[++tmp]=s[j];
        rep(j,i-1)t[++tmp]=s[j];
        if(check()){puts("1");return 0;}
    }
    puts("2");
    return 0;
}