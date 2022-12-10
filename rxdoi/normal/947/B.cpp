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

ll A[N],B[N],sum[N],res[N],ans[N];
int n;

int main(){
	n=IN();
	For(i,1,n+1) A[i]=IN();
	For(i,1,n+1) B[i]=IN();
	For(i,1,n+1) sum[i]=sum[i-1]+B[i];
	For(i,1,n+1){
		int x=upper_bound(sum+i,sum+n+1,A[i]+sum[i-1])-sum-1;
		ans[i]++;
		ans[x+1]--;
		A[i]-=sum[x]-sum[i-1];
		res[x+1]+=A[i];
	}
	For(i,1,n+1) ans[i]+=ans[i-1];
	For(i,1,n+1) printf("%I64d ",ans[i]*B[i]+res[i]);
	puts("");
}