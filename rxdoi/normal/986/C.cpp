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

const int N=(1<<22)+19;

Vi V1[N],V2[N];
int A[N],vis1[N],vis2[N];
int n,m,cnt,res;

void bfs(int s){
	static int Q[10000000];
	int f=1,w=0;
	Q[1]=s;
	vis1[s]=1;
	while (f>w){
		int x=Q[++w];
		if (x<n){
			for (int y:V1[x]){
				if (!vis2[y]) vis2[y]=1,Q[++f]=y+n;
			}
		} else{
			x-=n;
			for (int y:V2[x]){
				if (!vis1[y]) vis1[y]=1,Q[++f]=y;
			}
			For(i,0,m) if (x>>i&1){
				int y=x^(1<<i);
				if (!vis2[y]) vis2[y]=1,Q[++f]=y+n;
			}
		}
	}
}

int main(){
	m=IN(),n=IN();
	For(i,0,n) A[i]=IN();
	For(i,0,n){
		V1[i].pb(((1<<m)-1)^A[i]);
		V2[A[i]].pb(i);
	}
	For(i,0,n) if (!vis1[i]){
		bfs(i);
		res++;
	}
	printf("%d\n",res);
}