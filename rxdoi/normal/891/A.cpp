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

const int N=2000+19;

int f[N][N];
int A[N],n,ans,c;

int main(){
	n=IN();
	For(i,1,n+1){
		A[i]=IN();
		if (A[i]!=1) c++;
	}
	For(i,1,n+1){
		For(j,i,n+1) f[i][j]=__gcd(f[i][j-1],A[j]);
	}
	if (f[1][n]!=1){
		puts("-1");
		return 0;
	}
	ans=(1<<30)-1;
	For(i,1,n+1) For(j,i,n+1)
		if (f[i][j]==1){
			ans=min(ans,j-i+1);
		}
	if (ans==1){
		printf("%d\n",c);
	} else{
		printf("%d\n",ans+c-2);
	}
}