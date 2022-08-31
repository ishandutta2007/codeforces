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
constexpr int N=5e6+5,mod=1e9+7;
constexpr ld eps=1e-9,inf=1e50;
struct node{
    int s[2],tim,ans,fa,is;
}a[N];
int m,tot;
char s[3005];
int ret[3005];
int main(){
    tot=1;a[1].tim=0;a[1].ans=1;a[1].fa=0;a[1].is=0;
    scanf("%d",&m);
    rep(i,m){
        int x;
        scanf("%d",&x),s[i]=(x==1?'1':'0');
    }
    rep(i,m){
        int cur=1;
        for(int j=i;j<=m;++j){
            if(a[cur].s[s[j]-'0']==0){
                a[cur].s[s[j]-'0']=++tot;
                a[tot].tim=j;
                a[tot].fa=cur;
                a[tot].is=s[j]-'0';
                a[tot].ans=0;
                int tmp=a[tot].is,pos=cur;
                rep(k,4){
                    if(k==4&&(tmp==15||tmp==7||tmp==10||tmp==12))break;
                    (a[tot].ans+=a[pos].ans)%=mod;
                    if(k==4)break;
                    if(cur==1)break;
                    tmp=tmp<<1|a[pos].is;
                    pos=a[pos].fa;
                }
                (ret[a[tot].tim]+=a[tot].ans)%=mod;
            }
            cur=a[cur].s[s[j]-'0'];
        }
    }
    rep(i,m)(ret[i]+=ret[i-1])%=mod;
    rep(i,m)printf("%d\n",ret[i]);
    return 0;
}