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

const int N=5e5+19;

struct edge{
	int x,y,z,id;
	bool operator < (const edge &B) const{
		return z<B.z;
	}
} e[N];

Vi V[N],T[N];
int *stk[20*N],val[20*N];
int pos[N],ans[N],c[N],fa[N],rk[N],B[N];
int n,m,q,ec,top;

int getf(int x){
	return fa[x]==x?x:getf(fa[x]);
}
bool cmp(int i,int j){
	return e[i].z<e[j].z;
}
void bao(int *i){
	++top;
	stk[top]=i;
	val[top]=*i;
}
int Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x==y) return 0;
	if (rk[x]>rk[y]) swap(x,y);
	bao(fa+x);
	fa[x]=y;
	if (rk[x]==rk[y]){
		bao(rk+y);
		rk[y]++;
	}
	return 1;
}
void Resume(int w){
	for (;top>w;top--){
		*stk[top]=val[top];
	}
}

int main(){
	n=IN(),m=IN();
	For(i,1,m+1){
		e[i]=(edge){IN(),IN(),IN(),i};
		B[++*B]=e[i].z;
	}
	sort(e+1,e+m+1);
	For(i,1,m+1) pos[e[i].id]=i;
	sort(B+1,B+*B+1);
	For(i,1,m+1){
		e[i].z=lower_bound(B+1,B+*B+1,e[i].z)-B;
	}
	q=IN();
	For(i,1,q+1){
		Vi V;
		int k=IN();
		For(j,0,k) V.pb(pos[IN()]);
		sort(V.begin(),V.end(),cmp);
		For(j,0,V.size())
			if (j==0||e[V[j]].z!=e[V[j-1]].z){
				T[e[V[j]].z].pb(i);
			}
		::V[i]=V;
	}
	For(i,1,n+1){
		fa[i]=i;
		rk[i]=0;
	}
	For(i,1,q+1) ans[i]=1;
	ec=1;
	For(i,1,*B+1){
		int tmp=top;
		for (int w:T[i]){
			int j;
			for (;c[w]<V[w].size()&&e[j=V[w][c[w]]].z==i;c[w]++){
				if (!Union(e[j].x,e[j].y)) ans[w]=0;
			}
			Resume(tmp);
		}
		for (;ec<=m&&e[ec].z==i;ec++){
			Union(e[ec].x,e[ec].y);
		}
	}
	For(i,1,q+1) puts(ans[i]?"YES":"NO");
}