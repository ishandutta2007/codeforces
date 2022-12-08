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
#define cpy(a,x) memcpy(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,res,ans,fa[N],cnt[N];
ll a[N],now[N];
inline int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int x,int tot,int si){
	int t=tot;
	for(int j=x;j<=n;j++) t-=cnt[j];
	if(t>=res+1) return; 
	if(x==n+1){
		if(si<=1) tot--;
		gmin(res,tot);
		return ;
	}
	int tmp[N];
	cpy(tmp,fa);
	for(int i=1;i<=n;i++){
		if(x==i||now[i]%a[x]!=0||find(x)==find(i)) continue;
		fa[find(x)]=find(i);now[i]/=a[x];
		dfs(x+1,tot-cnt[x],si);
		now[i]*=a[x];cpy(fa,tmp);
	}
	dfs(x+1,tot,si+1);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ll t=a[i];
		for(ll j=2;j*j<=t;j++)
			while(t%j==0)
				t/=j,cnt[i]++;
		if(t>1) cnt[i]++;
		if(cnt[i]==1) ans--;
		fa[i]=i;ans+=cnt[i];
		now[i]=a[i];
	}
	ans+=n+1;
	res=ans;
	dfs(1,ans,0);
	printf("%d\n",res);
	return 0;
}