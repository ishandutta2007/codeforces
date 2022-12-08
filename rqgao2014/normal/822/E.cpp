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
	x=0;char ch=getchar(),rev=0;
	while(ch>'9'||ch<'0') rev=(ch=='-'),ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x=rev?-x:x;
}
inline int exp(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;y>>=1;
	}return ans;
}

namespace sufarr{
#define pos tmp
#define lcp rk
	const int N=210005;
	short lg[N];
	int n=0,cnt=200,s[N],rk[N],tmp[N],sa[N],c[N],f[N][22];
	inline int ins(char *str){
		int m=strlen(str+1),now=n;
		for(int i=1;i<=m;i++)
			s[++n]=str[i]-'a'+1;
		s[++n]=++cnt;
		return now+1;
	}
	void getsa(){
		int m=cnt;
		for(int i=1;i<=n;i++) rk[i]=s[i];
		for(int i=1;i<=n;i++) c[rk[i]]++;
		for(int i=1;i<=m;i++) c[i]+=c[i-1];
		for(int i=1;i<=n;i++)
			sa[c[rk[i]]]=i,c[rk[i]]--;
		for(int k=1;k<n;k<<=1){
			int tot=0;
			for(int i=n-k+1;i<=n;i++) tmp[++tot]=i;
			for(int i=1;i<=n;i++) if(sa[i]>k) tmp[++tot]=sa[i]-k;
			for(int i=1;i<=m;i++) c[i]=0;
			for(int i=1;i<=n;i++) c[rk[i]]++;
			for(int i=1;i<=m;i++) c[i]+=c[i-1];
			for(int i=n;i;i--)
				sa[c[rk[tmp[i]]]]=tmp[i],c[rk[tmp[i]]]--;
			tmp[sa[1]]=1;
			for(int i=2;i<=n;i++){
				int p=sa[i-1],q=sa[i];
				tmp[q]=tmp[p];
				if(rk[p]!=rk[q]||rk[p+k]!=rk[q+k]) tmp[q]++;
			}
			m=tmp[sa[n]];
			if(m==n) break;
			cpy(rk,tmp);
		}
	}
	void getlcp(){
		for(int i=1;i<=n;i++) pos[sa[i]]=i;
		for(int i=1,k=0;i<=n;i++){
			if(k) k--;
			while(s[i+k]==s[sa[pos[i]+1]+k]) k++;
			lcp[pos[i]]=k;
		}
		for(int i=1;i<n;i++)
			f[i][0]=lcp[i];
		for(int j=1;j<=20;j++)
			for(int i=1;i<=n;i++)
				if(i+(1<<j)<=n) f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	}
	void build(){
		for(int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
		getsa();getlcp();
	}
	inline int get(int l,int r){
		l=pos[l];r=pos[r];
		if(l>r) swap(l,r);
		int x=lg[r-l];
		return min(f[l][x],f[r-(1<<x)][x]);
	}
}

int n,m,x,dp[N][35];
char a[N],b[N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%s%d%s%d",&n,a+1,&m,b+1,&x);
	sufarr::ins(a);
	sufarr::ins(b);
	sufarr::build();
	for(int i=0;i<n;i++)
		for(int j=0;j<=x;j++){
			gmax(dp[i+1][j],dp[i][j]);
			int L=sufarr::get(i+1,dp[i][j]+n+2);
			if(L) gmax(dp[i+L][j+1],dp[i][j]+L);
		}
//	debug(dp[4][1]);
	puts(dp[n][x]<m?"NO":"YES");
	return 0;
}