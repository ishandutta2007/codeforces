#include<bits/stdc++.h>
#define inv(x) power(x,Mod-2)
using namespace std;
typedef long long ll;
const ll Mod=1e9+7,mod=1e9+6;
inline ll add(ll a,const ll b){a+=b;if(a>=Mod)a-=Mod;return a;}
inline ll sub(ll a,const ll b){a-=b;if(a<0)a+=Mod;return a;}
inline ll mul(const ll a,const ll b){return a*b%Mod;}
inline ll power(ll x,ll cs)
{
	ll ras=1;
	while(cs)
	{
		if(cs&1) ras=mul(ras,x);
		x=mul(x,x);cs>>=1;
	}
	return ras;
}
ll n,c,f1,f2,f3,ans=1;
struct Solve1
{
	ll A[3][3],B[3][3],C[3][3],P[3][3];
	inline void smul(ll A[3][3],ll B[3][3],ll R[3][3])
	{
		ll i,j,k;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				C[i][j]=0;
				for(k=0;k<3;k++)
				{
					C[i][j]+=A[i][k]*B[k][j];
					C[i][j]%=mod;
				}
			}
		}
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				R[i][j]=C[i][j];
			}
		}
	}
	inline void solve()
	{
		ll cs;
		A[0][2]=A[1][0]=A[1][2]=A[2][1]=A[2][2]=1;
		B[0][0]=B[1][1]=B[2][2]=1;
		cs=n-3;
		while(cs)
		{
			if(cs&1) smul(B,A,B);
			smul(A,A,A);cs>>=1;
		}
		P[0][0]=1;
		smul(P,B,P);
		ans=mul(ans,power(f1,P[0][2]));
		
		memset(P,0,sizeof(P));
		P[0][1]=1;
		smul(P,B,P);
		ans=mul(ans,power(f2,P[0][2]));
		
		memset(P,0,sizeof(P));
		P[0][2]=1;
		smul(P,B,P);
		ans=mul(ans,power(f3,P[0][2]));
		
	}
}s1;
struct Solve2
{
	ll A[5][5],B[5][5],C[5][5],P[5][5];
	inline void smul(ll A[5][5],ll B[5][5],ll R[5][5])
	{
		ll i,j,k;
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				C[i][j]=0;
				for(k=0;k<5;k++)
				{
					C[i][j]+=A[i][k]*B[k][j];
					C[i][j]%=mod;
				}
			}
		}
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				R[i][j]=C[i][j];
			}
		}
	}
	inline void solve()
	{
		ll cs;
		A[0][2]=A[1][0]=A[1][2]=A[2][1]=A[2][2]=A[3][2]=A[3][3]=A[4][4]=1;
		A[4][2]=A[4][3]=2;
		B[0][0]=B[1][1]=B[2][2]=B[3][3]=B[4][4]=1;
		cs=n-3;
		while(cs)
		{
			if(cs&1) smul(B,A,B);
			smul(A,A,A);cs>>=1;
		}
		P[0][4]=1;
		smul(P,B,P);
		ans=mul(ans,power(c,P[0][2]));
		//printf("!!!%I64d\n",P[0][2]);
	}
}s2;
int main()
{
//	freopen("t.in","r",stdin);
	ll i;
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&f1,&f2,&f3,&c);
	s1.solve();
	s2.solve();
	printf("%I64d",ans);
	return 0;
}