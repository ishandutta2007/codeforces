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


const int mod=1e6+3;
struct matrix{
	int a[105][105];
}tmp,a;
int c,w,h,pw[1006],dp[1005];
inline matrix operator * (matrix a,matrix b){
	memset(tmp.a,0,sizeof(tmp.a));
	for(int i=0;i<=w;i++)
		for(int j=0;j<=w;j++){
			int si=0;
			for(int k=0;k<=w;k++){
				tmp.a[i][j]+=(ll)a.a[i][k]*b.a[k][j]%mod;
				si++;
				if(si==100) tmp.a[i][j]%=mod,si=0;
			}
		}
	return tmp;
}
inline matrix exp(matrix x,int  y){
	matrix ans;
	for(int i=0;i<=w;i++)
		for(int j=0;j<=w;j++) ans.a[i][j]=(i==j);
	while(y){
		if(y&1) ans=ans*x;
		x=x*x;y>>=1;
	}
	return ans;
}

int main(){
	read(c,w,h);
	pw[0]=1;
	for(int i=1;i<=w;i++) pw[i]=(ll)pw[i-1]*h%mod;
	dp[0]=1;
	for(int i=1;i<=w;i++){
		for(int j=1;j<=i;j++)
			dp[i]=((ll)dp[i-j]*pw[j-1]%mod+dp[i])%mod;
		dp[i]=(dp[i]+pw[i])%mod;
	}
	if(c<=w) printf("%d\n",dp[c]);
	else{
		for(int i=0;i<=w;i++)
			a.a[0][i]=pw[i];
		for(int i=1;i<=w;i++)
			a.a[i][i-1]=1;
		a=exp(a,c-w);
		int ans=0;
		for(int i=0;i<=w;i++)
			ans=(ans+(ll)a.a[0][i]*dp[w-i]%mod)%mod;
		printf("%d\n",ans);
	}
}