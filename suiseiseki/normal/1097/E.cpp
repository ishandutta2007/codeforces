#include <vector>
#include <cstdio>
#include <algorithm>
const int Maxn=100000;
int n,k;
int p[Maxn+5];
bool out[Maxn+5];
namespace BIT{
	std::pair<int,int> f[Maxn+5];
	void init(){
		for(int i=1;i<=n;i++){
			f[i]=std::make_pair(0,0);
		}
	}
	void add(int x,std::pair<int,int> a){
		for(int i=x;i<=n;i+=(i&(-i))){
			f[i]=std::max(f[i],a);
		}
	}
	std::pair<int,int> query(int x){
		std::pair<int,int> ans=std::make_pair(0,0);
		for(int i=x;i>0;i-=(i&(-i))){
			ans=std::max(ans,f[i]);
		}
		return ans;
	}
}
int f[Maxn+5],lst[Maxn+5];
std::vector<int> g[Maxn+5];
std::vector<int> get_lis(){
	for(int i=1;i<=n;i++){
		f[i]=lst[i]=0;
	}
	BIT::init();
	for(int i=1;i<=n;i++){
		if(out[i]){
			continue;
		}
		std::pair<int,int> val=BIT::query(p[i]);
		f[i]=val.first+1;
		lst[i]=val.second;
		BIT::add(p[i],std::make_pair(f[i],i));
	}
	int max_pos=0;
	for(int i=1;i<=n;i++){
		if(f[i]>f[max_pos]){
			max_pos=i;
		}
	}
	std::vector<int> lis;
	while(max_pos>0){
		lis.push_back(max_pos);
		max_pos=lst[max_pos];
	}
	std::reverse(lis.begin(),lis.end());
	return lis;
}
std::vector<std::vector<int> > ans;
std::vector<std::vector<int> > divide_all(){
	int g_len=0;
	for(int i=1;i<=n;i++){
		if(out[i]){
			continue;
		}
		if(g_len==0||p[i]>p[g[g_len].back()]){
			g_len++;
			g[g_len].clear();
			g[g_len].push_back(i);
		}
		else{
			int left=1,right=g_len;
			while(left<right){
				int mid=(left+right)>>1;
				if(p[i]>p[g[mid].back()]){
					left=mid+1;
				}
				else{
					right=mid;
				}
			}
			g[left].push_back(i);
		}
	}
	std::vector<std::vector<int> > ans;
	for(int i=1;i<=g_len;i++){
		ans.push_back(g[i]);
	}
	return ans;
}
void solve(){
	ans.clear();
	scanf("%d",&n);
	k=1;
	while(1ll*k*(k+1)/2<=n){
		k++;
	}
	k--;
	for(int i=1;i<=n;i++){
		out[i]=0;
		scanf("%d",&p[i]);
	}
	int last_n=n;
	while(last_n>0){
		std::vector<int> lis=get_lis();
		if((int)lis.size()>k){
			ans.push_back(lis);
			for(int i:lis){
				out[i]=1;
			}
			last_n-=(int)lis.size();
			k--;
		}
		else{
			std::vector<std::vector<int> > lis=divide_all();
			ans.insert(ans.end(),lis.begin(),lis.end());
			last_n=0;
		}
	}
	printf("%d\n",(int)ans.size());
	for(std::vector<int> lis:ans){
		printf("%d ",(int)lis.size());
		for(int i:lis){
			printf("%d ",p[i]);
		}
		puts("");
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