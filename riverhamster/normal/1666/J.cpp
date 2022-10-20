#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n;
ll c[Maxn+5][Maxn+5];
ll f[Maxn+5][Maxn+5];
int pos[Maxn+5][Maxn+5];
ll sum[Maxn+5][Maxn+5];
int fa[Maxn+5];
void print(int l,int r,int f){
	if(l>r){
		return;
	}
	fa[pos[l][r]]=f;
	print(l,pos[l][r]-1,pos[l][r]),print(pos[l][r]+1,r,pos[l][r]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
			c[i][j]+=c[i][j-1];
		}
	}
	for(int l=n;l>0;l--){
		for(int r=l;r<=n;r++){
			for(int i=l;i<=r;i++){
				sum[l][r]+=c[i][l-1]+c[i][n]-c[i][r];
			}
			if(l==r){
				f[l][r]=0,pos[l][r]=l;
				continue;
			}
			f[l][r]=Inf_ll;
			for(int i=l;i<=r;i++){
				if(f[l][i-1]+f[i+1][r]+sum[l][i-1]+sum[i+1][r]<f[l][r]){
					pos[l][r]=i;
				}
				f[l][r]=std::min(f[l][r],f[l][i-1]+f[i+1][r]+sum[l][i-1]+sum[i+1][r]);
			}
		}
	}
	print(1,n,0);
	for(int i=1;i<=n;i++){
		printf("%d ",fa[i]);
	}
	puts("");
	return 0;
}