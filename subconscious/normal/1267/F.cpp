#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define x0 gtmsub
#define y0 gtmshb
#define x1 gtmjtjl
#define y1 gtmsf
#define st first
#define nd second
const int N=2e5+5;
priority_queue<int,vector<int>,greater<int>>pq;
int a[N],b[N],cnt[N];
int n,m,ka,kb;
vector<pair<int,int>>vec;
int main()
{
	scanf("%d%d%d%d",&n,&m,&ka,&kb);
	rep(i,ka)scanf("%d",a+i);
	rep(i,kb)scanf("%d",b+i);
	if(ka>m-1||kb>n-1){puts("No");return 0;}
	puts("Yes");
	rep(i,m-1-ka)a[i+ka]=1;
	rep(i,n-1-kb)b[i+kb]=n+1;
	ka=m-1,kb=n-1;
	rep(i,ka)++cnt[a[i]];
	rep(i,kb)++cnt[b[i]];
	rep(i,n+m)if(cnt[i]==0)pq.push(i);
	int ptra=1,ptrb=1;
	rep(i,n+m-2){
		int now=pq.top();
		if(now<=n){
			//assert(ptrb<=kb);
			vec.pb(mp(now,b[ptrb]));
			--cnt[b[ptrb]];
			pq.pop();
			if(cnt[b[ptrb]]==0)pq.push(b[ptrb]);
			++ptrb;
		}else{
			//assert(ptra<=ka);
			vec.pb(mp(now,a[ptra]));
			--cnt[a[ptra]];
			pq.pop();
			if(cnt[a[ptra]]==0)pq.push(a[ptra]);
			++ptra;
		}
	}
	int now1=pq.top();pq.pop();
	int now2=pq.top();
	//assert((now1<=n&&now2>n)||(now1>n&&now2<=n));
	vec.pb(mp(now1,now2));
	for(auto&p:vec)printf("%d %d\n",p.st,p.nd);
	return 0;
}