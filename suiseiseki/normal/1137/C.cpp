#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge {
	int from,n,nxt;
	edge(int from,int n,int nxt) {
		this->from=from;
		this->n=n;
		this->nxt=nxt;
	}
	edge() {}
	friend bool operator ==(edge a,edge b) {
		return a.from==b.from&&a.n==b.n;
	}
	friend bool operator <(edge a,edge b) {
		if(a.from!=b.from)
			return a.from<b.from;
		return a.n<b.n;
	}
} e[5000000];
int head[5000100],ecnt=-1;
void add(int from,int to) {
	e[++ecnt]=edge(from,to,head[from]);
	head[from]=ecnt;
}
int dfn[5000100],low[5000100],cnt=0,del[5000100],dcnt=0;
int f[5000100],sz[5000100],cur[5000100];
int stk[5000100],tp=0,d,stk_[5000100],tp_=0;
bool in[5000100],used[5000100];
bool ava[5000100];
void tarjan(int x) {
	stk[++tp]=x;
	cur[x]=-1;
	while(tp) {
		x=stk[tp];
		if(cur[x]==-1) {
			cur[x]=head[x];
			dfn[x]=++cnt;
			low[x]=dfn[x];
			in[x]=1;
			stk_[++tp_]=x;
		} else {
			low[x]=low[x]<low[e[cur[x]].n]?low[x]:low[e[cur[x]].n];
			cur[x]=e[cur[x]].nxt;
		}

		if(cur[x]!=-1)
			for(int i=cur[x]; ~i; cur[x]=i=e[i].nxt)
				if(!dfn[e[i].n]) {
					stk[++tp]=e[i].n;
					cur[e[i].n]=-1;
					break;
				} else if(in[e[i].n])
					low[x]=low[x]<dfn[e[i].n]?low[x]:dfn[e[i].n];

		if(cur[x]==-1) {
			if(low[x]==dfn[x]) {
				++dcnt;
				int b=tp_;
				do {
					if(ava[stk_[tp_]]&&!used[(stk_[tp_]-1)/d+1]) {
						++sz[dcnt];
						used[(stk_[tp_]-1)/d+1]=1;
					}
					del[stk_[tp_]]=dcnt;
					in[stk_[tp_--]]=0;
				} while(stk_[tp_+1]!=x);
				for(int i=tp_+1; i<=b; ++i)
					used[(stk_[i]-1)/d+1]=0;
			}
			--tp;
		}
	}
}
int D[5000100],q[5000100],l=0,r=0;

char s[100];
int main() {
	memset(head,-1,sizeof(head));
	int n,m,u,v;
	scanf("%d%d%d",&n,&m,&d);

	for(int i=1; i<=m; ++i) {
		scanf("%d%d",&u,&v);
		for(int j=1; j<=d; ++j)
			add((u-1)*d+j,(v-1)*d+j%d+1);
	}
	for(int i=1; i<=n; ++i) {
		scanf("%s",s+1);
		for(int j=1; j<=d; ++j)
			if(s[j]=='1')
				ava[(i-1)*d+j]=1;
	}
	for(int i=1; i<=n*d; ++i)
		if(!dfn[i])
			tarjan(i);
	for(int i=0; i<=ecnt; ++i) {
		e[i].from=del[e[i].from];
		e[i].n=del[e[i].n];
	}
	sort(e,e+ecnt+1);
	unique(e,e+1+ecnt);
	int t=ecnt;
	for(int i=0; i<ecnt; ++i)
		if(!(e[i]<e[i+1])) {
			t=i;
			break;
		}
	ecnt=-1;
	memset(head,-1,sizeof(head));
	for(int i=0; i<=t; ++i)
		if(e[i].n!=e[i].from) {
			++D[e[i].from];
			add(e[i].n,e[i].from);
		}

	for(int i=1; i<=dcnt; ++i)
		if(!D[i])
			q[++r]=i;
	while(l<r) {
		int x=q[++l];
		f[x]+=sz[x];
		for(int i=head[x]; ~i; i=e[i].nxt) {
			--D[e[i].n];
			f[e[i].n]=f[e[i].n]>f[x]?f[e[i].n]:f[x];
			if(!D[e[i].n])
				q[++r]=e[i].n;
		}
	}
	printf("%d\n",f[del[1]]);
	return 0;
}