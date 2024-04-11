#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,w;
int a[100010],b[100010];
int M;
vector<int>Vec[200010];
const int B=350;
const int inf=1e18;
struct block{
	int l;
	int it,ad,sz,p;
	int A[B<<1|1],c[B<<1|1];
	int stk[B<<1|1],tm[B<<1|1],top;
	int get(int t){
		return A[t]+c[t]*ad;
	}
	void build(){
		top=0;
		stk[++top]=0;tm[top]=-inf;
		for(int i=1;i<=sz;++i){
			while(1){
				if(!top){
					tm[++top]=-inf;stk[top]=i;break ;
				}
				// int f=(A[stk[top]]-A[i]-1)/(c[i]-c[stk[top]])+1;
				int f=(A[stk[top]]-A[i]+c[i]-c[stk[top]]-1)/(c[i]-c[stk[top]]);
				if(f<=tm[top]) --top;
				else{
					tm[++top]=f;stk[top]=i;
					break ;
				}
			}
		}
		it=0;p=0;
		for(int i=1;i<=top;++i) if(ad>=tm[i]) it=stk[i],p=i;else break ;
	}
	PII chk(){
		for(int i=p+1;i<=top;++i) if(ad>=tm[i]) it=stk[i],p=i;else break ;
		return mp(get(it),it+l);
	}
}C[B<<1|1];
int cnt;
int bel[200010];
PII getans(){
	PII res=mp(0,0);
	for(int i=1;i<=cnt;++i){
		res=max(res,C[i].chk());
	}
	return res;
}
void add(int i){
	int bl=bel[a[i]];
	for(int j=bl-1;j>=1;--j){
		C[j].ad++;
	}
	int p=a[i]-C[bl].l;
	for(int j=p;j>=0;--j){
		C[bl].A[j]+=C[bl].c[j];
	}
	C[bl].build();
}
signed main(){
	n=read(),w=read();
	int N=0;
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),M=max(M,a[i]+1),N=max(N,b[i]+1),Vec[b[i]].pb(i);
	cnt=0;
	for(int i=0;i<=M;i+=B){
		++cnt;C[cnt].it=C[cnt].sz=min(B-1,M-i);
		C[cnt].l=i;
		for(int j=0;j<B&&i+j<=M;++j){
			C[cnt].c[j]=i+j;bel[i+j]=cnt;
		}
	}
	int c=n;
	// for(int i=1;i<=n;++i)
	for(int i=0;i<=N;++i){
		if(i!=0){
			for(int j:Vec[i-1]){
				// if(n==100) printf("i:%d,j:%d,%d %d\n",i,j,a[j],b[j]);
				add(j);--c;
			}
		}
		PII ans=getans();
		// if(n==100) printf("%d %d\n",ans.fi,ans.se);
		ans.fi+=c*i*w;
		printf("%lld %lld\n",ans.fi,ans.se);
	}
}