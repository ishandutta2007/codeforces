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

const int N=200000+19;

Vi V[N];
int vis[N],ed[N],pre[N],Q[N];
int n,m,x,draw,s;

void dfs(int x){
	if (x>n&&ed[x-n]){
		puts("Win");
		Vi T;
		for (int i=x;i;i=pre[i]) T.pb(i);
		for (int i=int(T.size())-1;~i;i--){
			printf("%d ",T[i]<=n?T[i]:T[i]-n);
		}
		puts("");
		exit(0);
	}
	vis[x]=1;
	for (int y:V[x]){
		if (!vis[y]){
			pre[y]=x;
			dfs(y);
		} lf (vis[y]==1){
			draw=1;
		}
	}
	vis[x]=2;
}

int main(){
	n=IN(),m=IN();
	For(i,1,n+1) ed[i]=1;
	For(i,1,n+1){
		for (int k=IN();k--;){
			x=IN();
			V[i].pb(x+n);
			V[i+n].pb(x);
			ed[i]=0;
		}
	}
	s=IN();
	dfs(s);
	puts(draw?"Draw":"Lose");
}