#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const ll Inf=0x3f3f3f3f3f3f3f3fll;
int exgcd(int a,int b,int &x,int &y){
	if(b==0){
		x=1,y=0;
		return a;
	}
	int t=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return t;
}
int n,m,D,G,B;
vector<int> g[Maxn+5],b[Maxn+5];
ll ans;
int s[Maxn+5],d[Maxn+5],p[Maxn+5],cnt;
bool cmp(int p,int q){
	if(s[p]==s[q]){
		return p>q;
	}
	return s[p]<s[q];
}
ll check(int m,int n,int x,vector<int> &gv,vector<int> &bv){
	if((int)gv.size()==m){
		return -1;
	}
	cnt=0;
	for(int i=0;i<(int)gv.size();i++){
		cnt++;
		s[cnt]=1ll*gv[i]*x%m;
		d[cnt]=gv[i];
		p[cnt]=cnt;
	}
	for(int i=0;i<(int)bv.size();i++){
		cnt++;
		s[cnt]=1ll*bv[i]*x%m;
		d[cnt]=bv[i];
		p[cnt]=cnt;
	}
	sort(p+1,p+1+cnt,cmp);
	s[p[0]=0]=s[p[cnt]]-m;
	s[p[cnt+1]=cnt+1]=s[p[1]]+m;
	ll dis=Inf,ans=0;
	for(int i=1;i<=cnt;i++){
		dis=min(dis+1ll*n*(s[p[i]]-s[p[i-1]]),1ll*d[p[i]]);
	}
	for(int i=1;i<=cnt;i++){
		dis=min(dis+1ll*n*(s[p[i]]-s[p[i-1]]),1ll*d[p[i]]);
		if(s[p[i]]==s[p[i+1]]){
			continue;
		}
		if(s[p[i]]+1==s[p[i+1]]&&p[i]<=(int)gv.size()){
			continue;
		}
		ans=max(ans,dis+1ll*n*(s[p[i+1]]-s[p[i]]-1));
	}
	return ans;
}
int main(){
	int x,y;
	scanf("%d%d",&n,&m);
	D=exgcd(m,n,x,y);
	if(D>200000){
		puts("-1");
		return 0;
	}
	int tmp;
	scanf("%d",&B);
	for(int i=0;i<B;i++){
		scanf("%d",&tmp);
		b[tmp%D].push_back(tmp/D);
	}
	scanf("%d",&G);
	for(int i=0;i<G;i++){
		scanf("%d",&tmp);
		g[tmp%D].push_back(tmp/D);
	}
	x=(x+n)%n;
	y=(y+m)%m;
	for(int i=0;i<D;i++){
		if(g[i].empty()&&b[i].empty()){
			puts("-1");
			return 0;
		}
		ans=max(ans,check(m/D,n/D,y,g[i],b[i])*D+i);
		ans=max(ans,check(n/D,m/D,x,b[i],g[i])*D+i);
	}
	printf("%lld\n",ans);
	return 0;
}