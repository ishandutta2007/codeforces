#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll n,a[MAXN],b[MAXN],c[MAXN];
ll k;
mat mul(mat A,mat B)
{
    mat C(A.size(),vec(B[0].size()));
    for(ll i=0;i<A.size();i++)
        for(ll k=0;k<B.size();k++)
            for(ll j=0;j<B[0].size();j++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MOD;
    return C;
}
mat pow(mat A,ll n)
{
    mat B(A.size(),vec(A.size()));
    for(ll i=0;i<A.size();i++)
        B[i][i]=1;
    while(n>0)
    {
        if(n&1) B=mul(B,A);
        A=mul(A,A);
        n>>=1;
    }
    return B;
}
mat trans(ll h)
{
	mat A(16,vec(16));
	for(ll i=0;i<16;i++)
		for(ll j=0;j<16;j++)
			A[i][j]=0;
	for(ll i=0;i<=h;i++)
	{
		A[i][i]=1;
		if(i>0) A[i-1][i]=1;
		if(i!=h) A[i+1][i]=1;
	}
	return A;
}
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(ll i=0;i<n;i++)
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&c[i]);
	b[n-1]=k;
	mat ans(16,vec(1));
	ans[0][0]=1;
	for(ll i=0;i<n;i++)
	{
		mat B=trans(c[i]);
		B=pow(B,b[i]-a[i]);
		ans=mul(B,ans);
	}
	printf("%I64d\n",ans[0][0]);
	return 0;
}