#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n,q;
string s[200000];
char ch[500010];
vector<int> son[1000100];
int cnt=1,l[1000100],r[1000100],dfn[1000100],pos[1000100];
int tr[1000100],ans[500010];
void add(int x,int y){
	while(x<=cnt){
		tr[x]+=y;
		x+=(x&-x);
	}
}
int Query(int x){
	int ans=0;
	while(x){
		ans+=tr[x];
		x-=(x&-x);
	}
	return ans;
}
bool vis[1000100];
struct SAM{
	int go[1000100][27],par[1000100],val[1000100],last,siz;
	SAM(){
		par[0]=-1;
		siz=1;last=0;
		memset(go,-1,sizeof(go));
	}
	void extend(int x){
		int p=last;
		int np=siz++;val[np]=val[p]+1;
		while(p!=-1 && go[p][x]==-1)go[p][x]=np,p=par[p];
		if(p==-1){
			par[np]=0;
		}else{
			int q=go[p][x];
			if(val[p]+1==val[q])
				par[np]=q;
			else{
				int nq=siz++;val[nq]=val[p]+1;
				memcpy(go[nq],go[q],sizeof(go[q]));
				par[nq]=par[q];
				par[q]=nq;
				par[np]=nq;
				while(p!=-1 && go[p][x]==q){
					go[p][x]=nq;
					p=par[p];
				}
			}
		}
		last=np;
	}
	void build(){
		for(int i=1;i<siz;i++)
			son[par[i]].push_back(i);
	}
	void dfs(int x){
		l[x]=dfn[x]=cnt++;
		for(int i=0;i<son[x].size();i++)
			dfs(son[x][i]);
		r[x]=cnt-1;
	}
	void print(int x){
		vis[x]=1;
		printf("%d %d %d\n",x,par[x],val[x]);
		for(int i=0;i<=26;i++)printf("%d ",go[x][i]);printf("\n");
		for(int i=0;i<=26;i++)
			if(go[x][i]!=-1 && !vis[go[x][i]])print(go[x][i]);
	}
	int tra(string s,bool f){
		int l=s.size();
		int now=0;if(f)add(dfn[now],1);
		for(int i=0;i<l;i++){
			now=go[now][s[i]-'a'];
			if(f)add(dfn[now],1);
		}
		return now;
	}
}sam;
struct query{
	int r,id,k,f;
	query(int _r,int _k,int _id,int _f){
		r=_r,k=_k,id=_id,f=_f;
	}
	query(){
	}
	bool operator <(const query &o)const{
		return r<o.r;
	}
}e[1000100];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%s",ch);
		s[i]=ch;
		int l=s[i].length();
		for(int j=0;j<l;j++)
			sam.extend(ch[j]-'a');
		sam.extend(26);
	}
	for(int i=0;i<n;i++)pos[i]=sam.tra(s[i],0);
	int m=0;
	for(int i=0;i<q;i++){
		int x,y,k;scanf("%d%d%d",&x,&y,&k);
		query p(y-1,k-1,i,1);
		e[m++]=p;
		if(x>1){
			query q(x-2,k-1,i,-1);
			e[m++]=q;
		}
	}
	sort(e,e+m);
	sam.build();
	sam.dfs(0);
//	sam.print(0);
	int j=0;
	for(int i=0;i<n;i++){
		sam.tra(s[i],1);
		while(e[j].r==i){
			ans[e[j].id]+=e[j].f*(Query(r[pos[e[j].k]])-Query(l[pos[e[j].k]]-1));
			j++;
		}
	}
	for(int i=0;i<q;i++)printf("%d\n",ans[i]);
	return 0;
}