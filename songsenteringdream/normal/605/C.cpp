#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;
const int o=1e5+10;
int n,st[o],tp;double p,q,ans=1e9,k,b,x;pair<int,int> pr[o];
int main(){
	scanf("%d%lf%lf",&n,&p,&q);
	for(int i=1;i<=n;++i) scanf("%d%d",&pr[i].first,&pr[i].second);
	sort(pr+1,pr+n+1);
	for(int i=1;i<=n;st[++tp]=i++)
		for(;(tp&&pr[st[tp]].second<=pr[i].second)||(tp>1&&(pr[st[tp-1]].second-pr[st[tp]].second)*1ll*(pr[i].first
		-pr[st[tp]].first)>(pr[st[tp]].second-pr[i].second)*1ll*(pr[st[tp]].first-pr[st[tp-1]].first));--tp);
	for(int i=1;i<=tp;++i) ans=min(ans,max(p/pr[st[i]].first,q/pr[st[i]].second));
	for(int i=1;i<tp;++i){
		k=(pr[st[i+1]].second-pr[st[i]].second)*1.0/(pr[st[i+1]].first-pr[st[i]].first);
		b=pr[st[i]].second-pr[st[i]].first*k;x=b/(q/p-k);
		if(x>=pr[st[i]].first&&x<=pr[st[i+1]].first) ans=min(ans,p/x);
	}
	printf("%lf",ans);
	return 0;
}