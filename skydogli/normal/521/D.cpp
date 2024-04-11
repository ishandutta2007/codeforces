#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pdi pair<double,int>
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
#define MN 100005
int k,n,m,a[MN],O[MN],X[MN],Y[MN];
int upd[MN],pos[MN];
priority_queue<pdi >Q,mul;
priority_queue<pii >ad[MN];
vector<int>ans;
signed main(){
	scanf("%lld%lld%lld",&k,&n,&m);
	for(int i=1;i<=k;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i){
		int op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		O[i]=op;X[i]=x;Y[i]=y;
		if(op==1){
			if(upd[x]<y-a[x])upd[x]=y-a[x],pos[x]=i;
			Y[i]-=a[x];
		}
		else if(op==2)ad[x].push(mp(y,i));
		else if(y!=1)mul.push(mp(y,i));//cerr<<"QWQ: "<<i<<endl;
	}
	for(int i=1;i<=k;++i){
		if(upd[i])ad[i].push(mp(upd[i],pos[i]));
		if(!ad[i].empty()){
			Q.push(mp(1.0+1.0*ad[i].top().x/a[i],ad[i].top().y));
			ad[i].pop();
		}
	}
	for(int i=1;i<=m;++i){
		if(Q.empty()&&mul.empty())break;
		if(Q.empty()||(!mul.empty()&&Q.top().x<mul.top().x)){
			ans.push_back(mul.top().y);
//			cerr<<"MUL "<<mul.top().y<<endl;
			mul.pop();
		}
		else{
			ans.push_back(Q.top().y);
//			cerr<<"AD "<<Q.top().y<<endl;
			int p=X[Q.top().y];
			a[p]+=Y[Q.top().y];
			Q.pop();
			if(!ad[p].empty()){
				Q.push(mp(1.0+1.0*ad[p].top().x/a[p],ad[p].top().y));
				ad[p].pop();
			}
		}
	}
	sort(ans.begin(),ans.end(),[](int i,int j){return O[i]<O[j];});
	printf("%lld\n",(int)ans.size());
	for(int i=0;i<ans.size();++i)printf("%lld ",ans[i]);
	return 0;
}