#include <cstdio>
#include <iostream>
#include <algorithm>
const int Maxn=200000;
const int Maxv=5000000;
const int eps=2500000;
int n;
struct Node{
	int a,id;
	friend bool operator <(Node a,Node b){
		return a.a<b.a;
	}
}a[Maxn+5];
int val[Maxv+5];
struct Value{
	std::pair<int,int> x[3];
	Value(){
		x[0].first=x[1].first=x[2].first=-1;
		x[0].second=x[1].second=x[2].second=-1;
	}
	void update(int a,int b){
		if(a>b){
			std::swap(a,b);
		}
		if(x[0].first==-1){
			x[0]=std::make_pair(a,b);
		}
		else if(x[1].first==-1){
			x[1]=std::make_pair(a,b);
		}
		else{
			x[2]=std::make_pair(a,b);
		}
	}
	std::pair<int,int> query(int a,int b){
		if(x[0].first!=a&&x[0].first!=b&&x[0].second!=a&&x[0].second!=b){
			return x[0];
		}
		if(x[1].first!=a&&x[1].first!=b&&x[1].second!=a&&x[1].second!=b){
			return x[1];
		}
		return x[2];
	}
}sum[Maxv+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		a[i].id=i;
	}
	std::sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		if(val[a[i].a-a[i-1].a+eps]>0){
			int t=val[a[i].a-a[i-1].a+eps];
			puts("YES");
			printf("%d %d %d %d\n",a[i].id,a[t-1].id,a[i-1].id,a[t].id);
			return 0;
		}
		val[a[i-1].a-a[i-2].a+eps]=i-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(sum[a[i].a+a[j].a].query(a[i].id,a[j].id).first!=-1){
				std::pair<int,int> tmp=sum[a[i].a+a[j].a].query(a[i].id,a[j].id);
				puts("YES");
				printf("%d %d %d %d\n",tmp.first,tmp.second,a[i].id,a[j].id);
				return 0;
			}
		}
		for(int j=1;j<i;j++){
			sum[a[i].a+a[j].a].update(a[i].id,a[j].id);
		}
	}
	puts("NO");
	return 0;
}