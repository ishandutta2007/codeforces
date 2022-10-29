#include<algorithm>
#include<iostream>
#include<string>
#include<cctype>
#include<cstdio>
#define rep(i,x,y) for(int i=x; i<=y; ++i)

using namespace std;
typedef long long LL;
const int N=30;
LL a[N][N];
int n,Q;

int main()
{
	cin>>n;
	rep(i,3,n+n-1)
	{
		int x=max(i-n,1),y=i-x;
		LL now=0;
		while(x<=n)
		{
			a[x][y]=now;
			now^=1ll<<(i-3);
			++x,--y;
		}
	}
	rep(i,1,n) rep(j,1,n) printf("%lld%c",a[i][j]," \n"[j==n]);
	fflush(stdout);
	cin>>Q;
	while(Q--)
	{
		LL k;
		cin>>k;
		int x=1,y=1;
		rep(i,1,2*n-2)
		{
			cout<<x<<" "<<y<<endl;
			LL c=k&1ll;
			k>>=1;
			if(y<n && a[x][y+1]==(c<<(x+y+1-3))) ++y;
			else ++x;
		}
		cout<<n<<" "<<n<<endl;
	}
	return 0;
}