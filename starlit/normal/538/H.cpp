#include<bits/stdc++.h>
const int N=100005;
using namespace std;
int sl,sr,tl,tr,n,m,vis[N],now,
to[N*2],hd[N*2],lk[N],cnt,ans,fin[N];
struct itv{
	int l,r;
	inline void chk(itv a){
		l=max(l,a.l),r=min(r,a.r);
	}
}a[N],I1,I2,ini;
const itv ivl={0,-1};
struct qry{
	int x;bool v;itv s;
}q[N*5];
struct ans{
	itv i1,i2;
	vector<int>v1,v2;
}st[N];
struct pq{
	priority_queue<int>q,d;
	inline void ins(int x,bool v){
		if(v)q.push(x);else d.push(x);
	}
	inline int top(){
		for(;d.size()&&q.top()==d.top();q.pop(),d.pop());
		return q.top();
	}
}Sl,Sr;
void dfs(int x){
	if(vis[x]>2)I2.chk(a[x]),st[ans].v2.push_back(x);
	else I1.chk(a[x]),st[ans].v1.push_back(x);
	for(int s,i=lk[x];i;i=hd[i])
	if(vis[s=to[i]]){
		if(vis[s]==vis[x])
		puts("IMPOSSIBLE"),exit(0);
	}
	else vis[s]=vis[x]^1,dfs(s);
}
inline void add(int u,int v){
	to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;
}int u,v;
bool fl;
int main(){
	//freopen("dat.txt","r",stdin);
	scanf("%d%d%d%d",&sl,&sr,&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d%d",&a[i].l,&a[i].r);
	for(;m--;)
	scanf("%d%d",&u,&v),
	add(u,v),add(v,u);
	m=0;ini={0,sr};
	for(int i=1;i<=n;i++)
	if(!vis[i]){
		I1=I2={0,sr},vis[i]=2,dfs(i);
		st[ans].i1=I1,st[ans].i2=I2;
		ans++;
		if(I1.l>I2.l)swap(I1,I2);
		ini.chk({I1.l,min(I1.r,I2.r)});
		q[m++]={I1.l,1,I2};
		if(I1.r<I2.l)
		q[m++]={I1.r+1,0,I2},
		q[m++]={I1.r+1,1,ivl},
		q[m++]={I2.l,0,ivl},
		q[m++]={I2.l,1,I1};
		else if(I1.r<I2.r)
		q[m++]={I2.l,0,I2},
		q[m++]={I2.l,1,{I1.l,I2.r}},
		q[m++]={I1.r+1,0,{I1.l,I2.r}},
		q[m++]={I1.r+1,1,I1};
		else
		q[m++]={I2.l,0,I2},
		q[m++]={I2.l,1,I1},
		q[m++]={I2.r+1,0,I1},
		q[m++]={I2.r+1,1,I2};
	}
	sort(q,q+m,[](qry x,qry y){
		return x.x==y.x?x.v>y.v:x.x<y.x;
	});
	q[m].x=sr+1;
	for(int i=0;i<m;i++){
		//cerr<<i<<".."<<q[i].x<<' '<<q[i].v<<'('<<
		//q[i].s.l<<','<<q[i].s.r<<")\n";
		Sl.ins(q[i].s.l,q[i].v);
		Sr.ins(-q[i].s.r,q[i].v);
		//for(auto j:Sl)cerr<<j<<"?";cerr<<endl;
		now=q[i].x;
		if(now>=ini.l&&now<=ini.r&&q[i].x<q[i+1].x){
			tl=max(sl-q[i+1].x+1,Sl.top());
			tr=min(sr-q[i].x,-Sr.top());
			if(tl<=tr){
				tr=max(q[i].x,sl-tl);
				printf("POSSIBLE\n%d %d\n",tl,tr);
				for(int i=0;i<ans;i++){
					fl=(st[i].i1.l<=tl&&tl<=st[i].i1.r&&
					st[i].i2.l<=tr&&tr<=st[i].i2.r);
					for(int j:st[i].v1)
					fin[j]=2-fl;
					for(int j:st[i].v2)
					fin[j]=1+fl;
				}
				for(int i=1;i<=n;i++)
				printf("%d",fin[i]);
				return 0;
			}
		}
	}
	puts("IMPOSSIBLE");
}