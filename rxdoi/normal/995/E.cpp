#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=10000000;

unordered_map<int,int> step,dis,step2,dis2,pre,pre2;
int Q[N];
int u,v,p,f,w;

int Pow(int a,int b){
	int res=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) res=1ll*res*a%p;
	return res;
}
void gao(int x,int s,int d,int y){
	if (s>100||d>2) return;
	if (!step.count(x)){
		step[x]=s;
		dis[x]=d;
		Q[++f]=x;
		pre[x]=y;
	}
}
void gao2(int x,int s,int d,int y){
	if (s>100||d>2) return;
	if (!step2.count(x)){
		step2[x]=s;
		dis2[x]=d;
		Q[++f]=x;
		pre2[x]=y;
		if (step.count(x)&&step[x]+step2[x]<=200){
			Vi V;
			for (int i=x;i!=u;i=pre[i]){
				int w=pre[i];
				if ((w+1)%p==i) V.pb(1);
				lf ((w+p-1)%p==i) V.pb(2);
				else V.pb(3);
			}
			reverse(V.begin(),V.end());
			for (int i=x;i!=v;i=pre2[i]){
				int w=pre2[i];
				if ((i+1)%p==w) V.pb(1);
				lf ((i+p-1)%p==w) V.pb(2);
				else V.pb(3);
			}
			printf("%d\n",V.size());
			for (int i:V) printf("%d ",i);
			puts("");
			exit(0);
		}
	}
}
void bfs(int s){
	f=1,w=0;
	Q[1]=s;
	step[s]=0;
	dis[s]=0;
	while (f>w){
		int x=Q[++w];
		gao((x+1)%p,step[x]+1,dis[x],x);
		gao((x-1+p)%p,step[x]+1,dis[x],x);
		gao(Pow(x,p-2),step[x]+1,dis[x]+1,x);
	}
}
void bfs2(int s){
	f=1,w=0;
	Q[1]=s;
	step2[s]=0;
	dis2[s]=0;
	while (f>w){
		int x=Q[++w];
		gao2((x+1)%p,step2[x]+1,dis2[x],x);
		gao2((x-1+p)%p,step2[x]+1,dis2[x],x);
		gao2(Pow(x,p-2),step2[x]+1,dis2[x]+1,x);
	}
}

int main(){
	u=IN(),v=IN(),p=IN();
	bfs(u);
	bfs2(v);
}