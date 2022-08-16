#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define cross(i,k) for (register int i=first[k];i;i=last[i])
#define Debug(x) cerr<<#x<<"="<<(x)<<endl
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
inline ll read(){
    ll x=0;int ch=getchar(),f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=-1;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return x*f;
}
const int N = 5010;
int n,a,b,Dp[N][N],dp[N][N],f[N];
char s[N];
int main(){
	n=read(),a=read(),b=read(),scanf("%s",s+1);
	For(i,1,n) For(j,1,n) Dp[i][j]=(s[i]==s[j]?Dp[i-1][j-1]+1:0);
	For(i,1,n) For(j,i,n) dp[i][j]=max(dp[i-1][j],Dp[i][j]);
	For(i,1,n) f[i]=1e9;
	For(i,0,n-1){
		f[i+1]=min(f[i+1],f[i]+a);
		For(j,i+1,n){
			int k=dp[i][j];
			if (j-k<=i) f[j]=min(f[j],f[i]+b);//,printf("%d %d %d\n",i,j,k);
		}
	}
	printf("%d\n",f[n]);
}