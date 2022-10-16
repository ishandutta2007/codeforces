#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
typedef long long ll;
const int Maxn=1000000;
int n;
ll a[2][Maxn+5];
int lst[3][Maxn+5];
std::map<ll,int> mp;
int f[Maxn+5];
int g[2][Maxn+5];
std::vector<std::pair<std::pair<int,int>,int> > lis[Maxn+5];
void upd_val(int x,int y,int v){
	f[std::min(x,y)]=std::max(f[std::min(x,y)],v);
	lis[std::max(x,y)].push_back(std::make_pair(std::make_pair(x,y),v));
}
void make_upd(int x,int y,int v){
	upd_val(x-1,y,v),upd_val(x,y-1,v);
	if(lst[0][x]!=-1){
		upd_val(lst[0][x],y,v+1);
	}
	if(lst[1][y]!=-1){
		upd_val(x,lst[1][y],v+1);
	}
	if(x==y&&lst[2][x]!=-1){
		upd_val(lst[2][x],lst[2][y],v+1);
	}
}
int main(){
	scanf("%d",&n);
	lst[0][0]=lst[1][0]=lst[2][0]=-1;
	mp[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[0][i]);
		a[0][i]+=a[0][i-1];
		lst[0][i]=lst[0][i-1];
		if(mp.count(a[0][i])>0){
			lst[0][i]=std::max(lst[0][i],mp[a[0][i]]);
		}
		mp[a[0][i]]=i;
	}
	mp.clear();
	mp[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[1][i]);
		a[1][i]+=a[1][i-1];
		lst[1][i]=lst[1][i-1];
		if(mp.count(a[1][i])>0){
			lst[1][i]=std::max(lst[1][i],mp[a[1][i]]);
		}
		mp[a[1][i]]=i;
	}
	mp.clear();
	mp[0]=0;
	for(int i=1;i<=n;i++){
		lst[2][i]=lst[2][i-1];
		if(mp.count(a[0][i]+a[1][i])>0){
			lst[2][i]=std::max(lst[2][i],mp[a[0][i]+a[1][i]]);
		}
		mp[a[0][i]+a[1][i]]=i;
		g[0][i]=g[1][i]=-1;
	}
	for(int i=n;i>0;i--){
		make_upd(i,i,f[i]);
		for(std::pair<std::pair<int,int>,int> v:lis[i]){
			if(v.second!=f[i]+1){
				continue;
			}
			if(v.first.first<i){
				g[0][i]=std::max(g[0][i],v.first.first);
			}
			if(v.first.second<i){
				g[1][i]=std::max(g[1][i],v.first.second);
			}
		}
		if(g[0][i]!=-1){
			make_upd(g[0][i],i,f[i]+1);
		}
		if(g[1][i]!=-1){
			make_upd(i,g[1][i],f[i]+1);
		}
	}
	printf("%d\n",f[0]);
	return 0;
}