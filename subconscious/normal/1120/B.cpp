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
char s[N];
int a[N],b[N],p[N],n;
set<int>AMD;
bool check(int x){
    if(p[x]>0){
        return a[x]!=0&&a[x+1]!=9&&(x!=1||a[x]!=1);
    }else if(p[x]<0){
        return a[x]!=9&&a[x+1]!=0;
    }
    else return 0;
}
void mt(int x){
    if(x<1)return;
    if(x>n-1)return;
    if(check(x))AMD.insert(x);
    else AMD.erase(x);
}
ll ans=0;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);rep(i,n)a[i]=s[i]-'0';
    scanf("%s",s+1);rep(i,n)b[i]=s[i]-'0';
    rep(i,n)if(i%2==0)a[i]=9-a[i],b[i]=9-b[i];
    rep(i,n)p[i]=p[i-1]+a[i]-b[i];
    rep(i,n)ans+=abs(p[i]);
    if(p[n]!=0){puts("-1");return 0;}
    rep(i,n-1)if(check(i))AMD.insert(i);

    printf("%lld\n",ans);
    rep(i,min(ans,(ll)1e5)){
        int cur=*AMD.begin();
        if(p[cur]>0){
            --a[cur];++a[cur+1];--p[cur];
            mt(cur-1);mt(cur);mt(cur+1);
            printf("%d %d\n",cur,cur%2==0?1:-1);
        }else{
            ++a[cur];--a[cur+1];++p[cur];
            mt(cur-1);mt(cur);mt(cur+1);
            printf("%d %d\n",cur,cur%2==0?-1:1);
        }
    }
    return 0;
}