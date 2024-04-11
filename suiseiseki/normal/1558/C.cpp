#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=3000;
int T,n,a[Maxn+5],fl;
std::vector<int> g;
void rev(int x){
	g.push_back(x);
	for(int i=1;i<=x/2;i++){
		std::swap(a[i],a[x+1-i]);
	}
}
int solve(int x){
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			return i;
		}
	}
	return -1;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i){
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		fl=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			fl|=((a[i]^i)&1);
		}
		if(fl){
			puts("-1");
		}
		else{
			g.clear();
			for(int i=n-1;i>0;i-=2){
				rev(solve(i+1));
				rev(solve(i)-1);
				rev(solve(i)+1);
				rev(3);
				rev(i+1);
			}
			printf("%d\n",(int)g.size());
			for(int i=0;i<(int)g.size();i++){
				printf("%d ",g[i]);
			}
			puts("");
		}
	}
	return 0;
}