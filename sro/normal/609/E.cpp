#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define SZ(x) (x).size()
using namespace std;

int fa[25][200005];
int mx[25][200005];
int ceng[200005];
vector<pair<int,int> > nei[200005];
pair<pair<int,int>,pair<int,int> > egs[200005];
int n,m;
long long cnt=0;
bool isinmst[200005];
long long ans[200005];

struct{
	int Fa[200005];
	void init(){
		for(int i=0;i<200005;i++){
			Fa[i]=i;
		}
	}
	int root(int x){
		return Fa[x]==x?x:(Fa[x]=root(Fa[x]));
	}
	bool conn(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y){
			return 0;
		}
		Fa[x]=y;
		return 1;
	}
}dsu;

void dfs(int now,int lst){
	fa[0][now]=lst;
	ceng[now]=ceng[lst]+1;
	for(int i=0;i<SZ(nei[now]);i++){
		if(nei[now][i].first!=lst){
			dfs(nei[now][i].first,now);
			mx[0][nei[now][i].first]=nei[now][i].second;
		}
	}
}

int lcb(int a,int b){
	if(ceng[a]>ceng[b]){
		swap(a,b);
	}
	int toUP=ceng[b]-ceng[a];
	int maxx=0;
	for(int i=0;i<20;i++){
		if(toUP&(1<<i)){
			maxx=max(maxx,mx[i][b]);
			b=fa[i][b];
		}
	}
	if(a==b){
		return maxx;
	}
	for(int i=19;i>=0;i--){
		if(fa[i][a]!=fa[i][b]){
			maxx=max(maxx,mx[i][a]);
			maxx=max(maxx,mx[i][b]);
			a=fa[i][a];
			b=fa[i][b];
		}
	}
	maxx=max(maxx,mx[0][a]);
	maxx=max(maxx,mx[0][b]);
	return maxx;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&egs[i].second.first,&egs[i].second.second,&egs[i].first.first);
		egs[i].first.second=i;
	}
	dsu.init();
	sort(egs,egs+m);
	for(int i=0;i<m;i++){
		if(dsu.conn(egs[i].second.first,egs[i].second.second)){
			nei[egs[i].second.first].push_back(make_pair(egs[i].second.second,egs[i].first.first));
			nei[egs[i].second.second].push_back(make_pair(egs[i].second.first,egs[i].first.first));
			isinmst[i]=1;
			cnt+=egs[i].first.first;
		}
	}
	dfs(1,0);
	for(int i=1;i<20;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[i-1][fa[i-1][j]];
			mx[i][j]=max(mx[i-1][j],mx[i-1][fa[i-1][j]]);
		}
	}
	for(int i=0;i<m;i++){
		if(isinmst[i]){
			ans[egs[i].first.second]=cnt;
		}else{
			ans[egs[i].first.second]=cnt-lcb(egs[i].second.first,egs[i].second.second)+egs[i].first.first;
		}
	}
	for(int i=0;i<m;i++){
		printf("%I64d\n",ans[i]);
	}
	return 0;
}