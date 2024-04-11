#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

class MOD_LL;
typedef MOD_LL MLL;
class MOD_LL
{
public:
	LL x;
	friend ostream& operator<<(ostream &out,MOD_LL &a);
	friend ostream& operator<<(ostream &out,const MOD_LL &a);
	friend istream& operator>>(istream &in,MOD_LL &a);
	MOD_LL()
	{
		
	}
	
	MOD_LL(LL y)
	{
		x=y;
	}
	
	MLL operator=(MLL y)
	{
		x=y.x;
	}
	
	MLL operator+(MLL y)
	{
		return x+y.x>=MOD ? x+y.x-MOD:x+y.x;	
	} 
	
	MLL operator+=(MLL y)
	{
		x+=y.x;
		if (x>=MOD)
			x-=MOD;
		return x;
	}
	
	
	MLL operator-(MLL y)
	{
		return x-y.x<0 ? x-y.x+MOD:x-y.x;	
	} 
	
	MLL operator-=(MLL y)
	{
		x-=y.x;
		if (x<0)
			x+=MOD;
		return x;
	}
	
	MLL operator*(MLL y)
	{
		return x*y.x%MOD;	
	} 
	
	MLL operator*=(MLL y)
	{
		x=x*y.x%MOD;
		return x;
	}
	
	LL mpow(LL x,LL n)
	{
		LL ans=1;
		while (n)
		{
			if (n&1)
				ans=ans*x%MOD;
			x=x*x%MOD;
			n>>=1;
		}
		return ans;
	} 

	MLL inv(LL x)
	{
		return (MLL)mpow(x,MOD-2);
	}
	
	MLL operator^(MLL y)
	{
		return mpow(x,y.x);
	}
	
	MLL operator^=(MLL y)
	{
		x=mpow(x,y.x);
		return x;
	}
	
	MLL operator/(MLL y)
	{
		return (*this)*inv(y.x);
	}
	
	MLL operator/=(MLL y)
	{
		return (*this)=(*this)*inv(y.x);
	}
};

#define mll1 (MLL)1

ostream &operator<<(ostream &out,const MLL &a)
{
	cout<<a.x;
	return out;
}

ostream &operator<<(ostream &out,MLL &a)
{
	cout<<a.x;
	return out;
}

istream& operator>>(istream &in,MOD_LL &a)
{
	cin>>a.x;
	return in;
}

//MLL operator/
int n;
MLL a[MAXN];
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	MLL tmp=1;
	MLL ans=0;
	for (int i=n;i;i--)
	{
		tmp=tmp/a[i]*100;
		ans+=tmp;
	}
	cout<<ans;
	return ~~(0^_^0);
}