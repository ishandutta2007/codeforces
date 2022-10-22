#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>10) print(x/10);
	putchar((x%10)|48);
}
int dp[80][80][2];
int T;
int n,k;
struct node{
	PII s;int id;
	bool operator <(const node &x)const{
		return s>x.s;
	}
}a[100];
int m;
vector<int>op1,op2,op3;
void dfs(int x,int j,int op){
//	printf("X:%d,j:%d,op:%d\n",x,j,op);
	if(x==n+1) return ;
	if(op){
		if(dp[x][j][op]==dp[x+1][j][op]+a[x].s.fi*(k-1)){
			op2.pb(x);dfs(x+1,j,op);
		}
		else if(dp[x][j][op]==dp[x+1][j][0]+a[x].s.fi*(k-1)+a[x].s.se){
			op3.pb(x);dfs(x+1,j,0);
		}
		else if(j&&dp[x][j][op]==dp[x+1][j-1][op]+a[x].s.fi*(j-1)+a[x].s.se){
			dfs(x+1,j-1,op);op1.pb(x);
		}
	}
	else{
		if(dp[x][j][0]==dp[x+1][j][0]+a[x].s.fi*(k-1)){
			op2.pb(x);dfs(x+1,j,0);
		}
		else if(j&&dp[x][j][0]==dp[x+1][j-1][0]+a[x].s.fi*(j-1)+a[x].s.se){
			dfs(x+1,j-1,0);op1.pb(x);
		}
	}
}
vector<int>ans;
int main(){
	T=read();
	while(T--){
		op1.clear(),op2.clear(),op3.clear();
		n=read(),k=read();
		for(int i=1;i<=n;++i) a[i].s.se=read(),a[i].s.fi=read(),a[i].id=i;
		sort(a+1,a+n+1);
		memset(dp,-0x3f,sizeof(dp));
		dp[n+1][0][0]=0;
		int ans=0;
		for(int i=n;i>=1;--i){
//			printf("%d %d %d\n",a[i].s.se,a[i].s.fi,a[i].id);
			for(int j=0;j<=(n-i+1)&&j<k;++j){
				dp[i][j][0]=dp[i+1][j][0]+a[i].s.fi*(k-1);
				
				dp[i][j][1]=max(dp[i+1][j][1]+a[i].s.fi*(k-1),dp[i+1][j][0]+a[i].s.fi*(k-1)+a[i].s.se);
				
				if(j){
					dp[i][j][0]=max(dp[i][j][0],dp[i+1][j-1][0]+a[i].s.fi*(j-1)+a[i].s.se);
					dp[i][j][1]=max(dp[i][j][1],dp[i+1][j-1][1]+a[i].s.fi*(j-1)+a[i].s.se);
				}
//				printf("i:%d,j:%d,dp:%d,%d\n",i,j,dp[i][j][0],dp[i][j][1]);
			}
		}
		dfs(1,k-1,1);
		printf("%d\n",op1.size()+op2.size()*2+1);
		for(int i=0;i<op1.size();++i){
			printf("%d ",a[op1[i]].id);
		}
		for(int i=0;i<op2.size();++i) printf("%d %d ",a[op2[i]].id,-a[op2[i]].id);
		printf("%d\n",a[op3[0]].id);
//		printf("%d\n",dp[1][k-1][1]);
	}
	return 0;
}