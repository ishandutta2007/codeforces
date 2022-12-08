#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls k<<1
#define rs k<<1|1
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#define nowtime cerr<<"time:"<<(ll)clock()*1000/CLOCKS_PER_SEC<<"ms"<<endl
#define fore(i,x,y) for(int i=head[(x)];i!=(y);i=p[i].next)
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define per(i,x,y) for(int i=(x);i>=(y);i--)
#define REP(i,x,y) for(int i=(x);i<(y);i++)
#define PER(i,x,y) for(int i=(x);i>(y);i--)
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int N=200005,mod=1e9+7;
struct node{
	int x,y;
}p[N];
int n,m,k,s,f[N],g[N],a[N],tot;
int dp[N][25],ans;
inline void ch(int &x,int y){
	x+=y;
	if(x>=mod) x-=mod;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}
	return ans;
}
inline int C(int x,int y){
	if(x<y) return 0;
	return (ll)f[x]*g[y]%mod*g[x-y]%mod;
}
inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&m,&k,&s);
	p[1]=(node){1,1};k++;
	rep(i,2,k) scanf("%d%d",&p[i].x,&p[i].y);
	p[++k]=(node){n,m};
	sort(p+1,p+k+1,cmp);
	while(s!=1) a[tot++]=s,s=(s+1)/2;
	a[tot]=s;a[++tot]=s;
	f[0]=1;
	rep(i,1,n+m) f[i]=(ll)f[i-1]*i%mod;
	g[n+m]=exp(f[m+n],mod-2);
	per(i,n+m-1,0) g[i]=(ll)g[i+1]*(i+1)%mod;
//	printf("%d\n",C(0,0));
	dp[1][0]=1;
	rep(i,2,k){
		REP(j,1,i){
//			printf("%d %d\n",j,i);
			if(p[j].y>p[i].y) continue;
			int si=C(p[i].x-p[j].x+p[i].y-p[j].y,p[i].x-p[j].x);
			if(i==k){
				rep(t,0,tot) ch(dp[i][t],(ll)dp[j][t]*si%mod);
				continue;
			}
			rep(t,1,tot) ch(dp[i][t],(ll)dp[j][t-1]*si%mod);
//			ch(dp[i][tot],(ll)dp[j][tot]*si%mod);
		}
//		rep(j,0,tot) printf("%d ",dp[i][j]);puts("");
		if(i==k) per(l,tot,0) PER(r,tot,l) ch(dp[i][l],mod-dp[i][r]);
		else per(l,tot,1) PER(r,tot,l) ch(dp[i][l],mod-dp[i][r]);
//		dp[i][tot]=C(p[i].x+p[i].y-2,p[i].y-1);
//		REP(l,0,tot) ch(dp[i][tot],dp[i][l]);
//		rep(j,0,tot) printf("%d ",dp[i][j]);puts("");
	}
	rep(i,0,tot)
		ch(ans,(ll)dp[k][i]*a[i]%mod);
//	puts("");
	ans=(ll)ans*exp(C(n+m-2,n-1),mod-2)%mod;
	printf("%d\n",ans);
	return 0;
}