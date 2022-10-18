#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int a[200002][20];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t,i,j;
	cin>>t;
	for (i=1;i<=200000;i++) for (j=0;j<20;j++) a[i][j]=a[i-1][j]+(i>>j&1);
	while (t--)
	{
		int l,r,ans=0;
		cin>>l>>r;
		for (int i=0;i<20;i++) ans=max(ans,a[r][i]-a[l-1][i]);
		//cout<<cal(r,0)<<' '<<cal(l-1,0)<<'\n';
		cout<<r-l+1-ans<<'\n';
	}
}