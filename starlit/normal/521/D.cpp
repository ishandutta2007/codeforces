#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int n,m,k,a[N],mx[N],no[N],t;
struct dat{
	int op,x;double v;
}ans[N];
bool cmp(dat a,dat b){return a.v>b.v;}
long long now;
int op,u,v;
vector<dat>ad[N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
	scanf("%d",a+i);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&op,&u,&v);
		if(op>2)ans[t++]={3,i,v};
		else if(op>1)ad[u].push_back({2,i,v});
		else if(mx[u]<v)mx[u]=v,no[u]=i;
	}
	for(int i=1;i<=n;i++){
		if(mx[i]>a[i])ad[i].push_back({1,no[i],mx[i]-a[i]});
		sort(ad[i].begin(),ad[i].end(),cmp);
		now=a[i];
		for(auto j:ad[i])
		ans[t]=j,ans[t++].v=(double)(now+j.v)/now,now+=j.v;
	}
	k=min(t,k);
	nth_element(ans,ans+k,ans+t,cmp);
	sort(ans,ans+k,[](dat a,dat b){return a.op<b.op;});
	printf("%d\n",k);
	for(int i=0;i<k;i++)
	printf("%d ",ans[i].x);
}