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

LL a[100][100];
int n,k;

void work()
{
	fflush(stdout);
	LL p;
	cin>>p;
	p-=(1ll<<(2*n-2));
	int pos=1;
	cout<<1<<' '<<1<<endl;
	int c=3;
	for (int i=2*n-3;i>=0;i--)
	{
		if (((p>>i)&1)!=(pos&1) && c<=n+1)
			pos++;
		if (((p>>i)&1)!=(pos&1) && c>n)
			pos--;
		//WRT(pos);
		if (c<=n+1)
			cout<<c-pos<<' '<<pos<<endl;
		else
			cout<<n+1-pos<<' '<<c-(n+1-pos)<<endl;
		c++;
	}
}

int main()
{
	cin>>n;
	for (int i=2;i<=2*n;i++)
	{
		if (i<=n+1)
			for (int j=1;j<=i-1;j++)
				a[i-j][j]=(1ll<<(2*n-i))*(j&1);
			else
				for (int j=i-n;j<=n;j++)
					a[i-j][j]=(1ll<<(2*n-i))*((j-(i-n)+1)&1);
		//for (int j=1;j<=min(i,2*n-i+1);j++)
	} 
	
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)	
			cout<<a[i][j]<<' ';
		cout<<endl;
	}
	fflush(stdout);
	cin>>k;
	fflush(stdout);
	while (k--)
		work();
	
	return ~~(0^_^0);
}