#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct P{
	ll x,y;
}a[5];
bool cmp(P a,P b){
	return a.y<b.y;
}
//int idx[5];
//ll dis(P a,P b){
//	return abs(a.x-b.x)+abs(a.y-b.y);
//}
int n=3;
ll minx=1ll<<50,maxx=-1ll<<50;

struct node{
	ll x1,y1,x2,y2;
};
vector<node>v;
//void to(P a,P b){
//	if(a.x==b.x){
//		v.push_back({a.x,a.y,b.x,b.y});
//	}
//	else if(a.y==b.y)v.push_back({a.x,a.y,b.x,b.y});
//	else{
//		v.push_back({a.x,a.y,a.x,b.y});
//		v.push_back({a.x,b.y,b.x,b.y});
//	}
//}
int main(){
	for(int i=1;i<=n;++i){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		minx=min(minx,a[i].x);
		maxx=max(maxx,a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	v.push_back({minx,a[2].y,maxx,a[2].y});
	if(a[1].y!=a[2].y)v.push_back({a[1].x,a[1].y,a[1].x,a[2].y});
	if(a[3].y!=a[2].y)v.push_back({a[3].x,a[3].y,a[3].x,a[2].y});
	printf("%d\n",v.size());
	for(auto pr:v){
		printf("%lld %lld %lld %lld\n",pr.x1,pr.y1,pr.x2,pr.y2);
	}
}