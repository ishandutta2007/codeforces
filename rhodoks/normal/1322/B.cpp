#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
int ans=0;
int b[MAXN];
 
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int j=0;j<30;j++)
	{
		int cnt=0;
		for (int i=0;i<n;i++)
		{
			b[i]=a[i]&((1<<j)-1);
			//cout<<b[i]<<' ';
			if (a[i] & (1<<j))
				cnt++;
		}
		cnt=((LL)(n-cnt)*cnt)&1;
		LL sum=0;
		//cout<<endl;
		sort(b,b+n);
		for (int i=0;i<n;i++)
		{
			sum+=b+n-lower_bound(b,b+n,(1<<j)-b[i]);
			if (b[i]+b[i]>=(1<<j))
				sum--;
		}
		sum/=2;
		sum&=1;
		cnt+=sum;
		//WRT(cnt);
		if (cnt&1)
			ans^=(1<<j);
	}
	cout<<ans<<endl;
	return ~~(0^_^0);
	ans=0;
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			ans^=(a[i]+a[j]);
	cout<<ans;
}