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

const int N=105,M=100005,mod=1e9+7;
template<class T> inline void gmin(T &x,const T &y){if(x>y) x=y;}
template<class T> inline void gmax(T &x,const T &y){if(x<y) x=y;}
inline void ch(int &x,int y){x=(x+y)%mod;}
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int a[N],b[N],cnt[N],ans,n,k,last[N],nxt[N][N];
bool vis[N];

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=n;i++) last[i]=n+1;
	for(int i=n;i;i--){
		cpy(nxt[i],last);
		last[a[i]]=i;
	}
	int now=k;
	for(int i=1;i<=n;i++){
		cnt[a[i]]--;
		if(vis[a[i]]) continue;
		ans++;
		if(now){
			int r=1;
			for(int j=1;j<=k;j++)
				if(!b[j]) r=j;
			vis[a[i]]=1;b[r]=a[i];
			now--;
		}
		else{
			int r=1;
			for(int j=1;j<=k;j++)
				if(nxt[i][b[j]]>nxt[i][b[r]]) r=j;
			vis[b[r]]=0;b[r]=a[i];vis[a[i]]=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}