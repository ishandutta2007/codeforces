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

const int N=25;
const int oo=(1<<30)-1;

int A[N][N],B[N][N],P[N];
int n,m,ans=oo,x,y;
Vi V,alb;

pair<int,Vi> calc(){
	int tmp=0;
	Vi res;
	memcpy(B,A,sizeof(A));
	For(w,1,n+1){
		int x=P[w],ok=0;
		For(i,1,n+1) if (i!=x&&B[x][i])
			For(j,i+1,n+1) if (j!=x&&B[x][j]){
				if (!B[i][j]) B[i][j]=B[j][i]=1,ok=1;
			}
		if (ok) res.pb(x);
		tmp+=ok;
	}
	For(i,1,n+1) For(j,i+1,n+1) if (!B[i][j]) return mp(oo,alb);
	return mp(tmp,res);
}

int main(){
	srand(time(0));
	n=IN(),m=IN();
	For(i,0,m){
		x=IN(),y=IN();
		A[x][y]=A[y][x]=1;
	}
	For(i,1,n+1) P[i]=i;
	for (;;){
		random_shuffle(P+1,P+n+1);
		pair<int,Vi> tmp=calc();
		if (tmp.fi<ans) ans=tmp.fi,V=tmp.se;
		if (clock()>0.9*CLOCKS_PER_SEC) break;
	}
	printf("%d\n",ans);
	For(i,0,V.size()) printf("%d ",V[i]);
	puts("");
}