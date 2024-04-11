#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
const int Maxn=300000;
const int Maxb=400;
int n,m;
int a[Maxn+5];
int d[Maxn+5],d_len;
int num[Maxn+5];
bool vis[Maxn+5];
std::vector<int> lis[Maxb+5],nov[Maxn+5],out;
void solve(){
	d_len=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[++d_len]=a[i];
	}
	std::sort(d+1,d+1+d_len);
	d_len=std::unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=d_len;i++){
		num[i]=0,nov[i].clear();
	}
	out.clear();
	for(int i=1;i<=n;i++){
		a[i]=std::lower_bound(d+1,d+1+d_len,a[i])-d;
		num[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=std::lower_bound(d+1,d+1+d_len,x)-d,y=std::lower_bound(d+1,d+1+d_len,y)-d;
		nov[y].push_back(x);
	}
	ll ans=0;
	for(int i=1;i<=d_len;i++){
		for(int j:nov[i]){
			vis[j]=1;
		}
		{
			for(int j:out){
				if(vis[j]){
					continue;
				}
				ans=std::max(ans,1ll*(num[i]+num[j])*(d[i]+d[j]));
			}
		}
		{
			for(int j=Maxb-1;j>0;j--){
				for(int k=(int)lis[j].size()-1;k>=0;k--){
					if(vis[lis[j][k]]){
						continue;
					}
					ans=std::max(ans,1ll*(num[i]+j)*(d[i]+d[lis[j][k]]));
					break;
				}
			}
		}
		if(num[i]<Maxb){
			lis[num[i]].push_back(i);
		}
		else{
			out.push_back(i);
		}
		for(int j:nov[i]){
			vis[j]=0;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=d_len;i++){
		if(num[i]<Maxn){
			lis[num[i]].clear();
		}
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}