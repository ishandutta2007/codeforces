#include<bits/stdc++.h>
#define pb push_back
typedef double db;
const db eps=1e-9;
const int N=100005;
using namespace std;
int n,m,to[N*2],hd[N*2],lk[N],cnt,
f[N],sz[N],de[N],top[N],son[N];
db ans=1e9,sc,sp;
struct dat{
	int k;db tl,tr;int b;
	friend bool operator <(dat x,dat y){
		return x.b+(sc-x.tl)*x.k<y.b+(sc-y.tl)*y.k;
	}
};
vector<dat>ins[N],del[N];
set<dat>S;
set<dat>::iterator il,it,ir;
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}
void dfs(int x){
	sz[x]=1;
	for(int s,i=lk[x];i;i=hd[i])
	if((s=to[i])^f[x])
	f[s]=x,de[s]=de[x]+1,dfs(s),
	sz[x]+=sz[s],sz[son[x]]<sz[s]?son[x]=s:0;
}
void dfss(int x){
	!top[x]?top[x]=x:0;
	top[son[x]]=top[x];
	//cerr<<x<<":"<<de[x]<<' '<<top[x]<<endl;
	for(int i=lk[x];i;i=hd[i])
	if(f[to[i]]==x)dfss(to[i]);
}
int t,c,u,v,w,tp;
inline void lca(int u,int v){
	for(;top[u]^top[v];u=f[top[u]])
	if(de[top[u]]<de[top[v]])swap(u,v);
	w=de[u]<de[v]?u:v;
}
bool cmp(dat x,dat y){
	return x.tl<y.tl;
}
inline void cal(dat x,dat y){
	//cerr<<"?cal "<<x.k<<','<<x.b<<','<<x.tl<<'~'<<x.tr<<' '<<y.k<<','<<y.b<<','<<y.tl<<'~'<<y.tr<<endl;
	if(abs(x.k-y.k)<eps){
		if(abs(y.b-x.b+x.k*x.tl-y.k*y.tl)<eps)
		ans=min(ans,max(x.tl,y.tl));
		return;
	}
	db re=(y.b-x.b+x.k*x.tl-y.k*y.tl)/(x.k-y.k);
	if(re+eps>max(x.tl,y.tl)&&re<min(x.tr,y.tr)+eps)
	ans=min(ans,re);
}
inline void sol(vector<dat>I,vector<dat>D){
	sort(I.begin(),I.end(),cmp);
	sort(D.begin(),D.end(),cmp);
	//cerr<<I.size()<<'&'<<D.size()<<endl;
	//cerr<<S.size()<<endl;
	for(int i=0,j=0;i<I.size()&&j<D.size();)
	if(D[j].tl+eps<I[i].tl){
		//cerr<<"del "<<D[j].k<<"x+"<<D[j].b<<"("<<D[j].tl<<'~'<<D[j].tr<<")\n";
		if(D[j].tl+eps>ans)break;
		sc=D[j].tl;
		D[j].tl+=eps;
		il=ir=it=S.lower_bound(D[j]),ir++;
		assert(it!=S.end());
		//cerr<<"find:"<<it->k<<','<<it->b<<','<<it->tl<<'~'<<it->tr<<endl;
		if(il!=S.begin()&&ir!=S.end())
		cal(*--il,*ir);
		S.erase(it);
		j++;
	}
	else{
		if(I[i].tl+eps>ans)break;
		//cerr<<"ins "<<I[i].k<<"x+"<<I[i].b<<"("<<I[i].tl<<'~'<<I[i].tr<<")\n";
		sc=I[i].tl;
		il=ir=S.lower_bound(I[i]);
		if(il!=S.begin())
		cal(*--il,I[i]);
		if(ir!=S.end())
		cal(I[i],*ir);
		S.insert(I[i++]);
	}
	//cerr<<"clr?"<<sc<<endl;
	S.clear();
	//cerr<<"???\n";
}
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	dfs(1),dfss(1);
	//cerr<<"l1 completed\n";
	for(;m--;){
		scanf("%d%d%d%d",&t,&c,&u,&v);
		lca(u,v),sc=t;
		for(;;u=f[tp]){
			sp=sc,tp=top[u];
			//cerr<<"***"<<tp<<endl;
			if(tp==top[w]){
				sc+=(double)(de[u]-de[w])/c;
				if(sp+eps<sc)
				del[tp].pb({-c,sc-10*eps,sc,de[w]}),
				ins[tp].pb({-c,sp,sc-10*eps,de[u]});
				break;
			}
			sc+=(double)(de[u]-de[f[tp]])/c;
			if(sp+eps<sc)
			del[tp].pb({-c,sc-10*eps,sc,de[f[tp]]}),
			ins[tp].pb({-c,sp,sc-10*eps,de[u]});
		}
		sc+=(double)(de[v]-de[w])/c;
		//cerr<<"??"<<sc<<endl;
		for(;;v=f[tp]){
			sp=sc,tp=top[v];
			del[tp].pb({c,sp,sp,de[v]});
			if(tp==top[w]){
				sc-=(double)(de[v]-de[w])/c;
				//cerr<<"???"<<v<<'/'<<w<<' '<<de[v]<<'/'<<de[w]<<endl;
				ins[tp].pb({c,sc,sp,de[w]});
				break;
			}
			sc-=(double)(de[v]-de[f[tp]])/c;
			ins[tp].pb({c,sc,sp,de[f[tp]]});
		}
	}
	//cerr<<"l2 completed\n";
	for(int i=1;i<=n;i++)//cerr<<"Sol "<<i<<"=======\n",
	sol(ins[i],del[i]);
	if(ans<1e8)printf("%.7lf",ans);
	else puts("-1");
}