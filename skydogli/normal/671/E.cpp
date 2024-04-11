#include<bits/stdc++.h>
using namespace std;
#define MN 100005
#define LL long long
#define int long long
const int INF=1000000000000000000ll;
int n,k;
int a[MN],d[MN];
LL f[MN],g[MN];
#define Ls (x<<1)
#define Rs (x<<1|1)
#define mid ((l+r)>>1)
int A[MN<<2],B[MN<<2],tag[MN<<2];
void pu(int x){A[x]=min(A[Ls],A[Rs]);B[x]=min(B[Ls],B[Rs]);}
void pd(int x){
	if(tag[x]){
		A[Ls]+=tag[x];
		A[Rs]+=tag[x];
		tag[Ls]+=tag[x];
		tag[Rs]+=tag[x];
		tag[x]=0;
	}
}
void SET(int x,int l,int r,int loc){
	if(l==r){A[x]=B[x]=g[loc];return;}
	if(loc<=mid)SET(Ls,l,mid,loc);
	else SET(Rs,mid+1,r,loc);
	pu(x);
}
void change(int x,int l,int r,int b,int e,int v){
	if(b<=l&&r<=e){
		A[x]+=v;
		tag[x]+=v;
		return;
	}
	if(l>e||r<b)return;
	pd(x);
	if(b<=mid)change(Ls,l,mid,b,e,v);
	if(e>mid)change(Rs,mid+1,r,b,e,v);
	pu(x);
}
int ask(int x,int l,int r,int Min,int rmax){
	if(l>rmax) return 0;
	if(B[x]-k>Min) return 0;
	if(l==r)return l;
	pd(x);
	if(A[Ls]>=B[Rs]-k){
		int ans=ask(Rs,mid+1,r,min(Min,A[Ls]),rmax);
		if(ans)return ans;
	}
	return ask(Ls,l,mid,Min,rmax);
}
int st[MN];
signed main(){
	memset(A,0x3f,sizeof(A));
	memset(B,0x3f,sizeof(B));
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;++i){
		scanf("%lld",&d[i]);
	}
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+a[i-1]-d[i-1];
		g[i]=g[i-1]+d[i-1]-a[i];
	}
	int ans=0,N=0;
	for(int i=n;i;--i){
		int now=0,lst=i;
		LL Min=g[i];
		SET(1,1,n,i);
		while(N&&f[i]<f[st[N]]){
			if(N>1) change(1,1,n,st[N-1]-1,n,f[st[N]]-f[st[N-1]]);
			N--;
		}
		st[++N]=i;
		if(N>1)change(1,1,n,st[N-1]-1,n,f[st[N-1]]-f[st[N]]);
		int l=0,r=N+1;
		st[0]=n+1;
		while(l+1<r){
			if(f[i]-f[st[mid]]>k) l=mid;
			else r=mid;
		}
	//	cerr<<"get "<<i<<": "<<st[l]<<endl;
		ans=max(ans,ask(1,1,n,INF,st[l]-1)-i+1);
/*		for(int j=i+1;j<=n;++j){
			if(f[j]<f[lst]){
				now+=f[lst]-f[j];
				Min=min(Min,g[j-1]-now);
				lst=j;
			}
			if(now>k){
				break;
			}
			if(Min>=g[j]-k){
				ans=max(ans,j-i+1);
			}
			Min=min(Min,g[j]-now);
		}*/
	}
	printf("%lld\n",ans);
	return 0;
}