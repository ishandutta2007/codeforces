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

#define MAXN 1001100
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
	friend ostream& operator<<(ostream &out, MOD_LL &a);
	MOD_LL()
	{
		
	}
	
	MOD_LL(LL y)
	{
		x=y;
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
	
	MLL operator^(LL y)
	{
		return mpow(x,y);
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

ostream  &operator<<(ostream &out, MLL &a)
{
	//MRK(); 
	cout<<a.x;
	return out;
}

int n;
vector<int> gift[MAXN];
int cnt[MAXN];
MLL inv[1010];
 
int main()
{
	cin>>n;
	MLL invn2(1);
	invn2/=n;
	invn2/=n;
	inv[1]=invn2;
	for (int i=2;i<=1000;i++)
	{
		inv[i]=inv[MOD%i]*(MOD-MOD/i);
		//cout<<inv[i]<<endl;
		/*
		inv[i]=1;
		inv[i]/=i;
		cout<<inv[i]<<endl;
		*/
	}
	//WRT(inv[2]);
	int k,x;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while (k--)
		{
			scanf("%d",&x);
			gift[i].push_back(x); 
			cnt[x]++;
		}
	}
	MLL ans(0);
	LL c(0);
	for (int i=1;i<=n;i++)
	if (gift[i].size()==1)
	{
		c+=cnt[gift[i][0]];
	}
	else 
	{
		MLL tmp=invn2;
		if (gift[i].size()<=1000)
			tmp=inv[gift[i].size()];
		else
			tmp/=gift[i].size();
		for (auto p:gift[i])
			ans+=tmp*cnt[p];
	}
	c%=MOD;
	ans+=invn2*c;
	cout<<ans;
	return ~~(0^_^0);
}