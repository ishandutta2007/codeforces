#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=102;
int a[N],b[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		int n,i;memset(b,0,sizeof b);
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i],b[abs(a[i])]++;
		int ans=min(1,b[0]);
		for (i=1;i<=100;i++) ans+=min(b[i],2);
		cout<<ans<<'\n';
	}
}