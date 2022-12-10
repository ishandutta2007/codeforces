#include<bits/stdc++.h>

#define For(i,x,y) for (int i=x;i<y;i++)
#define Rep(i,x,y) for (int i=x,_=y;i<=_;i++)
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

const int S=320;
const int N=100000+19;
const int oo=(1<<30)-1;

int L[S],R[S],mx[S],mn[S],Ti2[S];
int pos[S][N],T2[S][N];
int fa[N],sz[N],val[N],id[N],las[N],T1[N],A[N];
int n,m,o,Ql,Qr,x,ans,Ti1;

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y){
		fa[x]=y;
		sz[y]+=sz[x];
	}
}
void Rebuild(int w){
	Ti1++;
	Ti2[w]++;
	mx[w]=0;
	mn[w]=0;
	For(i,L[w],R[w]+1){
		int x=A[i];
		mx[w]=max(mx[w],x);	
		if (T1[x]!=Ti1) T1[x]=Ti1,las[x]=0;
		if (!las[x]){
			las[x]=i;
			fa[i]=i;
			sz[i]=1;
			val[i]=x;
			T2[w][x]=Ti2[w];
			pos[w][x]=i;
		} else{
			fa[i]=las[x];
			sz[fa[i]]++;
		}
	}
}
void Recover(int w){
	For(i,L[w],R[w]+1){
		A[i]=val[getf(i)]-mn[w];
//		assert(A[i]>=1&&A[i]<N);
	}
}

int main(){
//	freopen("E.in","r",stdin);
//	freopen("E.out","w",stdout);
	n=IN(),m=IN();
	For(i,1,n+1) id[i]=(i-1)/S+1;
	for (int i=1;i<=n;i++) R[id[i]]=i;
	for (int i=n;i>=1;i--) L[id[i]]=i;
	For(i,1,n+1) A[i]=IN();
	For(i,1,id[n]+1) Rebuild(i);
	while (m--){
		o=IN(),Ql=IN(),Qr=IN(),x=IN();
		if (o==1){
			if (id[Ql]==id[Qr]){
				Recover(id[Ql]);
				Rep(i,Ql,Qr) if (A[i]>x) A[i]-=x;
				Rebuild(id[Ql]);
			} else{
				Recover(id[Ql]);
				Recover(id[Qr]);
				Rep(i,Ql,R[id[Ql]]) if (A[i]>x) A[i]-=x;
				Rep(i,L[id[Qr]],Qr) if (A[i]>x) A[i]-=x;
				For(i,id[Ql]+1,id[Qr]){
					if (2*x>=mx[i]){
						Rep(j,x+1,mx[i]){
							int w=j+mn[i];
//							assert(w-x>=1);
//							assert(w>=1&&w<N);
							if (T2[i][w]==Ti2[i]&&pos[i][w]){
								if (T2[i][w-x]!=Ti2[i]){
									T2[i][w-x]=Ti2[i];
									pos[i][w-x]=0;
								}
								if (!pos[i][w-x]){
									pos[i][w-x]=pos[i][w];
									val[pos[i][w]]=w-x;
								} else{
									Union(pos[i][w],pos[i][w-x]);
								}
								pos[i][w]=0;
							}
						}
						mx[i]=min(mx[i],x);
					} else{
						for (int j=x;j;j--){
							int w=j+mn[i];
							if (T2[i][w]==Ti2[i]&&pos[i][w]){
								if (T2[i][w+x]!=Ti2[i]){
									T2[i][w+x]=Ti2[i];
									pos[i][w+x]=0;
								}
								if (!pos[i][w+x]){
									pos[i][w+x]=pos[i][w];
									val[pos[i][w]]=w+x;
								} else{
									Union(pos[i][w],pos[i][w+x]);
								}
								pos[i][w]=0;
							}
						}
						mx[i]-=x;
						mn[i]+=x;
					}
				}
				Rebuild(id[Ql]);
				Rebuild(id[Qr]);
			}
		} else{
			ans=0;
			if (id[Ql]==id[Qr]){
				Recover(id[Ql]);
				For(i,Ql,Qr+1) if (A[i]==x) ans++;
			} else{
				Recover(id[Ql]);
				Recover(id[Qr]);
				Rep(i,Ql,R[id[Ql]]) if (A[i]==x) ans++;
				Rep(i,L[id[Qr]],Qr) if (A[i]==x) ans++;
				For(i,id[Ql]+1,id[Qr]){
					int w=x+mn[i];
					if (w>=1&&w<N&&T2[i][w]==Ti2[i]) ans+=sz[pos[i][w]];
				}
			}
			printf("%d\n",ans);
		}
	}
}