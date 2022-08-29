#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=110000;
const int M=100200;
const int P=1000000007;
int cl[N*160],cr[N*160],tot=1,dis[N];int key[N*160];
int n,m;vector<pii>p[N];
int copy(int x){
	++tot;cl[tot]=cl[x];cr[tot]=cr[x];key[tot]=key[x];
	return tot;
}
int compare(int a,int b){
	if(!cl[a]&&!cr[a]){
		if(key[a]==key[b])return 0;
		if(key[a]<key[b])return -1;
		return 1;
	}
	if(key[cr[a]]==key[cr[b]])return compare(cl[a],cl[b]);else return compare(cr[a],cr[b]);
}
struct Node{
	int id,root;
	inline Node(int a=0,int b=0){id=a;root=b;}
};
inline bool operator <(const Node &a,const Node &b){
	int v=compare(a.root,b.root);
	if(v!=0)return v<0;
	return a.id<b.id;
}
multiset<Node> hp;
int pre[N];int ans[N];
bool jw;int Pow[N];
void add(int &me,int l,int r,int v){
	me=copy(me);
	if(l==r){
		if(key[me])jw=1;else jw=0;
		key[me]^=1;
		return;
	}
	int mid=(l+r)>>1;
	if(v<=mid){
		add(cl[me],l,mid,v);
		if(jw)add(cr[me],mid+1,r,mid+1);
	}
	else add(cr[me],mid+1,r,v);
	key[me]=(key[cl[me]]+key[cr[me]]*1ll*Pow[mid-l+1])%P;
}
int main(){
	scanf("%d%d",&n,&m);
	Pow[0]=1;
	for(int i=1;i<=M+5;i++)Pow[i]=Pow[i-1]*2ll%P;
	rep(i,1,m){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);p[u].pb(pii(v,w));p[v].pb(pii(u,w));
	}
	int S,T;scanf("%d%d",&S,&T);
	if(S==T){
		printf("0\n1\n%d",S);
		return 0;
	}
	add(dis[S],0,M,0);
	hp.insert(Node(S,dis[S]));
	while(1){
		if(!(hp.size())){
			printf("-1");
			return 0;
		}
		Node now=*hp.begin();
		hp.erase(hp.begin());
		if(now.id==T){
			int rp=key[now.root];rp--;if(rp<0)rp+=P;
			printf("%d\n",rp);
			for(int u=T;u;u=pre[u]){
				ans[++ans[0]]=u;
			}
			printf("%d\n",ans[0]);
			per(i,ans[0],1)printf("%d ",ans[i]);
			return 0;
		}
		else{
			for(int i=0;i<p[now.id].size();i++){
				int y=p[now.id][i].fi;int ww=p[now.id][i].se;
				int tmp=now.root;
				add(tmp,0,M,ww);
				if(!dis[y]||compare(tmp,dis[y])<0){
					dis[y]=tmp;
					hp.insert(Node(y,tmp));
					pre[y]=now.id;
				}
			}
		}
	}
	return 0;
}