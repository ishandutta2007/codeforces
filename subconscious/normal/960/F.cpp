#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
#define P 1000000007
#define N 100005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef long double ld;
map<int,int>a[N];
int n,m,x,y,d,ans;
int main(){
	scanf("%d%d",&n,&m);ans=0;
	rep(i,n)a[i].insert(mp(-1,0));
	rep(i,m){
		scanf("%d%d%d",&x,&y,&d);
		bool q=0;
		if(a[x].find(d)==a[x].end())a[x].insert(mp(d,inf)),q=1;
		auto p=a[x].find(d);
		--p;
		//printf("%d %d\n",p->first,p->second);
		int ss=p->second+1;ans=max(ans,ss);
		if(q)++p,a[x].erase(p);
		p=a[y].find(d);
		if(p!=a[y].end())ss=max(ss,p->second),a[y].erase(p);
		a[y].insert(mp(d,inf));
		p=a[y].find(d);--p;if((p->second)>=ss){++p;a[y].erase(p);continue;}
		++p;a[y].erase(p);
		a[y].insert(mp(d,ss));
		while((p=a[y].upper_bound(d))!=a[y].end()){//printf("%d %d\n",p->first,p->second);
			if(p->second<=ss)a[y].erase(p);else break;
		}
	}
	printf("%d\n",ans);
	return 0;
}