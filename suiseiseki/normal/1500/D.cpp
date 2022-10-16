#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=1500;
struct List{
	std::pair<int,int> a[12];
	int p;
	List(){
		p=0;
		for(int i=0;i<12;i++){
			a[i]=std::make_pair(0,0);
		}
	}
	List(std::pair<int,int> x){
		a[0]=x;
		p=1;
		for(int i=1;i<12;i++){
			a[i]=std::make_pair(0,0);
		}
	}
	void push_back(std::pair<int,int> x){
		a[p]=x;
		p++;
	}
	int size(){
		return p;
	}
	std::pair<int,int> &operator [](int x){
		return a[x];
	}
}a[Maxn+5][Maxn+5],col[Maxn+5][Maxn+5];
int c[Maxn+5][Maxn+5],ans[Maxn+5];
int n,q;
int find_dis(std::pair<int,int> x,std::pair<int,int> y){
	return std::max(std::abs(x.first-y.first),std::abs(x.second-y.second));
}
bool vis[Maxn*Maxn+5];
std::pair<int,int> p_zero;
List merge(List a,List b){
	List lis;
	int x=0,y=0;
	while(lis.size()<=q&&(x<a.size()||y<b.size())){
		if(x==a.size()||(y!=b.size()&&find_dis(p_zero,a[x])>=find_dis(p_zero,b[y]))){
			if(!vis[c[b[y].first][b[y].second]]){
				lis.push_back(b[y]);
			}
			vis[c[b[y].first][b[y].second]]=1;
			y++;
		}
		else{
			if(!vis[c[a[x].first][a[x].second]]){
				lis.push_back(a[x]);
			}
			vis[c[a[x].first][a[x].second]]=1;
			x++;
		}
	}
	for(int i=0;i<a.size();i++){
		vis[c[a[i].first][a[i].second]]=0;
	}
	for(int i=0;i<b.size();i++){
		vis[c[b[i].first][b[i].second]]=0;
	}
	return lis;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=n;i>0;i--){
		List cur;
		for(int j=n;j>0;j--){
			p_zero=std::make_pair(i,j);
			cur=merge(cur,List(std::make_pair(i,j)));
			col[i][j]=merge(col[i+1][j],List(std::make_pair(i,j)));
			a[i][j]=merge(merge(cur,col[i][j]),a[i+1][j+1]);
			int x=std::min(n-i+1,n-j+1);
			if(a[i][j].size()>q){
				x=std::min(x,find_dis(p_zero,a[i][j][q]));
			}
			ans[x]++;
		}
	}
	for(int i=n;i>=0;i--){
		ans[i]+=ans[i+1];
	}
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}