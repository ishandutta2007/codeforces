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

const int N=1e5+19;

int A[N],B[N];
int n,ans,c;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	sort(A+1,A+n+1);
	c=1;
	For(i,1,n+1){
		while (c<=n&&A[c]<=A[i]) c++;
		if (c<=n) ans++,c++;
	}
	printf("%d\n",ans);
}