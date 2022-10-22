#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int p[200010];
int cnt[3000010];
struct poly{
	vector<int>a;
	int len;
	poly(){
		len=-1;
	}
}X[200010];
int R[400010];
int m;
const int mod=998244353;
int qpow(int x,int k){
	int res=1;
	while(k){
		if(k&1) res=1ll*res*x%mod;
		x=1ll*x*x%mod ;
		k>>=1;
	} 
	return res;
}
void NTT(vector<int>&s,int f){
	for(int i=0;i<=m;++i) if(i<R[i]) swap(s[i],s[R[i]]);
	for(int l=1;l<m;l<<=1){
		int w=(f==1?qpow(3,(mod-1)/(l<<1)):qpow(qpow(3,mod-2),(mod-1)/(l<<1)));
		for(int j=0;j<m;j+=(l<<1)){
			int sum=1;
			for(int k=0;k<l;++k){
				int a1=s[j+k],a2=s[j+k+l];
				a2=1ll*a2*sum%mod;
				s[j+k]=(a1+a2)%mod,s[j+k+l]=(a1-a2+mod)%mod;
				sum=1ll*sum*w%mod;
			}
		}
	}
}
poly operator *(poly a,poly b){
	int sz=a.len+b.len;
	int l=0;m=1;
	while(m<=sz) ++l,m<<=1;
	vector<int>A,B;
	A.resize(m*2+1),B.resize(m*2+1);
	for(int i=0;i<=a.len;++i) A[i]=a.a[i];
	for(int i=a.len+1;i<=m;++i) A[i]=0;
	for(int i=0;i<=b.len;++i) B[i]=b.a[i]; 
	for(int i=b.len+1;i<=m;++i) B[i]=0;
	for(int i=0;i<=m;++i) R[i]=(R[i>>1]>>1)|((i&1)<<l-1);
	NTT(A,1);NTT(B,1);
	poly c;c.a.resize(m*2+1);
	for(int i=0;i<=m;++i) c.a[i]=1ll*A[i]*B[i]%mod;
	NTT(c.a,-1);
	for(int i=0;i<=sz;++i){
		c.a[i]=1ll*c.a[i]*qpow(m,mod-2)%mod;
	}
	c.len=sz;
	return c;
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) p[i]=read(),++cnt[p[i]];
	int count=0;
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	for(int i=1;i<=3000000;++i){
		if(cnt[i]){
			++count;
			X[count].a.resize(cnt[i]+1);
			X[count].len=cnt[i];
			for(int j=0;j<=cnt[i];++j) X[count].a[j]=1;
			Q.push(mp(cnt[i],count));
		}
	}
	while(Q.size()>1){
		int u=Q.top().se;
		Q.pop();
		int v=Q.top().se;
		Q.pop();
		X[u]=X[u]*X[v];
		Q.push(mp(X[u].len,u));
	}
	printf("%d\n",X[Q.top().se].a[X[Q.top().se].len+1>>1]);
}