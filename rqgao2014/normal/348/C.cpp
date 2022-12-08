#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,B=400,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

vi a[N];
int n,m,q,tot,tmp[N],b[N],c[304][N],p[N];
ll sum[N],flag[N],d[N];
bool vis[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++) scanf("%d",&tmp[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		for(int j=0,x;j<b[i];j++)
			scanf("%d",&x),a[i].pb(x),sum[i]+=tmp[x];
		if(b[i]>B) p[++tot]=i;
//		debug(sum[i]);
	}
	for(int i=1;i<=tot;i++){
		int k=p[i];
		for(int j=0;j<b[k];j++) vis[a[k][j]]=1;
		for(int j=1;j<=m;j++)
			for(int k=0;k<b[j];k++)
				c[i][j]+=vis[a[j][k]];
		for(int j=0;j<b[k];j++) vis[a[k][j]]=0;
	}
	while(q--){
		char tmp[10];int x,y;
		scanf("%s%d",tmp,&x);
		if(tmp[0]=='+'){
			scanf("%d",&y);
			if(b[x]<=B){
				for(int i=0;i<b[x];i++)
					d[a[x][i]]+=y;
			}else flag[x]+=y;
			for(int i=1;i<=tot;i++)
				sum[p[i]]+=(ll)y*c[i][x];
		}
		else{
			ll ans=sum[x];
			if(b[x]<=B){
				for(int i=0;i<b[x];i++)
					ans+=d[a[x][i]];
				for(int i=1;i<=tot;i++) 
					ans+=flag[p[i]]*c[i][x];
			}printf("%I64d\n",ans);
		}
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}