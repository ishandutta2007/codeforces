#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int Maxn=200000;
const int Maxv=(1<<20);
int n,m,q;
int c[Maxn+5];
int lim;
int ans[Maxn+5];
namespace BIT{
	int f[Maxv+5];
	void add(int x,int a){
		x++;
		for(int i=x;i<=lim;i+=(i&(-i))){
			f[i]^=a;
		}
	}
	int query(int x){
		int ans=0;
		x++;
		for(int i=x;i>0;i-=(i&(-i))){
			ans^=f[i];
		}
		return ans;
	}
	void clear(){
		memset(f,0,sizeof f);
	}
};
std::vector<std::pair<int,int> > op[Maxn+5];
void work(int d){
	BIT::clear();
	lim=(2<<d);
	for(int i=m;i>0;i--){
		if(c[i]){
			BIT::add(i&(lim-1),1);
		}
		for(int j=0;j<(int)op[i].size();j++){
			int x=(op[i][j].first&(lim-1));
			if(x&(1<<d)){
				ans[op[i][j].second]^=((BIT::query((x-(1<<d))-1)^BIT::query(x-1))<<d);
			}
			else{
				ans[op[i][j].second]^=((BIT::query(lim-1)^BIT::query(x+(1<<d)-1)^BIT::query(x-1))<<d);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		c[x]^=1;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		op[x].push_back(std::make_pair(x,i));
		op[y+1].push_back(std::make_pair(x,i));
	}
	for(int i=0;i<18;i++){
		work(i);
	}
	for(int i=1;i<=q;i++){
		if(ans[i]){
			putchar('A');
		}
		else{
			putchar('B');
		}
	}
	putchar('\n');
	return 0;
}