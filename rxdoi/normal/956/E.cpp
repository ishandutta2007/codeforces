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

const int N=10000+19;

struct node{
	int a,b;
	bool operator < (const node &B) const{
		if (b!=B.b) return b>B.b;
		return a<B.a;
	}
} P[N];
int dp[N],sum[N];
int n,l,r,m;

int main(){
	n=IN(),l=IN(),r=IN();
	For(i,1,n+1) P[i].a=IN();
	For(i,1,n+1) P[i].b=IN();
	sort(P+1,P+n+1);
	while (m<n&&P[m+1].b==1) m++;
	For(i,1,m+1) sum[i]=sum[i-1]+P[i].a;
	memset(dp,60,sizeof(dp));
	dp[0]=0;
	For(i,m+1,n+1){
		for (int j=r;j>=P[i].a;j--){
			dp[j]=min(dp[j],dp[j-P[i].a]);
		}
	}
	for (int i=m;i;i--){
		for (int j=r;j>=P[i].a;j--){
			dp[j]=min(dp[j],dp[j-P[i].a]+1);
		}
		for (int j=l;j<=r-sum[i-1];j++)
			if (dp[j]<m-i+1){
				printf("%d\n",i);
				return 0;
			}
	}
	puts("0");
}