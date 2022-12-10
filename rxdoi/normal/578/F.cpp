#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

const int N=1000+19;

char s[N][N];
int id[N][N],A[N][N];
int reid[N*N],fa[N*N];
int n,m,p,num,c,res;

int Det(int n){
	int res=1;
	For(i,1,n+1){
		For(j,1,n+1) A[i][j]=(A[i][j]%p+p)%p;
	}
	For(i,1,n+1){
		if (!A[i][i]){
			For(j,i+1,n+1)
				if (A[j][i]){
					For(k,i,n+1) swap(A[i][k],A[j][k]);
					res=p-res;
				}
		}
		if (!A[i][i]) return 0;
		For(j,i+1,n+1)
			while (A[j][i]){
				int t=A[i][i]/A[j][i];
				For(k,i,n+1) A[i][k]=(A[i][k]-1ll*t*A[j][k]%p+p)%p;
				For(k,i,n+1) swap(A[i][k],A[j][k]);
				res=p-res;
			}
		res=1ll*res*A[i][i]%p;
	}
	return res;
}

int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
int Union(int x,int y){
	x=getf(x),y=getf(y);
	if (x!=y) return fa[x]=y,1;else return 0;
}
void Add_Edge(int x,int y){
	x=reid[getf(x)];
	y=reid[getf(y)];
	A[x][x]++;A[y][y]++;
	A[x][y]--;A[y][x]--;
}
int Solve(int f){
	num=0;
	For(i,0,n+1){
		For(j,0,m+1)
			if ((i+j)%2==f) id[i][j]=++num;
	}
	For(i,1,num+1) fa[i]=i;
	For(i,1,n+1) For(j,1,m+1)
		if (!f){
			if ((i+j)%2==0){
				if (s[i][j]=='\\'){
					if (!Union(id[i-1][j-1],id[i][j])) return 0;
				}
			} else{
				if (s[i][j]=='/'){
					if (!Union(id[i][j-1],id[i-1][j])) return 0;
				}
			}
		} else{
			if ((i+j)%2==0){
				if (s[i][j]=='/'){
					if (!Union(id[i][j-1],id[i-1][j])) return 0;
				}
			} else{
				if (s[i][j]=='\\'){
					if (!Union(id[i-1][j-1],id[i][j])) return 0;
				}
			}
		}
	c=0;
	For(i,1,num+1) if (fa[i]==i) reid[i]=++c;
	memset(A,0,sizeof(A));
	For(i,1,n+1) For(j,1,m+1)
		if (s[i][j]=='*')
			if (!f){
				if ((i+j)%2==0){
					Add_Edge(id[i-1][j-1],id[i][j]);
				} else{
					Add_Edge(id[i][j-1],id[i-1][j]);
				}
			} else{
				if ((i+j)%2==0){
					Add_Edge(id[i][j-1],id[i-1][j]);
				} else{
					Add_Edge(id[i-1][j-1],id[i][j]);
				}
			}
	return Det(c-1);
}

int main(){
	n=IN(),m=IN(),p=IN();
	For(i,1,n+1){
		scanf("%s",s[i]+1);
	}
	res+=Solve(0);
	res+=Solve(1);
	printf("%d\n",res%p);
}