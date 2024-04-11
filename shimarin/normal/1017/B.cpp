#include<bits/stdc++.h>
#define int long long
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,u) for (register int i=first[u];i;i=last[i])
using namespace std;
inline int read(){
    int x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N=1e5+10;
int n,dp[N][2][2];
char s[N],t[N];
main(){
	n=read(),scanf("%s%s",s+1,t+1);
	int ans=0;
	For(i,1,n){
		For(j,0,1)
			For(k,0,1) dp[i][j][k]=dp[i-1][j][k];
		int j=s[i]-'0',k=t[i]-'0';
		if (j==1){ans+=dp[i][0][0];if(!k)ans+=dp[i][0][1];}
			else {ans+=dp[i][1][0];if(!k)ans+=dp[i][1][1];}
		dp[i][j][k]++;
	}
	printf("%I64d",ans);
}