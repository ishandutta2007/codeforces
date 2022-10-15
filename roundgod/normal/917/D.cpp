#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int n;
int a[MAXN][MAXN];
int fact[MAXN],invf[MAXN];
int x[MAXN],y[MAXN];
int ans[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int get_det(mat A)
{
	int n=A.size();
	int ans=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			while(A[j][i]!=0)
			{
				int t=1LL*A[i][i]*pow_mod(A[j][i],MOD-2)%MOD;
				for(int k=0;k<n;k++)
				{
					dec(A[i][k],1LL*A[j][k]*t%MOD);
					swap(A[i][k],A[j][k]);
				}
				ans=(MOD-ans)%MOD;
			}
			if(A[i][i]==0) return 0;
		}
		ans=1LL*ans*A[i][i]%MOD;
	}
	return ans;
}
int construct_matrix(int x)
{
    mat lap(n,vec(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            lap[i][j]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            if(a[i][j]) dec(lap[i][j],x),add(lap[i][i],x);
            else dec(lap[i][j],1),add(lap[i][i],1);
        }
    lap.resize(n-1); for(int i=0;i<n-1;i++) lap[i].resize(n-1);
    return get_det(lap);
}
void interpolate()
{
   for(int i=0;i<n;i++)
   {
       x[i]=i+1;
       y[i]=construct_matrix(i+1);
   }
   vector<int> v;
   v.push_back(1);
   for(int i=0;i<n;i++)
   {
       vector<int> tmp=v;
       v.insert(v.begin(),0);
       for(int j=0;j<(int)tmp.size();j++) dec(v[j],1LL*tmp[j]*x[i]%MOD);
   }
   for(int i=0;i<n;i++)
   {
       int coef=1;
       for(int j=0;j<n;j++) if(i!=j) coef=1LL*coef*pow_mod(x[i]-x[j]+MOD,MOD-2)%MOD;
       coef=1LL*coef*y[i]%MOD;
       int last=0;
       for(int j=0;j<(int)v.size();j++)
       {
           int res=v[j]; dec(res,last); res=1LL*res*pow_mod(x[i],MOD-2)%MOD;
           res=(MOD-res)%MOD;
           add(ans[j],1LL*res*coef%MOD);
           last=res;
       }
   }
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100]=pow_mod(fact[100],MOD-2);
    for(int i=99;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    memset(ans,0,sizeof(ans));
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v); u--; v--;
        a[u][v]=a[v][u]=1;
    }
    interpolate();
    for(int i=0;i<=n-1;i++) printf("%d ",ans[i]);
    puts("");
    return 0;
}