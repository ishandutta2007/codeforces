#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define rep(i,j,k) for(int i=(int)(j);i<=(int)(k);i++)
#define per(i,j,k) for(int i=(int)(j);i>=(int)(k);i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
int n,m;
map<int,bool> s[N];
int fa[N];
int get(int x){
	if(x==fa[x])return x;
	return fa[x]=get(fa[x]);
}
vector<int> d[N];
set<int> ui;
vector<int> era;
int ans;
void Union(int a,int b){
	a=get(a);
	b=get(b);
	if(d[a].size()<d[b].size())swap(a,b);
	era.pb(b);

	for(int x:d[b])d[a].pb(x);
	fa[b]=a;
}
int main(){
	scanf("%d%d",&n,&m);
	ans=n-1;
	rep(i,1,m){
		int a,b;scanf("%d%d",&a,&b);
		s[a][b]=s[b][a]=1;
	}
	rep(i,1,n)fa[i]=i,d[i].pb(i),ui.insert(i);

	rep(i,1,n){
		for(auto x=ui.begin();x!=ui.end();++x){
			if(get(i)==get(*x))continue;
			bool flg=0;
			for(int y:d[*x]){
				if(!s[i][y]){
					flg=1;
					break;
				}
			}
			if(flg){
				--ans;
				Union(i,*x);
			}
		}
		for(int x:era){
			ui.erase(ui.find(x));
		}
		era.clear();
	}
	printf("%d\n",ans);
	return 0;
}