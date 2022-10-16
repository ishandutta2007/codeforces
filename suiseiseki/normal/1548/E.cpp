#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=200000;
int n,m,x;
int a[Maxn+5],b[Maxn+5];
int p[Maxn+5];
int l[Maxn+5],r[Maxn+5];
int id_a[Maxn+5],id_b[Maxn+5];
int fa[Maxn+5];
bool vis[Maxn+5];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
}
namespace BIT{
	int f[Maxn+5];
	void add(int x,int a){
		for(int i=x;i>0;i-=(i&(-i))){
			f[i]+=a;
		}
	}
	int query(int x){
		x=std::max(x+1,1);
		int ans=0;
		for(int i=x;i<=Maxn;i+=(i&(-i))){
			ans+=f[i];
		}
		return ans;
	}
}
void merge(int x,int y){
	if(!vis[y]){
		return;
	}
	int fa_x=find(x),fa_y=find(y);
	if(fa_x==fa_y){
		return;
	}
	if(b[fa_x]>b[fa_y]){
		std::swap(fa_x,fa_y);
		std::swap(x,y);
	}
	BIT::add(b[fa_y],-1);
	fa[fa_y]=fa_x;
}
bool cmp_a(int x,int y){
	if(a[x]==a[y]){
		return x>y;
	}
	return a[x]>a[y];
}
bool cmp_b(int x,int y){
	return b[x]<b[y];
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id_a[i]=i;
		l[i]=r[i]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		id_b[i]=i;
	}
	for(int i=1;i<=n;i++){
		p[i]=i-1;
		while(p[i]&&a[p[i]]>a[i]){
			l[i]=std::max(l[i],l[p[i]]);
			p[i]=p[p[i]];
		}
		if(p[i]==0){
			l[i]=x;
		}
	}
	for(int i=n;i>0;i--){
		p[i]=i+1;
		while(p[i]<=n&&a[p[i]]>=a[i]){
			r[i]=std::max(r[i],r[p[i]]);
			p[i]=p[p[i]];
		}
		if(p[i]>n){
			r[i]=x;
		}
	}
	std::sort(id_a+1,id_a+1+n,cmp_a);
	std::sort(id_b+1,id_b+1+m,cmp_b);
	for(int i=0;i<=m+1;i++){
		fa[i]=i;
	}
	ll ans=0;
	for(int i=1,j=1;i<=n;i++){
		while(j<=m&&b[id_b[j]]+a[id_a[i]]<=x){
			merge(id_b[j],id_b[j]-1),merge(id_b[j],id_b[j]+1);
			BIT::add(b[id_b[j]],1);
			vis[id_b[j]]=1;
			j++;
		}
		ans+=BIT::query(x-std::min(l[id_a[i]],r[id_a[i]]));
	}
	printf("%lld\n",ans);
	return 0;
}