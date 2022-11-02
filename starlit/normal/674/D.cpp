#include<bits/stdc++.h>
#define rep for(int i=1;i<=n;i++)
#define W(xx) (t[xx]/de[xx])
const int N=100005;
using namespace std;
typedef long long ll;
int n,m,de[N],f[N];
ll t[N],w[N];
struct pq{
	priority_queue<ll>q,d;
	inline ll top(){
		for(;d.size()&&q.top()==d.top();)
		q.pop(),d.pop();
		return q.size()?q.top():-1e18;
	}
	inline void ins(ll v,int p){p>0?q.push(v):d.push(v);}
}mx[N],mn[N],Mx,Mn;
inline void ins(int x,int p){
	Mx.ins(mx[x].top()+W(x),p),Mn.ins(mn[x].top()-W(x),p);
}
inline void fins(int x,int p){
	mx[f[x]].ins(w[x],p),mn[f[x]].ins(-w[x],p);
}
inline void cut(int x,int y,int p){
	ins(f[f[x]],-1),ins(f[x],-1),ins(x,-1);
	fins(f[x],-1),fins(x,-1),fins(y,p);
	w[f[x]]-=W(x),w[x]-=t[x]-W(x)*(de[x]-1),de[x]+=p;
	w[f[x]]+=W(x),w[x]+=p*W(y)+t[x]-W(x)*(de[x]-1);
	fins(x,1),fins(f[x],1);
	ins(x,1),ins(f[x],1),ins(f[f[x]],1);
}
int u,v,y;
int main(){
	//freopen("dat.txt","r",stdin);
	//freopen("me.txt","w",stdout);
	scanf("%d%d",&n,&m);
	rep scanf("%lld",t+i),de[i]=2;
	rep scanf("%d",f+i),de[f[i]]++;
	rep w[f[i]]+=W(i);
	rep w[i]+=t[i]-W(i)*(de[i]-1),fins(i,1);
	rep ins(i,1);
	for(;m--;){
		scanf("%d",&v);
		if(v>2)printf("%lld %lld\n",-Mn.top(),Mx.top());
		else{
			scanf("%d",&u),y=f[u];
			if(v>1)printf("%lld\n",w[u]+W(y));
			else{
				scanf("%d",&v);
				cut(f[u],u,-1),cut(f[u]=v,u,1);
			}
		}
	}
}