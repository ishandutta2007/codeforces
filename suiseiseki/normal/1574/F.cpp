#include <cstdio>
#include <vector>
#include <algorithm>
int quick_power(int a,int b,int Mod){
	int ans=1;
	while(b){
		if(b&1){
			ans=1ll*ans*a%Mod;
		}
		b>>=1;
		a=1ll*a*a%Mod;
	}
	return ans;
}
typedef unsigned long long ull;
const int Maxn=2000000;
const int Mod=998244353;
const int G=3;
int find_inv(int x){
	return quick_power(x,Mod-2,Mod);
}
int n,m,k;
int lst[Maxn+5],nxt[Maxn+5];
std::vector<int> c[Maxn+5],lis[Maxn+5];
bool un_val[Maxn+5],in_val[Maxn+5];
bool vis[Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
int a[Maxn+5],b[Maxn+5],a_len;
int len[Maxn+5];
namespace Poly{
	int add(int x,int y){
		return x+y>=Mod?x+y-Mod:x+y;
	}
	int del(int x,int y){
		return x-y<0?x-y+Mod:x-y;
	}
	int inv[Maxn+5],pow_G[Maxn+5];
	void init_G(int len){
		int t=quick_power(G,(Mod-1)/len,Mod);
		pow_G[len>>1]=1;
		for(int i=(len>>1)+1;i<len;i++){
			pow_G[i]=1ll*pow_G[i-1]*t%Mod;
		}
		for(int i=(len>>1)-1;i>0;i--){
			pow_G[i]=pow_G[i<<1];
		}
	}
	void init(){
		int len=1;
		while(len<=Maxn){
			len<<=1;
		}
		len>>=1;
		init_G(len);
		inv[1]=1;
		for(int i=2;i<=Maxn;i++){
			inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
		}
	}
	void NTT(int *a,int flag,int n){
		static int R[Maxn+5],last_len=0;
		int len=1,L=0;
		while(len<n){
			len<<=1;
			L++;
		}
		if(last_len!=len){
			for(int i=0;i<len;i++){
				R[i]=(R[i>>1]>>1)|((i&1)<<(L-1));
			}
		}
		for(int i=0;i<len;i++){
			if(i<R[i]){
				std::swap(a[i],a[R[i]]);
			}
		}
		for(int j=1;j<len;j<<=1){
			int *t=pow_G+j;
			for(int k=0;k<len;k+=(j<<1)){
				for(int l=0;l<j;l++){
					int Nx=a[k+l],Ny=1ll*t[l]*a[j+k+l]%Mod;
					a[k+l]=add(Nx,Ny);
					a[j+k+l]=del(Nx,Ny);
				}
			}
		}
		if(flag==-1){
			std::reverse(a+1,a+len);
			for(int i=0,t=inv[len];i<len;i++){
				a[i]=1ll*a[i]*t%Mod;
			}
		}
	}
	void poly_inv(int *a,int *b,int len){
		static int A[Maxn+5],B[Maxn+5];
		if(len==1){
			b[0]=find_inv(a[0]);
			return;
		}
		poly_inv(a,b,len>>1);
		for(int i=(len>>1);i<len;i++){
			b[i]=0;
		}
		for(int i=0;i<len;i++){
			A[i]=a[i];
			B[i]=b[i];
		}
		for(int i=len;i<(len<<1);i++){
			A[i]=B[i]=0;
		}
		NTT(A,1,len<<1);
		NTT(B,1,len<<1);
		for(int i=0;i<(len<<1);i++){
			A[i]=1ll*A[i]*B[i]%Mod*B[i]%Mod;
		}
		NTT(A,-1,len<<1);
		for(int i=0;i<len;i++){
			b[i]=del(add(b[i],b[i]),A[i]);
		}
	}
}
using Poly::NTT;
using Poly::poly_inv;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		c[i].resize(len[i]+1);
		for(int j=1;j<=len[i];j++){
			scanf("%d",&c[i][j]);
			lis[c[i][j]].push_back(i);
		}
		for(int j=2;j<=len[i];j++){
			if(lst[c[i][j]]==0){
				lst[c[i][j]]=c[i][j-1];
			}
			else if(lst[c[i][j]]!=c[i][j-1]){
				un_val[c[i][j]]=1;
			}
		}
		for(int j=1;j<len[i];j++){
			if(nxt[c[i][j]]==0){
				nxt[c[i][j]]=c[i][j+1];
			}
			else if(nxt[c[i][j]]!=c[i][j+1]){
				un_val[c[i][j]]=1;
			}
		}
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<=k;i++){
		if(un_val[i]){
			qu[++qu_t]=i;
		}
	}
	while(qu_f<=qu_t){
		int u=qu[qu_f++];
		for(int i=0;i<(int)lis[u].size();i++){
			int v=lis[u][i];
			if(in_val[v]){
				continue;
			}
			in_val[v]=1;
			for(int j=1;j<=len[v];j++){
				if(!un_val[c[v][j]]){
					un_val[c[v][j]]=1;
					qu[++qu_t]=c[v][j];
				}
			}
		}
	}
	for(int i=1;i<=k;i++){
		if(un_val[i]||vis[i]){
			continue;
		}
		vis[i]=1;
		int sum=1;
		bool flag=1;
		for(int j=lst[i];j;j=lst[j]){
			if(vis[j]){
				flag=0;
				break;
			}
			vis[j]=1;
			sum++;
		}
		if(!flag){
			continue;
		}
		for(int j=nxt[i];j;j=nxt[j]){
			vis[j]=1;
			sum++;
		}
		if(sum<=m){
			a[sum]++;
		}
	}
	Poly::init();
	a[0]++;
	for(int i=1;i<=m;i++){
		a[i]=(Mod-a[i])%Mod;
	}
	int len=1;
	while(len<=m){
		len<<=1;
	}
	Poly::poly_inv(a,b,len);
	printf("%d\n",b[m]);
	return 0;
}