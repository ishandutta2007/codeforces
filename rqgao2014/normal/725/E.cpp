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

const int N=200005,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x+=y;if(x>=mod) x-=mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,c,a[N],pre[N];
int f[N],g[N],lg[N],dp[N][20];
bool stable[N];

inline int get(int l,int r){
	int x=lg[r-l+1];
	return min(dp[r][x],dp[l+(1<<x)-1][x]);
}

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d",&c);
	scanf("%d",&n);
	for(int i=2;i<=c;i++) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		a[x]++;
	}
	for(int i=1,last=0;i<=c+1;i++){
		pre[i]=last;
		if(a[i]) last=i;
		a[i]=min(a[i],c/i);
	}
	stable[0]=1;
	for(int i=1;i<=c;i++){
		int k=pre[i+1],now=i;
		while(k){
			if(now<=k*a[k]){stable[i]=stable[now%k];break;}
			now-=k*a[k];k=pre[k];
		}
	}
	f[0]=dp[0][0]=g[0]=inf;
	for(int i=1;i<=c;i++){
		if(!stable[i])f[i]=0;
		else{
			f[i]=inf;
			int k=pre[i+1],now=i;
			while(1){
				int x=min(a[k],now/k)*k;
				if(x>0) gmin(f[i],g[min(k-1,now-x)]+now-x+k);
				if(x>k) gmin(f[i],get(min(k-1,now-x+1),k-1)+now-x+k*2);
				if(now<=k*a[k]){gmin(f[i],f[now%k]);break;}
				now-=k*a[k];k=pre[k];
				if(now<=0) break;
			}
		}
//		printf("%d ",f[i]);
		g[i]=min(g[i-1],f[i]-i);
		dp[i][0]=f[i]-i;
		for(int j=1;j<=18;j++)
			if((i-(1<<j)+1)>=0) dp[i][j]=min(dp[i][j-1],dp[i-(1<<j-1)][j-1]); else break;
	}
//	puts("");
	if(f[c]<=c) printf("%d\n",f[c]); else puts("Greed is good");
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}