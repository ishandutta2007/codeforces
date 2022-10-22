#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
const int o=1e5+10;
int T,n,p[o],cnt,F[o],f[o],lst[o],ps,N;bool vis[o];pair<int,int> pr,mx[o];
vector<int> ans[o];set<pair<int,int> > S;set<pair<int,int> >::iterator iter;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,pair<int,int> val){for(;pos<=N;pos+=lowbit(pos)) mx[pos]=max(mx[pos],val);}
inline pair<int,int> query(int pos){pair<int,int> res=mx[0];for(;pos;pos-=lowbit(pos)) res=max(res,mx[pos]);return res;}
void getans(int x){
	if(lst[x]) getans(lst[x]);
	vis[x]=1;ans[cnt].push_back(p[x]);
}
void slv(){
	scanf("%d",&n);N=n;
	for(int i=1;i<=n;F[i]=vis[i]=0,++i) scanf("%d",&p[i]);
	for(int i=1,j=1;j<=n;j+=++i) F[j]=i;
	for(int i=1;i<=n;++i) if(!F[i]) F[i]=F[i-1];
	for(int len=0,ps=0;n;n=len,len=ps=0){
		for(int i=1;i<=N;++i) mx[i]=make_pair(0,0);
		for(int i=1;i<=n;modify(p[i],make_pair(f[i],i)),++i) pr=query(p[i]),f[i]=pr.first+1,lst[i]=pr.second;
		for(int i=1;i<=n;++i) if(f[i]>f[ps]) ps=i;
		if(f[ps]>F[n]){
			++cnt;getans(ps);
			for(int i=1;i<=n;++i) if(!vis[i]) p[++len]=p[i];
			for(int i=ps;i;i=lst[i]) vis[i]=0;
		}
		else break;
	}
	for(int i=1,j;i<=n;++i)
		if((iter=S.lower_bound(make_pair(p[i],0)))==S.end())
			S.insert(make_pair(p[i],++cnt)),ans[cnt].push_back(p[i]);
		else j=(*iter).second,ans[j].push_back(p[i]),S.erase(iter),S.insert(make_pair(p[i],j));
	printf("%d\n",cnt);
	for(int i=1,j,k;i<=cnt;++i,putchar('\n'))
		for(j=0,printf("%d ",k=ans[i].size());j<k;++j) printf("%d ",ans[i][j]);
}
int main(){
	for(scanf("%d",&T);T--;cnt=0,S.clear()){
		slv();
		for(int i=1;i<=cnt;++i) ans[i].clear();
	}
	return 0;
}