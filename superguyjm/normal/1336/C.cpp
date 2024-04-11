#include<algorithm>
#include<cstring>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)
#define mid (l+r>>1)
#define lch (rt<<1)
#define rch (rt<<1|1)

using namespace std;
const int N=3005,mod=998244353;
int n,m;
char S[N],T[N];
int f[N];
int ans;

void inc(int &a,int b) {if((a+=b)>=mod) a-=mod;}

int main()
{
	scanf("%s%s",S+1,T+1);
	n=strlen(S+1),m=strlen(T+1);
	rep(i,1,n) if(S[1]==T[i]||i>m) f[i]=2;
	if(m==1) inc(ans,f[1]);
	rep(i,2,n)
	{
		char c=S[i];
		rep(j,1,n)
		{
			int r=j+i-1;
			if(j>1 && (j-1>m || c==T[j-1])) 
				inc(f[j-1],f[j]);
			if(!(r>m || c==T[r])) f[j]=0;
		}
		if(i>=m) inc(ans,f[1]);
	}
	printf("%d\n",ans);
	return 0;
}