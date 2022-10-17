#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int Maxn=200000;
const int Maxm=200000;
const int Mod=998244353;
const int Inf_int=0x3f3f3f3f;
const ll Inf_ll=0x3f3f3f3f3f3f3f3fll;
int n,m;
int pow_2[Maxn+5];
vector<int> g[2][Maxn+5];
void init(){
	pow_2[0]=1;
	for(int i=1;i<=Maxn;i++){
		pow_2[i]=(pow_2[i-1]<<1)%Mod;
	}
}
struct Node{
	int a;
	ll sum;
	friend bool operator <(Node a,Node b){
		if(a.a>=23){
			if(b.a>=23){
				if(a.a==b.a){
					return a.sum<b.sum;
				}
				return a.a<b.a;
			}
			return 0;
		}
		if(b.a>=23){
			return 1;
		}
		return pow_2[a.a]-1+a.sum<pow_2[b.a]-1+b.sum;
	}
	friend bool operator >(Node a,Node b){
		if(a.a>=23){
			if(b.a>=23){
				if(a.a==b.a){
					return a.sum>b.sum;
				}
				return a.a>b.a;
			}
			return 1;
		}
		if(b.a>=23){
			return 0;
		}
		return pow_2[a.a]-1+a.sum>pow_2[b.a]-1+b.sum;
	}
};
Node dis[25][Maxn+5];
priority_queue<pair<Node,int>,vector<pair<Node,int> >,greater<pair<Node,int> > > q;
int get_id(int x){
	if(x<23){
		return x;
	}
	return (x&1)+23;
}
void dij(){
	for(int i=0;i<=24;i++){
		for(int j=1;j<=n;j++){
			dis[i][j].a=Inf_int;
			dis[i][j].sum=Inf_ll;
		}
	}
	dis[0][1].sum=0;
	dis[0][1].a=0;
	q.push(make_pair(dis[0][1],1));
	while(!q.empty()){
		pair<Node,int> tmp_top=q.top();
		q.pop();
		int u=tmp_top.second,u_x=tmp_top.first.a;
		if(dis[get_id(u_x)][u].a!=u_x||dis[get_id(u_x)][u].sum!=tmp_top.first.sum){
			continue;
		}
		for(int v:g[u_x&1][u]){
			Node nxt;
			nxt.a=u_x;
			nxt.sum=dis[get_id(u_x)][u].sum+1;
			if(nxt<dis[get_id(u_x)][v]){
				dis[get_id(u_x)][v]=nxt;
				q.push(make_pair(nxt,v));
			}
		}
		for(int v:g[(u_x&1)^1][u]){
			Node nxt;
			nxt.a=u_x+1;
			nxt.sum=dis[get_id(u_x)][u].sum+1;
			if(nxt<dis[get_id(u_x+1)][v]){
				dis[get_id(u_x+1)][v]=nxt;
				q.push(make_pair(nxt,v));
			}
		}
	}
}
int main(){
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[0][u].push_back(v);
		g[1][v].push_back(u);
	}
	dij();
	Node ans=dis[0][n];
	for(int i=1;i<=24;i++){
		ans=min(ans,dis[i][n]);
	}
	printf("%d\n",(int)((pow_2[ans.a]-1+ans.sum)%Mod));
	return 0;
}