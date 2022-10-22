#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
int n,x,y,sum[MAXN+5][2];
char s[MAXN+5];
int pos[MAXN+5],pp=0;
signed main(){
	scanf("%s%d%d",s+1,&x,&y);n=strlen(s+1);
	for(int i=1;i<=n;i++){
		sum[i][0]=sum[i-1][0];sum[i][1]=sum[i-1][1];
		if(s[i]=='1') sum[i][1]++;
		if(s[i]=='0') sum[i][0]++;
	}
	ll ss=0;
	for(int i=1;i<=n;i++) if(s[i]=='?') pos[++pp]=i;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			ss+=1ll*x*sum[i][0];
		} else if(s[i]=='0') {
			ss+=1ll*y*sum[i][1];
		}
	}
	ll tt=0;
	for(int i=1;i<=pp;i++){
		tt+=1ll*sum[pos[i]][0]*x;
		tt+=1ll*(sum[n][0]-sum[pos[i]][0])*y;
	}
	ll ans=1e18;
	ans=min(ans,ss+tt);
	for(int i=1;i<=pp;i++){
		tt-=1ll*x*(i-1)*(pp-(i-1));
		tt+=1ll*x*i*(pp-i);
		tt-=1ll*sum[pos[i]][0]*x;
		tt-=1ll*(sum[n][0]-sum[pos[i]][0])*y;
		tt+=1ll*sum[pos[i]][1]*y;
		tt+=1ll*(sum[n][1]-sum[pos[i]][1])*x;
		ans=min(ans,ss+tt);
	}
	tt=0;
	for(int i=1;i<=pp;i++){
		tt+=1ll*sum[pos[i]][1]*y;
		tt+=1ll*(sum[n][1]-sum[pos[i]][1])*x;
	}
	ans=min(ans,ss+tt);
	for(int i=1;i<=pp;i++){
		tt-=1ll*y*(i-1)*(pp-(i-1));
		tt+=1ll*y*i*(pp-i);
		tt-=1ll*sum[pos[i]][1]*y;
		tt-=1ll*(sum[n][1]-sum[pos[i]][1])*x;
		tt+=1ll*sum[pos[i]][0]*x;
		tt+=1ll*(sum[n][0]-sum[pos[i]][0])*y;
		ans=min(ans,ss+tt);
	}
	printf("%lld\n",ans);
	return 0;
}