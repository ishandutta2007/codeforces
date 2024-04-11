#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 1010000
#define MAXM 2010000
#define MOD 998244353  //1000000007
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL n;
LL a[MAXN];
LL A,B;

LL gcd(LL x,LL y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}


LL ans[MAXN][2];
inline void exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	exgcd(b,a%b,x,y);
	LL tem=x;
	x=y;
	y=tem-a/b*y;
}

int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		ans[i][0]-=a[i]/n*n;
		//WRT(ans[i][0])
		a[i]%=n;
	}
	if (n==1)
	{
		cout<<1<<' '<<1<<endl;
		cout<<ans[0][0]<<endl;
		cout<<1<<' '<<1<<endl;
		cout<<-a[0]<<endl;
		cout<<1<<' '<<1<<endl;
		cout<<a[0]<<endl;
		return 0;
	} 
	for (LL i=1;i<=n;i++)
		if (gcd(i,n)==1 && gcd(n-i,n)==1)
		{
			A=i;
			B=n-i;
			break;
		}
	//Ax+By=a
	LL aa,bb,x,y;
	
	exgcd(n,A,x,y);
	//swap(x,y);
	//cout<<n<<' '<<A<<' '<<x<<' '<<y<<endl;
	for (int i=0;i<A;i++)
	{
		ans[i][0]+=-x*a[i]*n;
		ans[i][1]+=-y*a[i]*A;
	}
	
	
	exgcd(n,B,x,y);
	//swap(x,y);
	for (int i=A;i<n;i++)
	{
		ans[i][0]+=-x*a[i]*n;
		ans[i][1]+=-y*a[i]*B;
	}
	
	cout<<1<<' '<<n<<endl;
	for (int i=0;i<n;i++)
		printf("%lld ",ans[i][0]);
	cout<<endl;
	
	
	cout<<1<<' '<<A<<endl;
	for (int i=0;i<A;i++)
		printf("%lld ",ans[i][1]);
	cout<<endl;
	
	
	cout<<A+1<<' '<<n<<endl;
	for (int i=A;i<n;i++)
		printf("%lld ",ans[i][1]);
	cout<<endl;
	return ~~(0^_^0);
}