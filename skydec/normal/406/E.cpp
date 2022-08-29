#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define pii pair<int,int>
#define se second
#define fi first
#define VI vector<int>
#define rep(i,j,k) for(int i=j;i<=(int)k;i++)
#define per(i,j,k) for(int i=j;i>=(int)k;i--)
using namespace std;
int m;const int N=110000;int dp;
typedef long long LL;
pii a[N];VI w[2];int e[N];int c[N];
int ans=-1;LL size;
void relax(int x,LL rp){
	if(rp<=0)return;
	if(x==ans)size+=rp;
	else if(x>ans){ans=x;size=rp;}
}
int sum[N];
void work000(int u){
	int n=w[u].size();if(n<3)return;
	rep(i,1,n)e[i]=w[u][i-1];
	if(e[1]==e[n]){
		relax(0,n*1ll*(n-1)*1ll*(n-2)/6);return;
	}
	int f=1;int g=n;
	while(f<n&&e[f+1]==e[1])f++;
	while(g>1&&e[g-1]==e[n])g--;
	int pa=2*(e[n]-e[1]);
	g=n-g+1;LL s1=n*1ll*f*g;
	s1-=f*1ll*(g+1)*1ll*g/2;
	s1-=g*1ll*(f+1)*1ll*f/2;
	relax(pa,s1);
}
void work001(int u){
	int n=dp;
	rep(i,1,n){e[i]=a[i].fi;c[i]=a[i].se;}
	rep(i,1,n){sum[i]=(c[i]==u)+sum[i-1];}
	int dis=-m;LL rp=0;
	int x=-1;LL y=0;
	rep(i,1,n)if(c[i]==u){
		if(e[i]==dis)rp+=sum[i-1]*1ll;
		else {dis=e[i];rp=sum[i-1];}
	}
	else if(rp){
		int diu=2*(m-(e[i]-dis));
		if(diu>x){
			x=diu;y=rp;
		}
		else if(diu==x)y+=rp;
	}
	relax(x,y);
}
void work010(int u){
	int n=dp;
	LL gt=0;rep(i,1,n)e[i]=a[i].fi,c[i]=a[i].se;
	LL an=0;
	rep(i,1,n){sum[i]=sum[i-1]+(c[i]==u);}
	rep(i,1,n)if(c[i]==u)an+=gt;
	else gt+=sum[i-1]*1ll;
	if(an)relax(2*m,an);
}
void work011(int u){
	int n=dp;
	rep(i,1,n/2)swap(a[i],a[n-i+1]);
	rep(i,1,n){a[i].se^=1;a[i].fi=m-a[i].fi;}
	work001(u^1);
	rep(i,1,n/2)swap(a[i],a[n-i+1]);
	rep(i,1,n){a[i].se^=1;a[i].fi=m-a[i].fi;}
}
int n;
int main(){
	scanf("%d%d",&m,&n);dp=n;
	rep(i,1,n){
		scanf("%d%d",&a[i].se,&a[i].fi);
		w[a[i].se].push_back(a[i].fi);
	}
	rep(u,0,1)sort(w[u].begin(),w[u].end());
	sort(a+1,a+1+n);
	rep(u,0,1){
		work000(u);
		work001(u);
		work010(u);
		work011(u);
	}
	printf("%I64d\n",size);
	return 0;
}