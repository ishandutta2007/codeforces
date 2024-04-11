#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=200000;
const int Mod=1000000007;
int n;
int a[Maxn+5],id[Maxn+5];
int st[Maxn+5],st_top;
int f[Maxn+5],g[Maxn+5],h[Maxn+5];
std::vector<int> lis[Maxn+5];
namespace BIT{
	int n;
	int f[Maxn+5];
	void init(int _n){
		n=_n;
		for(int i=1;i<=n;i++){
			f[i]=0;
		}
	}
	void add(int x,int a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]=(f[i]+a)%Mod;
		}
	}
	int query(int x){
		int ans=0;
		for(int i=x;i>0;i-=(i&(-i))){
			ans=(ans+f[i])%Mod;
		}
		return ans;
	}
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		id[i]=i;
	}
	std::sort(id+1,id+1+n,[&](int p,int q){
		if(a[p]==a[q]){
			return p>q;
		}
		return a[p]<a[q];
	});
	for(int i=1;i<=n;i++){
		a[id[i]]=i;
	}
	st_top=0;
	for(int i=n;i>0;i--){
		if(a[i]>a[st[st_top]]){
			st[++st_top]=i;
		}
	}
	BIT::init(n);
	for(int i=1;i<=n;i++){
		f[i]=(BIT::query(a[i])+1)%Mod;
		BIT::add(a[i],f[i]);
	}
	BIT::init(n);
	for(int i=n;i>0;i--){
		g[i]=(BIT::query(n-a[i]+1)+1)%Mod;
		BIT::add(n-a[i]+1,g[i]);
	}
	for(int i=1;i<=st_top;i++){
		lis[i].clear();
	}
	for(int i=1;i<=st_top;i++){
		for(int j=a[st[i-1]]+1;j<=a[st[i]];j++){
			lis[i].push_back(id[j]);
		}
	}
	for(int i=1;i<=st_top;i++){
		std::sort(lis[i].begin(),lis[i].end());
		lis[i].pop_back();
		std::reverse(lis[i].begin(),lis[i].end());
	}
	for(int i=1;i<=st_top;i++){
		BIT::init((int)lis[i].size()+1);
		BIT::add(1,1);
		h[st[i]]=1;
		for(int j:lis[i]){
			h[j]=BIT::query(a[st[i]]-a[j]+1);
			BIT::add(a[st[i]]-a[j]+1,h[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=(ans+1ll*(g[i]-h[i]+Mod)*f[i])%Mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}