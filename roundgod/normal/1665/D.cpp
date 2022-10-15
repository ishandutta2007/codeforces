#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long 
#define MAXN 40
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t;
int target,hidden;
vector<int> v={4,9,5,7,11,13,17,19,23};
int ask(int x,int y)
{
	printf("? %lld %lld\n",x,y); fflush(stdout);
	int ret;
	scanf("%lld",&ret); 
	//ret=__gcd(0LL+hidden+x,0LL+hidden+y);
	return ret;
}
void answer(int x)
{
	printf("! %lld\n",x); fflush(stdout);
}

int r[MAXN][MAXN],x[MAXN];
int extgcd(int a,int b,int &x,int &y)
{
    int d=a;
    if(b!=0)
    {
        d=extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else
    {
        x=1;
        y=0;
    }
    return d;
}
int mod_inverse(int a,int m)
{
    int x,y;
    extgcd(a,m,x,y);
    return (m+x%m)%m;
}
int solve(vector<P> &v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            r[i][j]=mod_inverse(v[i].S,v[j].S);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        x[i]=v[i].F;
        for(int j=0;j<i;j++)
        {
            x[i]=r[j][i]*(x[i]-x[j]);
            x[i]=x[i]%v[i].S;
            if(x[i]<0) x[i]+=v[i].S;
        }
    }
    int base=1;
    for(int i=0;i<n;i++)
    {
        ans+=base*x[i];
        base*=v[i].S;
    }
    return ans;
}
signed main()
{
	scanf("%lld",&t);
	target=4*9*5*7*11*13*17*19*23;
	while(t--)
	{
		//scanf("%lld",&hidden);
		vector<P> ans;
		ans.resize(9); 
		for(int i=0;i<9;i++) ans[i]=P(0,v[i]); 
		for(int i=1;i<=23;i++)
		{
			int ret=ask(i,i+target);
			for(int j=0;j<9;j++) if(ret%v[j]==0) ans[j].F=(((v[j]-i)%v[j])+v[j])%v[j];
		}
		int ret=solve(ans);
		answer(ret);
	}
	return 0;
}