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

const int N=300000+19;
const int Top=7000000;

int A[N],B[N];
int sz[Top],son[Top][2];
int tot,n;

void Add(int w){
	int x=0;
	for (int i=29;~i;i--){
		int &u=son[x][w>>i&1];
		if (!u) u=++tot;
		sz[x=u]++;
	}
}
void gao(int w){
	int x=0,ans=0;
	for (int i=29;~i;i--){
		int u;
		if (sz[son[x][w>>i&1]]){
			u=son[x][w>>i&1];
		} else{
			u=son[x][w>>i&1^1];
			ans|=1<<i;
		}
		sz[x=u]--;
	}
	printf("%d ",ans);
}

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1){
		B[i]=IN();
		Add(B[i]);
	}
	For(i,1,n+1){
		gao(A[i]);
	}
	puts("");
}