#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<iostream>
#include<cmath>
#include<cctype>
#include<ctime>
#include<map>
#include<vector> 
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define RepD(i,n) for(int i=n;i>=0;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define Forpiter(x) for(int &p=iter[x];p;p=next[p])  
#define Lson (x<<1)
#define Rson ((x<<1)+1)
#define MEM(a) memset(a,0,sizeof(a));
#define MEMI(a) memset(a,127,sizeof(a));
#define MEMi(a) memset(a,128,sizeof(a));
#define INF (2139062143)
#define F (100000007)
#define MAXN (30000+10)
#define MAXD (30000+10)
#define M (30001)
#define MP(a,b) make_pair(a,b) 
#define MAX_d_change (250+10)
#define C (250)
long long mul(long long a,long long b){return (a*b)%F;}
long long add(long long a,long long b){return (a+b)%F;}
long long sub(long long a,long long b){return (a-b+(a-b)/F*F+F)%F;}
typedef long long ll;
int n,d,a[MAXN]={0},s[MAXN]={0},f[MAXN][MAX_d_change*2]={0};
int main()
{
	cin>>n>>d;
	For(i,n)
	{
		int p;
		scanf("%d",&p);
		a[p]++;
	}
	For(i,M) s[i]=s[i-1]+a[i];
	
	int ans=0;
	memset(f,-1,sizeof(f));
	ans=f[d][C]=a[d];
	
	Fork(i,d,M){
		Rep(j,2*C+1)
			if(f[i][j]>=0){
				int dis=j-C+d;
				if (dis>0&&i+dis<=M) {f[i+dis][j]=max(f[i+dis][j],f[i][j]+a[i+dis]);ans=max(ans,f[i+dis][j]);}
				if (i+dis+1<=M) {f[i+dis+1][j+1]=max(f[i+dis+1][j+1],f[i][j]+a[i+dis+1]);ans=max(ans,f[i+dis+1][j+1]);}
				if (dis-1>0&&i+dis-1<=M) {f[i+dis-1][j-1]=max(f[i+dis-1][j-1],f[i][j]+a[i+dis-1]);ans=max(ans,f[i+dis-1][j-1]);}
			}
	}
	cout<<ans<<endl;
	return 0;
}