#include<bits/stdc++.h>
using namespace std;
#define int long long
#define MN 500005
#define pii pair<int,int>
#define mp make_pair
#define x first
#define y second
int c[MN],n,m,k;
int F[MN],x[MN],y[MN];
int C[MN],odd[MN],CC[MN];
vector<int>p[MN],edge[MN];
map<pii ,vector<int> >vis;
int Find(int a){
	if(F[a]==a)return a;
	return F[a]=Find(F[a]);
}
void dfs(int x){
	for(int i=0;i<edge[x].size();++i){
		int v=edge[x][i];
		if(C[v]!=-1){
			if(C[x]==C[v])odd[c[x]]=1;
		}
		else{
			C[v]=C[x]^1;
			dfs(v);
		}
	}
}
bool shit;
vector<pii >fk[MN];
void DFS(int x){
	for(int i=0;i<fk[x].size();++i){
		int a=::x[fk[x][i].y],b=::y[fk[x][i].y];
		int fa=Find(a),fb=Find(b);
		int v=fk[x][i].x;
		if(CC[fa]==-1){
			CC[fa]=(C[a]==C[b])^CC[fb];
			assert(fa==v);
			DFS(v);
		}
		else if(CC[fb]==-1){
			CC[fb]=(C[a]==C[b])^CC[fa];
			assert(fb==v);
			DFS(v);
		}
		else{
			if((CC[fa]^C[a])==(CC[fb]^C[b]))shit=1;
		}
	}
}
void solve(int c){
	for(int i=0;i<p[c].size();++i){
		int x=p[c][i];
		if(C[x]==-1){C[x]=0;dfs(x);}
	}
}
signed main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;++i){
		F[i]=i;C[i]=-1;CC[i]=-1;
		scanf("%lld",&c[i]);
		p[c[i]].push_back(i);
	}
	for(int i=1;i<=k;++i)C[i]=CC[i]=-1;
	for(int i=1;i<=m;++i){
		scanf("%lld%lld",&x[i],&y[i]);
		if(c[x[i]]==c[y[i]]){
			edge[x[i]].push_back(y[i]);
			edge[y[i]].push_back(x[i]);
			F[Find(x[i])]=Find(y[i]);
		}
		else{	
			int fa=c[x[i]],fb=c[y[i]];
			if(fa<fb)swap(fa,fb);
			vis[mp(fa,fb)].push_back(i);
		}
	}
	int cnt=0;
	for(int i=1;i<=k;++i){
		solve(i);
		if(!odd[i])cnt++;
	}
	int ans=cnt*(cnt-1)/2;
	for(int i=1;i<=m;++i){
		int fa=c[x[i]],fb=c[y[i]];
		if(odd[fa]||odd[fb])continue;
		if(fa<fb)swap(fa,fb);
		if(fa==fb||vis[mp(fa,fb)].size()==0)continue;
		vector<int>tmp=vis[mp(fa,fb)];vis[mp(fa,fb)].clear();
		shit=0;
		vector<int>p;p.clear();
		for(int i=0;i<tmp.size();++i){
			int a=x[tmp[i]],b=y[tmp[i]];
			int fa=Find(a),fb=Find(b);
			fk[fa].push_back(mp(fb,tmp[i]));
			fk[fb].push_back(mp(fa,tmp[i]));
			p.push_back(fa);p.push_back(fb);
			//			fk.push_back(fb);
			/*			if(CC[fa]==-1&&CC[fb]==-1){
						CC[fa]=0;CC[fb]=(C[a]==C[b]);
						}
						else if(CC[fa]==-1){
						CC[fa]=(C[a]==C[b])^CC[fb];
						}
						else if(CC[fb]==-1){
						CC[fb]=(C[a]==C[b])^CC[fa];
						}
						else{
						if((CC[fa]^C[a])==(CC[fb]^C[b]))shit=1;
						}*/

		}
		for(int i=0;i<p.size();++i)
			if(CC[p[i]]==-1){
				CC[p[i]]=0;
				DFS(p[i]);
			}
		for(int i=0;i<tmp.size();++i){
			int a=x[tmp[i]],b=y[tmp[i]];
			int fa=Find(a),fb=Find(b);
			fk[fa].clear();fk[fb].clear();
			CC[fa]=CC[fb]=-1;
		}
		if(shit)ans--;
		tmp.clear();
	}
	printf("%lld\n",ans);
	return 0;
}