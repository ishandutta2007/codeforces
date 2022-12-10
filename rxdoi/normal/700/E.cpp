#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=400000+19;

struct node{
	node *go[26],*par[20],*lnk,*pre;
	int val,Ri,ans;
} Nd[N],*P[N],*rt,*las,*cur=Nd,*Q[N];

char s[N];
vector<pii> E[N];
Vi V[N];
set<int> S;
int cnt[N],dep[N],top[N],fa[N],son[N],sz[N],dfn[N],pt[N];
int n,tot,ans;

void upd(int &x,int y){
	if (y>x) x=y;
}
node *New(int val){
	return cur->val=val,cur++;
}
node *Extend(int x){
	node *p=las,*np=New(p->val+1);
	for (;p&&!p->go[x];p=p->par[0]) p->go[x]=np;
	if (!p){
		np->par[0]=rt;
	} else{
		node *t=p->go[x];
		if (t->val==p->val+1){
			np->par[0]=t;
		} else{
			node *nt=New(p->val+1);
			nt->par[0]=t->par[0];
			t->par[0]=np->par[0]=nt;
			memcpy(nt->go,t->go,sizeof(t->go));
			for (;p&&p->go[x]==t;p=p->par[0]) p->go[x]=nt;
		}
	}
	return np;
}
void dfs(int x){
	dfn[x]=++tot;
	pt[tot]=x;
	sz[x]=1;
	For(i,0,E[x].size()){
		int y=E[x][i].se;
		fa[y]=x;
		dep[y]=dep[x]+1;
		dfs(y);
		sz[x]+=sz[y];
		if (sz[y]>sz[son[x]]) son[x]=y;
	}
}
void dfs(int x,int anc){
	top[x]=anc;
	if (son[x]) dfs(son[x],anc);
	For(i,0,E[x].size()){
		int y=E[x][i].se;
		if (y!=fa[x]&&y!=son[x]) dfs(y,y);
	}
}
int LCA(int x,int y){
	int a=top[x],b=top[y];
	while (a!=b){
		if (dep[a]>dep[b]) swap(a,b),swap(x,y);
		y=fa[b],b=top[y];
	}
	return dep[x]<dep[y]?x:y;
}
void Dfs(int x){
	if (x>1){
		int tmp=-1;
		assert(!S.empty());
		set<int>::iterator it;
		it=S.lower_bound(dfn[x]);
		if (it!=S.end()){
			int z=LCA(pt[*it],x);
			if (Nd[z-1].val>tmp){
				tmp=Nd[z-1].val;
				Nd[x-1].pre=Nd+z-1;
			}
		}
		if (it!=S.begin()){
			--it;
			int z=LCA(pt[*it],x);
			if (Nd[z-1].val>tmp){
				tmp=Nd[z-1].val;
				Nd[x-1].pre=Nd+z-1;
			}
		}
	}
	S.insert(dfn[x]);
	For(i,0,V[x].size()){
		Dfs(V[x][i]);
	}
	S.erase(dfn[x]);
}

int main(){
	rt=las=New(0);
	n=IN();
	scanf("%s",s+1);
	P[n+1]=las;
	for (int i=n;i;i--){
		P[i]=las=Extend(s[i]-'a');
		las->Ri=i;
	}
	for (node *i=Nd;i<cur;i++) cnt[i->val]++;
	For(i,1,N) cnt[i]+=cnt[i-1];
	for (node *i=Nd;i<cur;i++) Q[cnt[i->val]--]=i;
	for (int i=cur-Nd;i>1;i--){
		Q[i]->par[0]->Ri=Q[i]->Ri;
	}
	For(i,1,cur-Nd+1){
		For(j,1,20) if (Q[i]->par[j-1]){
			Q[i]->par[j]=Q[i]->par[j-1]->par[j-1];
		}
	}
	For(i,2,cur-Nd+1){
		node *x=Q[i];
		//x->Ri+1
		//x->val-1
		node *y=P[x->Ri+1];
		for (int j=19;~j;j--) if (y->par[j]){
			if (y->par[j]->val>=x->val-1) y=y->par[j];
		}
		x->lnk=y;
		/*
		if (y!=rt){
			dprintf("[%d,%d]->[%d,%d]\n",x->par[0]->val+1,x->val,y->par[0]->val+1,y->val);
		} else{
			dprintf("[%d,%d]->rt\n",x->par[0]->val+1,x->val);
		}
		*/
		V[x->lnk-Nd+1].pb(x-Nd+1);
	}
	for (node *x=Nd+1;x<cur;x++){
		E[x->par[0]-Nd+1].pb(mp(s[x->Ri+x->par[0]->val],x-Nd+1));
	}
	For(i,1,cur-Nd+1){
		sort(E[i].begin(),E[i].end());
		For(j,1,E[i].size()){
			assert(E[i][j].fi!=E[i][j-1].fi);
		}
	}
	dfs(1);
	dfs(1,1);
	Dfs(1);
	For(i,2,cur-Nd+1){
		Q[i]->ans=max(Q[i]->lnk->ans,Q[i]->pre->ans+1);
		ans=max(ans,Q[i]->ans);
	}
	printf("%d\n",ans);
}