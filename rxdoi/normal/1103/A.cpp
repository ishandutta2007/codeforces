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

const int N=1000+19;

char s[N];
vector<pii> V;
int n;

int work(int A){
	static int B[4],C[4];
	For(i,0,4) B[i]=C[i]=1;
	For(i,0,4){
		For(j,0,4) if (!(A>>(i*4+j)&1)) B[i]=C[j]=0;
	}
	For(i,0,4) if (B[i]) For(j,0,4) if (A>>(i*4+j)&1) A^=1<<(i*4+j);
	For(j,0,4) if (C[j]) For(i,0,4) if (A>>(i*4+j)&1) A^=1<<(i*4+j);
	return A;
}
void dfs(int x,int A){
	if (x==n+1){
		For(i,0,V.size()) printf("%d %d\n",V[i].fi,V[i].se);
		exit(0);
	}
	if (s[x]=='0'){
		For(i,0,3) For(j,0,4)
			if (!(A>>(i*4+j)&1)&&!(A>>((i+1)*4+j)&1)){
				V.pb(mp(i+1,j+1));
				dfs(x+1,work(A|1<<(i*4+j)|1<<((i+1)*4+j)));
				V.pop_back();
			}
	} else{
		For(i,0,4) For(j,0,3)
			if (!(A>>(i*4+j)&1)&&!(A>>(i*4+j+1)&1)){
				V.pb(mp(i+1,j+1));
				dfs(x+1,work(A|1<<(i*4+j)|1<<(i*4+j+1)));
				V.pop_back();
			}
	}
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	dfs(1,0);
}