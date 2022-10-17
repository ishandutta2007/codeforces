#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct P{
	long long t;
	long long w;
	friend bool operator <(P p,P q){
		if(p.t==q.t){
			return p.w<q.w;
		}
		return p.t>q.t;
	}
}a[300005];
priority_queue<long long,vector<long long>,greater<long long> >q;
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",&a[i].t,&a[i].w);
	}
	sort(a+2,a+1+n);
	int id=2;
	int ans=1<<30;
	while(1){
		while(id<=n&&a[id].t>a[1].t){
			q.push(a[id].w-a[id].t+1);
			id++;
		}
		ans=mn(ans,q.size()+1);
		if(q.empty()||a[1].t<q.top()){
			break;
		}
		a[1].t-=q.top();
		q.pop();
	}
	printf("%d\n",ans);
	return 0;
}