#include <bits/stdc++.h>
using namespace std;
//Coded in Dongge Jifang 4
//IP address: 192.168.12.233

int FFF;

struct afefa783gfid{
	int fa[500005],fa2[500005],lgl[500005];
	void init(){
		for(int i=0;i<500005;i++){
			fa[i]=i;
			fa2[i]=i;
		}
		memset(lgl,0,sizeof(lgl));
	}
	int root(int x){
		return fa[x]==x?x:(fa[x]=root(fa[x]));
	}
	int root2(int x){
		if(lgl[x]!=FFF){
			lgl[x]=FFF;
			fa2[x]=fa[x];
		}
		return fa2[x]==x?x:(fa2[x]=root2(fa2[x]));
	}
	bool conn(int x,int y){
		x=root(x);
		y=root(y);
		if(x==y){
			return 0;
		}
		fa[x]=y;
		return 1;
	}
	bool conn2(int x,int y){
		x=root2(x);
		y=root2(y);
		if(x==y){
			return 0;
		}
		fa2[x]=y;
		return 1;
	}
}dsu;

int n,m;
int u[500005],v[500005],w[500005];
vector<pair<int,int> > egs[500005];
vector<pair<int,int> > qry[500005];
bool shit[500005];

int main(){
	ios::sync_with_stdio(0);
	dsu.init();
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		egs[w[i]].push_back(make_pair(u[i],v[i]));
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int cnt;
		cin>>cnt;
		for(int j=0;j<cnt;j++){
			int x;
			cin>>x;
			qry[w[x]].push_back(make_pair(x,i));
		}
	}
	for(int i=0;i<500005;i++){
		int ass=-123;
		for(int j=0;j<qry[i].size();j++){
			if(ass!=qry[i][j].second){
				ass=qry[i][j].second;
				FFF++;
			}
			if(!dsu.conn2(u[qry[i][j].first],v[qry[i][j].first])){
				shit[qry[i][j].second]=1;
			}
		}
		for(int j=0;j<egs[i].size();j++){
			dsu.conn(egs[i][j].first,egs[i][j].second);
		}
	}
	for(int i=1;i<=q;i++){
		if(shit[i]){
			puts("NO");
		}else{
			puts("YES");
		}
	}
	return 0;
}