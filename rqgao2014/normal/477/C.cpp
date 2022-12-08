#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<bitset>
#include<functional>
#include<sstream>
#define sqr(x) (x)*(x)
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define vi vector<int>
#define pb push_back
#define ld long double
#define mp make_pair
#define pii pair<int,int>
#define pq priority_queue
#define rf random_shuffle
#define np next_permutation
#define lb lower_bound
#define debuge puts("isok")
#define debug(x) cout<<#x<<"="<<x<<endl
#define SS second
#define FF first
using namespace std;
inline void read(int &x){
	x=0;char ch=getchar(),flag=0;
	while((ch>'9'||ch<'0')&&ch!='-') ch=getchar();
	if(ch=='-') flag=1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	if(flag) x=-x;
}
inline void read(int &x,int &y){read(x),read(y);}
inline void read(int &x,int &y,int &z){read(x),read(y),read(z);}

const int inf=1<<30;
int n,m,from[2005],dp[2005][2005];
char s[2005],t[505];

int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	for(int i=1;i<=n;i++){
		int pt=m;
		for(int j=i;j;j--){
			if(s[j]==t[pt]) pt--;
			if(!pt){from[i]=j;break;}
		}
	}
	int k=0;
	for(int j=1;j<=n;j++)
		dp[0][j]=-inf;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=dp[i-1][j];
			if(j) dp[i][j]=max(dp[i-1][j-1],dp[i][j]);
			if(from[i]&&j-i+from[i]+m-1>=0) dp[i][j]=max(dp[i][j],dp[from[i]-1][j-i+from[i]+m-1]+1);
		}
	}
	for(int i=0;i<=n;i++)
		printf("%d ",dp[n][i]);
	puts("");
	return 0;
}