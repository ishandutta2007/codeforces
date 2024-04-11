#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=200000;
int n;
int p[Maxn+5];
bool vis[Maxn+5];
std::vector<std::pair<int,int> > ans;
void my_swap(int u,int v){
	std::swap(p[u],p[v]);
	ans.push_back(std::make_pair(u,v));
}
std::vector<std::vector<int> > cir;
std::vector<int> lis;
void work_1(std::vector<int> lis){
	for(int i=1;i<(int)lis.size()-1;i++){
		my_swap(lis[0],lis[i]);
	}
	my_swap(lis[1],lis.back());
	my_swap(lis[0],lis.back());
	my_swap(lis[0],lis[1]);
}
void work_2(std::vector<int> a,std::vector<int> b){
	my_swap(a[0],b[0]);
	for(int i=1;i<(int)a.size();i++){
		my_swap(a[i],b[0]);
	}
	for(int i=1;i<(int)b.size();i++){
		my_swap(b[i],a[0]);
	}
	my_swap(a[0],b[0]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		lis.clear();
		for(int j=i;!vis[j];j=p[j]){
			lis.push_back(j);
			vis[j]=1;
		}
		cir.push_back(lis);
	}
	if((int)cir.size()==1){
		work_1(cir[0]);
	}
	else{
		if(cir.size()&1){
			cir.push_back(std::vector<int>{cir[0][0]});
		}
		for(int j=0;j<(int)cir.size();j+=2){
			work_2(cir[j],cir[j+1]);
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<(int)ans.size();i++){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
	return 0;
}