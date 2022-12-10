#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

const int N=2e5+19;

struct node{
	int x,dep;
	bool operator < (const node &B) const{
		return dep>B.dep||dep==B.dep&&x<B.x;
	}
};set<node> S[2];

struct Edge{
	int y,nxt;
} E[N*2];
int las[N],fa[N],num[N],dep[N],leaf[N],vis[N];
int n,cnt,x,rt,tot;
Vi V;

void Add_Edge(int x,int y){
	E[cnt]=(Edge){y,las[x]};las[x]=cnt++;
	E[cnt]=(Edge){x,las[y]};las[y]=cnt++;
}
void dfs(int x){
	for (int i=las[x],y;~i;i=E[i].nxt)
		if ((y=E[i].y)!=fa[x]){
			dep[y]=dep[x]+1;
			fa[y]=x;
			num[x]++;
			dfs(y);
		}
	if (num[x]==0){
		leaf[x]=1;
		vis[x]=1;
	} else{
		tot++;
		S[(num[x]+(x!=rt))&1].insert((node){x,dep[x]});
	}
}

int main(){
	memset(las,-1,sizeof(las));
	n=IN();
	For(i,1,n+1){
		x=IN();
		if (x!=0) Add_Edge(x,i);else rt=i;
	}
	dfs(rt);
	while (tot){
		if (S[0].empty()){
			puts("NO");
			return 0;
		}
		node A=*S[0].begin();
		S[0].erase(S[0].begin());
		vis[A.x]=1;
		for (int i=las[A.x],y;~i;i=E[i].nxt)
			if (!vis[y=E[i].y]){
				S[(num[y]+(y!=rt))&1].erase((node){y,dep[y]});
				num[y]++;
				S[(num[y]+(y!=rt))&1].insert((node){y,dep[y]});
			}
		tot--;
		V.pb(A.x);
	}
	puts("YES");
	For(i,0,V.size()) printf("%d\n",V[i]);
	For(i,1,n+1) if (leaf[i]) printf("%d\n",i);
}