#include <iostream>
#include <fstream>
#define MAXN 100100
using namespace std;
typedef long long ll;
ll a[MAXN];
ll b[MAXN];
ll prefix[MAXN];
ll ans;
ll l, h;
int N;
int main()
{
	cin>>N;
	ans = -1e16;
	for(int i=1; i<=N; i++)
	{
		cin>>a[i];
	}
	for(int i=1; i<N; i++)
	{
		b[i] = a[i+1]-a[i];
		if(b[i]<0)
		{
			b[i] = -b[i];
		}
		if(i%2==0)
		{
			prefix[i] = prefix[i-1] + b[i];
		}
		else
		{
			prefix[i] = prefix[i-1] - b[i];
		}
	}
	for(int i=N-1; i>=1; i--)
	{
		l = min(l, prefix[i]);
		h = max(h, prefix[i]);
		if(i%2==1)
		{
			ans = max(ans, prefix[i-1]-l);
		}
		else
		{
			ans = max(ans, h-prefix[i-1]);
		}
	}
	cout<<ans<<endl;
}