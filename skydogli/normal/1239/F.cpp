#include<bits/stdc++.h>
using namespace std;
#define MN 500005
int n,m,u[MN],v[MN],deg[MN];
int st[MN],N,inq[MN],vis[MN],cnt;
vector<int>ans,edge[MN];
int T;
void out(){
	//if(T==28303)return;
	if(ans.size()==n){puts("No");return;}
	assert(ans.size());
	puts("Yes");
	printf("%d\n",n-(int)ans.size());
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=0;i<ans.size();++i)vis[ans[i]]=1;
	for(int i=1;i<=n;++i)if(!vis[i])printf("%d ",i);
	for(int i=1;i<=n;++i)vis[i]=0;
	puts("");
}
bool search(int x,int lst=0){//deg2-cir
	assert(deg[x]==2);
	vis[x]=1;
	inq[x]=inq[lst]+1;;
	st[++N]=x;
	bool ok=0;
	int p=0;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(lst==v||deg[v]==1)continue;
		if(inq[v]){
			if(!ok){ok=1,p=v;continue;}
			else {
				if(inq[p]<inq[v])p=v;
				continue;
			}
			while(st[N]!=v){
				ans.push_back(st[N--]);
			}
			ans.push_back(st[N]);
			return 1;
		}
//		if(!ok&&search(v,x))return 1;
	}
	if(p){
		while(st[N]!=p){
			ans.push_back(st[N--]);
		}
		ans.push_back(p);
		return 1;
	}
	else{
		for(int i=0;i<edge[x].size();++i){
			int v=edge[x][i];
			if(lst==v||deg[v]==1)continue;
			if(!inq[v]&&search(v,x))return 1;
		}
	}
	N--;inq[x]=0;
	return 0;
}
int rt,flag;
int lst[MN];
void SEARCH(int x,int lst=0){//1-2-1
	inq[x]=1;st[++N]=x;
//	cerr<<"DFS "<<x<<endl;
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(v==lst||vis[v])continue;
		if(v!=rt)vis[v]=vis[x];
		if(v==rt){
			if(flag)continue;
		//	cerr<<"okk: "<<v<<endl;
			for(int i=1;i<=N;++i){
				ans.push_back(st[i]);	
			}
			flag=1;
		}
	//	else SEARCH(v,x);
	}
//	if(!flag){
	for(int i=0;i<edge[x].size();++i){		
		int v=edge[x][i];
		if(v==lst)continue;
		if(v!=rt)vis[v]=vis[x];
		if(v==rt)continue;
		SEARCH(v,x);
	}
	inq[x]=0;N--;
//	cerr<<"end "<<x<<endl;
}
int q[MN];
void solve(int id){
	scanf("%d%d",&n,&m);
//	if(id==16232&&T==28303)cout<<n<<" "<<m<<endl;
	N=0;ans.clear();
	for(int i=1;i<=n;++i){
		edge[i].clear();
		vis[i]=inq[i]=deg[i]=0;
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&u[i],&v[i]);
	//	if(id==16232&&T==28303)cout<<u[i]<<" "<<v[i]<<"  ";
		edge[u[i]].push_back(v[i]);
		edge[v[i]].push_back(u[i]);
		deg[u[i]]++;deg[v[i]]++;
	}
	for(int i=1;i<=n;++i)deg[i]%=3;
	for(int i=1;i<=n;++i)if(deg[i]==0){ans.push_back(i);out();return;}
	bool ok=0;
	for(int i=1;i<=m;++i){
		if(deg[u[i]]==1&&deg[v[i]]==1){
			ans.push_back(u[i]);ans.push_back(v[i]);
			out();
			return;
		}
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]&&deg[i]==2){
			if(search(i)){
							cerr<<"cir 2: "<<i<<endl;
				out();
				return;
			}
		}
	cerr<<"GG"<<endl;
	for(int i=1;i<=n;++i)vis[i]=inq[i]=0;
	N=0;
	int tot=0;
	rt=0;
	for(int i=1;i<=n;++i){
		if(deg[i]==1)tot++,rt=i;
	}
	assert(tot);
	if(tot>1){
		int l=1,r=0;
		q[++r]=rt;
		for(int i=1;i<=n;++i)vis[i]=lst[i]=0;
		vis[rt]=1;
		while(l<=r){
			int x=q[l++];
		//			cerr<<"? "<<x<<endl;
			if(lst[x]&&deg[x]==1){
				while(x){
					ans.push_back(x);
					x=lst[x];
				}
				out();
				return;
			}
			for(int i=0;i<edge[x].size();++i){
				int v=edge[x][i];
				if(vis[v])continue;
				vis[v]=1;lst[v]=x;q[++r]=v;
			}
		}
		return;
	}
	else{
		ans.push_back(rt);
		//	cerr<<"1line rt: "<<rt<<endl;
		cnt=0;
		for(int i=1;i<=n;++i)vis[i]=inq[i]=0;
		N=0;
		for(int i=0;i<edge[rt].size();++i){
			int v=edge[rt][i];
			if(!vis[v]&&deg[v]==2){
				for(int i=1;i<=n;++i)inq[i]=0;
				N=0;flag=0;
				//		cerr<<"WUHU "<<v<<endl;
				vis[v]=++cnt;SEARCH(v,rt);
				for(int i=1;i<=n;++i)inq[i]=0;
				N=0;
			}
			if(cnt==2)break;
		}
		assert(cnt==2);
		out();
	}
}
int main(){
	//	freopen("FK.in","r",stdin);
	//	freopen("FK.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;++i){
		solve(i);
	}
	return 0;
}