#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
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
const int Mod=1000000007;
const int Maxn=8000;
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int r;
int id_tot,tot;
int p[4];
int f[Maxn+5][Maxn+5];
int ans[Maxn+5];
map<pair<int,int>,int> id;
int main(){
	scanf("%d",&r);
	int sum=0;
	for(int i=0;i<4;i++){
		scanf("%d",&p[i]);
		sum+=p[i];
	}
	sum=quick_power(sum,Mod-2,Mod);
	for(int i=0;i<4;i++){
		p[i]=1ll*p[i]*sum%Mod;
	}
	for(int i=-r;i<=r;i++){
		for(int j=-r;j<=r;j++){
			if(i*i+j*j>r*r){
				continue;
			}
			id[make_pair(i,j)]=++id_tot;
		}
	}
	tot=0;
	for(int i=-r;i<=r;i++){
		for(int j=-r;j<=r;j++){
			if(i*i+j*j>r*r){
				continue;
			}
			f[++tot][0]=1;
			f[tot][id[make_pair(i,j)]]=Mod-1;
			for(int k=0;k<4;k++){
				int nx=i+d[k][0],ny=j+d[k][1];
				if(id[make_pair(nx,ny)]){
					f[tot][id[make_pair(nx,ny)]]=p[k];
				}
			}
		}
	}
	for(int i=1;i<=id_tot;i++){
		for(int j=i+1;j<=id_tot;j++){
			if(j-i>(r<<1)){
				continue;
			}
			int t=1ll*quick_power(f[j][i],Mod-2,Mod)*f[i][i]%Mod;
			if(t==0){
				continue;
			}
			int u=min(tot,j+(r<<1));
			for(int k=i;k<=u;k++){
				f[j][k]=(1ll*f[j][k]*t-f[i][k]+Mod)%Mod;
			}
			f[j][0]=(1ll*f[j][0]*t-f[i][0]+Mod)%Mod;
		}
	}
	for(int i=id_tot;i>0;i--){
		ans[i]=1ll*(Mod-f[i][0])*quick_power(f[i][i],Mod-2,Mod)%Mod;
		for(int j=max(1,i-(r<<1));j<i;j++){
			f[j][0]=(f[j][0]+1ll*f[j][i]*ans[i])%Mod;
		}
	}
	printf("%d\n",ans[id[make_pair(0,0)]]);
	return 0;
}