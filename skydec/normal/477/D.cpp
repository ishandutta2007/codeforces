#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=5005;
const int P=1000000007;
inline int Min(const int &a,const int &b){if(a<b)return a;return b;}
inline int Max(const int &a,const int &b){if(a>b)return a;return b;}
inline void add(int &a,int b){
	a+=b;if(a>=P)a-=P;
}
int mc[N*2];
struct SA{
	int a[N*5],rank[N*5],sa[N*5],trank[N*5],tsa[N*5],p,sum[N*5],n;
	int h[N*5];
	int f[16][30000];
	inline void work(){
		p=0;
		rep(i,1,n){sum[rank[i]=a[i]]++;if(a[i]>p)p=a[i];}
		rep(i,1,p)sum[i]+=sum[i-1];
		rep(i,1,n)sa[sum[rank[i]]--]=i;
		
		trank[sa[1]]=1;p=1;
		rep(i,2,n){
			if(rank[sa[i]]!=rank[sa[i-1]])p++;
			trank[sa[i]]=p;
		}
		rep(i,1,n)rank[i]=trank[i];
		
		for(int k=1;k+1<=n&&p!=n;k++){
			rep(i,0,p)sum[i]=0;
			rep(i,1,n)sum[rank[i+k]]++;
			rep(i,1,p)sum[i]+=sum[i-1];
			rep(i,1,n)tsa[sum[rank[i+k]]--]=i;
			
			rep(i,0,p)sum[i]=0;
			rep(i,1,n)sum[rank[i]]++;
			rep(i,1,p)sum[i]+=sum[i-1];
			per(i,n,1)sa[sum[rank[tsa[i]]]--]=tsa[i];
			
			trank[sa[1]]=1;p=1;
			rep(i,2,n){
				if(rank[sa[i]]!=rank[sa[i-1]]||rank[sa[i]+k]!=rank[sa[i-1]+k])p++;
				trank[sa[i]]=p;
			}
			rep(i,1,n){rank[i]=trank[i];}
		}
		
		int t=0;
		rep(i,1,n){
			if(t)t--;
			while(a[i+t]==a[sa[rank[i]-1]+t])t++;
			f[0][rank[i]-1]=t;
		}
		
		rep(i,1,15)rep(j,1,n){
			f[i][j]=f[i-1][j];
			if((j+(1<<(i-1))<n)&&f[i-1][j+(1<<(i-1))]<f[i][j])f[i][j]=f[i-1][j+(1<<(i-1))];
		}
	}
	inline int lcp(int a,int b){
		a=rank[a];b=rank[b];
		if(a>b){int tmp=a;a=b;b=tmp;}
		b--;
		return Min(f[mc[b-a+1]-1][a],f[mc[b-a+1]-1][b-(1<<(mc[b-a+1]-1))+1]);
	}
}gt;
int f[N][N];int n;char str[N];
inline int cmp(const int &l,const int &r,const int &x,const int &y){
	int len=gt.lcp(l,x);
	if(len>=r-l+1)return 0;
	if(str[l+len]<str[x+len])return -1;
	return 1;
}
int pre[N];
int sum[N];
int p2[N];
inline int Getval(int l,int r){
	return ((sum[r]-sum[l-1]*1ll*p2[r-l+1])%P+P)%P;
}
inline void rex(int &a,int b){if(a>b)a=b;}
int g[N][N];
void Work2(){
	memset(g,63,sizeof g);
	
	p2[0]=1;
	rep(i,1,n){
		p2[i]=p2[i-1]*2ll%P;
		sum[i]=(sum[i-1]*2ll+(str[i]-'0'))%P;
	}
	
	g[1][1]=1;
	rep(i,2,n){
		g[1][i]=1;
		rep(j,1,i-1)if(str[j+1]=='1'){
			if(j<i-j)rex(g[j+1][i],g[1][j]+1);
			else{
				int len=i-j;
				if(cmp(j-len+1,j,j+1,i)<=0)rex(g[j+1][i],g[j-len+1][j]+1);
				else rex(g[j+1][i],g[j-len+2][j]+1);
			}
		}
		if(i^n)per(j,i-1,1)rex(g[j][i],g[j+1][i]);	
	}
	
	int ans=-1;
	for(int i=Max(n-25,1);i<=n;i++)if(g[i][n]<=n)if(g[i][n]+Getval(i,n)<=ans||ans==-1){ans=g[i][n]+Getval(i,n);}
	if(ans!=-1){
		printf("%d\n",ans);
		return;
	}
	for(int i=n;i>=1;i--)if(g[i][n]<=n){
		printf("%d\n",(Getval(i,n)+g[i][n])%P);
		return;
	}
}
int main(){
	for(int i=1;i<=10000;i++)mc[i]=mc[i/2]+1;
	
	scanf("%s",str+1);n=strlen(str+1);
	
	gt.n=n;rep(i,1,n)gt.a[i]=str[i]-'0'+1;gt.work();
	rep(i,n+1,n+10005)gt.a[i]=11;
	f[1][1]=1;
	
	rep(i,2,n){
		f[1][i]=1;
		rep(j,1,i-1)if(str[j+1]=='1'){
			if(j<i-j)add(f[j+1][i],f[1][j]);
			else{
				int len=i-j;
				if(cmp(j-len+1,j,j+1,i)<=0)add(f[j+1][i],f[j-len+1][j]);
				else add(f[j+1][i],f[j-len+2][j]);
			}
		}
		per(j,i-1,1)add(f[j][i],f[j+1][i]);	
	}
	int ret=f[1][n];
	printf("%d\n",ret);
	
	Work2();
	return 0;
}