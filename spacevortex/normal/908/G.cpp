#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
#define upd(a,b) a=add(a,b)
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int add(int a,const int b){a+=b;if(a>=Mod)a-=Mod;return a;}
int sub(int a,const int b){a-=b;if(a<0)a+=Mod;return a;}
int mul(const int a,const int b){return (ll)a*b%Mod;}
const int N=710;
int n,ans=0;
char s[N];
int a[N],f[N][2],g[N][2];
void trs(int tp,int a,int ai,int b,int bi,int xs)
{
	if(tp==1)
	{
		upd(f[b][bi],mul(xs,f[a][ai]));
		upd(g[b][bi],mul(xs,add(mul(g[a][ai],10),f[a][ai])));
	}
	else
	{
		upd(f[b][bi],mul(xs,f[a][ai]));
		upd(g[b][bi],mul(xs,g[a][ai]));
	}
}
int main()
{
	int i,w,x;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) a[i]=s[i]-'0';
	for(w=1;w<10;w++)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		f[0][1]=1;
		for(i=0;i<n;i++)
		{
			x=a[i+1];
			trs(1,i,0,i+1,0,10-w);
			trs(0,i,0,i+1,0,w);
			trs(0,i,1,i+1,0,min(w,x));
			trs(1,i,1,i+1,0,x-min(w,x));
			trs(w<=x,i,1,i+1,1,1);
		}
		upd(ans,add(g[n][0],g[n][1]));
	}
	printf("%d\n",ans);
	return 0;
}