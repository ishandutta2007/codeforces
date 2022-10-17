#include <map>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define Maxn 500005
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
int N,M;
map<int,vector<pair<int,int> > > E;
struct P{
	vector<int> par,rank,cnt;
	P(){
		par=rank=vector<int>(Maxn,0);
		cnt=vector<int>(Maxn,1);
		for(int i=0;i<Maxn;i++){
			par[i]=i;
		}
	}
	void reinit(){
		for(int i=0;i<Maxn;i++){
			rank[i]=0;
			cnt[i]=1;
			par[i]=i;
		}
	}
	int operator[](int x){
		return (par[x]==x)?x:(par[x]=(*this)[par[x]]);
	}
	int count(int x){
		return cnt[(*this)[x]];
	}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
P uf;
int main(){
	cout.tie(0);
	int i,j,k,l,r,x,y;
	scanf("%d%d",&N,&M);
	FOR(i,M){
		scanf("%d%d%d",&x,&y,&r);
		E[r].push_back({x-1,y-1});
	}
	int ret=0;
	FORR(e,E){
		vector<pair<int,int>> P;
		FORR(a,e.second) {
			if(uf[a.first]!=uf[a.second]) P.push_back(a);
		}
		FORR(a,P) {
			if(uf[a.first]!=uf[a.second]) {
				uf(a.first,a.second);
			}
			else {
				ret++;
			}
		}
	}
	cout<<ret<<endl;
	return 0;
}