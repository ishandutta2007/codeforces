#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define ld long double
#define vi vector<int>
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define debuge cerr<<"isok"<<endl
#define debug(x) cerr<<#x<<"="<<x<<endl
#define SS second
#define FF first
#define ls (k<<1)
#define rs (k<<1|1)
#define inf 0x3f3f3f3f
#define clr(a,x) memset(a,x,sizeof(a))
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
using namespace std;

const int N=100005,B=321;
inline void read(int &x){
	x=0;char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
}

int n,m,top,Q,go[N],to[N],s[N],dp[321][N];

int main(){
#ifdef rqgao2014
	freopen("input.txt","r",stdin);
	srand(time(0));
	time_tester(0);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;read(x);read(y);
		go[y]=x;
	}
	for(int i=1;i*B<=n;i++){
		for(int j=(i-1)*B+1;j<=i*B;j++)
			to[go[j]]=j;
//		for(int j=1;j<=i*B;j++) printf("%d ",to[j]);puts("");
		top=0;
		for(int j=i*B;j;j--){
			dp[i][j]=j;
			while(top&&s[top]<=to[j]){
//				if(j==1) printf("%d ",s[top]);
				dp[i][j]=dp[i][s[top]];
				top--;
			}
//			if(j==1)puts("");
			s[++top]=j;
		}
//		for(int j=1;j<=i*B;j++) printf("%d ",dp[i][j]);puts("");
	}
	scanf("%d",&Q);
	for(int i=1;i<=Q;i++){
		int x,y,k;read(x);read(y);
		if(x<=y/B*B) k=dp[y/B][x]; else k=x;
		for(int j=max(y/B*B+1,x);j<=y;j++)
			if(go[j]>=x&&go[j]<=k) k=j;
		printf("%d\n",k);
	}
#ifdef rqgao2014
	time_tester(1);
#endif
	return 0;
}