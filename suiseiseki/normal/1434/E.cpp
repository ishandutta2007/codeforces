#include <cstdio>
#include <cstring>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxm=450;
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n,m;
int val[Maxn+5];
int f[Maxm+5][Maxn+5],g[Maxm+5][Maxn+5];
int p[Maxm+5],d[Maxm+5];
int c[Maxn+5],c_tot;
int a[Maxn+5];
int find(int *fa,int x){
	if(x==fa[x]){
		return x;
	}
	return fa[x]=find(fa,fa[x]);
}
void work(int l,int r,int *f,int *g,int v){
	while((r=find(f,r))>=l){
		f[r]=r-1;
		g[r]=v;
	}
}
int solve(){
	memset(val,0,sizeof val);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		val[a[i]]=i;
	}
	for(int i=Maxn;i>=0;i--){
		if(val[i]==0){
			val[i]=val[i+1];
		}
	}
	for(int i=0;i<=Maxm;i++){
		for(int j=0;j<=m;j++){
			f[i][j]=j;
			g[i][j]=-1;
		}
	}
	c_tot++;
	c[0]=c_tot;
	work(1,m,f[0],g[0],m);
	for(int i=m-1,j;i>0;i--){
		p[0]=Inf;
		for(j=0;j<Maxm;j++){
			if(g[j][i]==-1){
				break;
			}
			p[j+1]=min(p[j],g[j][i]);
		}
		c[j]=c_tot;
		int r_max=i+1;
		for(int k=j;k>0;k--){
			int t=(a[i]<<1)-a[p[k]]+1;
			if(t<0){
				d[k]=1;
			}
			else{
				d[k]=val[t];
			}
			if(d[k]>=r_max){
				continue;
			}
			work(d[k],r_max-1,f[k],g[k],i);
			r_max=d[k];
		}
	}
	int ans=0;
	while(c[ans]==c_tot){
		ans++;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans^=solve();
	}
	if(ans==0){
		puts("NO");
	}
	else{
		puts("YES");
	}
	return 0;
}