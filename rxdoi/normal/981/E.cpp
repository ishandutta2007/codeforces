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

const int p=1e9+7;
const int N=1e4+19;

Vi I[N],O[N];
int dp[N],ans[N];
int n,q,l,r,x;

int main(){
	n=IN(),q=IN();
	For(i,1,q+1){
		l=IN(),r=IN(),x=IN();
		I[l].pb(x);
		O[r].pb(x);
	}
	dp[0]=1;
	For(i,1,n+1){
		for (int x:I[i]){
			for (int j=n;j>=x;j--){
				dp[j]=(dp[j]+dp[j-x])%p;
			}
		}
		For(j,1,n+1) if (dp[j]>0) ans[j]=1;
		for (int x:O[i]){
			for (int j=x;j<=n;j++){
				dp[j]=(dp[j]-dp[j-x]+p)%p;
			}
		}
	}
	Vi V;
	For(i,1,n+1) if (ans[i]) V.pb(i);
	printf("%d\n",V.size());
	for (int i:V) printf("%d ",i);
	puts("");
}