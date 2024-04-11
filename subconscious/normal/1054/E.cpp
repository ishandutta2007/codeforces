#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fuckjsb
#define y1 fuckjtjl
#define mp make_pair
#define fr first
#define sc second
#define pb push
#define pf pop
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pr;
const int N=1e5+5,inf=0x3f3f3f3f,MOD=1e9+7;
char s[N];
int len[305][305],len2[305][305],cur[305][305],n,m;
queue<bool>a[305][305];
string ed[305][305];
pair<pr,pr> ans[N*4],tp[N*4];int top;
void mv(int p,int q,int r,int s){
    ans[++top]=mp(mp(p,q),mp(r,s));
    a[r][s].pb(a[p][q].front());
    a[p][q].pf();
}
void sol(int typ){
    rep(i,n)rep(j,m)while(!a[i][j].empty())a[i][j].pf();
    int cnt0=0,cnt1=0;
    rep(i,n)rep(j,m){
        scanf("%s",s+1);len[i][j]=strlen(s+1);len2[i][j]=0;//printf("%d %d %s\n",i,j,s+1);
        if(typ==0)
        for(int k=len[i][j];k;--k)a[i][j].pb(s[k]=='1'),cnt1+=s[k]=='1',cnt0+=s[k]=='0';
        else 
        for(int k=1;k<=len[i][j];++k)a[i][j].pb(s[k]=='1'),cnt1+=s[k]=='1',cnt0+=s[k]=='0';
    }
    rep(i,len[n][1])if(a[n][1].front())
        mv(n,1,n,m);
    else mv(n,1,1,1),++len2[1][1];
    len[n][1]=0;

    rep(i,len[n][m])if(a[n][m].front())
        mv(n,m,1,m),++len2[1][m];
    else mv(n,m,n,1);
    len[n][m]=0;
    rep(i,n)for(int j=2;j<=m-1;++j)rep(k,len[i][j])
        if(a[i][j].front())mv(i,j,i,m),++len2[i][m];else mv(i,j,i,1),++len2[i][1];
    rep(i,n-1){
        rep(k,len[i][1])if(a[i][1].front())mv(i,1,i,m),++len2[i][m];
        else mv(i,1,n,1);
        rep(k,len[i][m])if(!a[i][m].front())mv(i,m,i,1),++len2[i][1];
        else mv(i,m,n,m);
        rep(k,len2[i][1])mv(i,1,n,1);
        rep(k,len2[i][m])mv(i,m,n,m);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    top=0;
    sol(0);
    int ts=top;
    top=0;memcpy(tp,ans,sizeof tp);
    sol(1);
    printf("%d\n",ts+top);
    rep(i,ts)printf("%d %d %d %d\n",tp[i].fr.fr,tp[i].fr.sc,tp[i].sc.fr,tp[i].sc.sc);
    //rep(i,top)printf("%d %d %d %d\n",ans[i].fr.fr,ans[i].fr.sc,ans[i].sc.fr,ans[i].sc.sc);
    for(int i=top;i;--i)printf("%d %d %d %d\n",ans[i].sc.fr,ans[i].sc.sc,ans[i].fr.fr,ans[i].fr.sc);
    return 0;
}