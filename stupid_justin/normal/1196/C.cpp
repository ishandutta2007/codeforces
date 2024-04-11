#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int MOD=1e9+7;
const int INF=100000;
int q,n,k;
long long x[N],y[N],l[N],u[N],r[N],d[N];
long long x_min,y_min,x_max,y_max;
int main()
{
	cin>>q;
	while(q--)
	{
		cin>>n;
		x_min=y_min=-INF;
		x_max=y_max=INF;
		for (int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>l[i]>>u[i]>>r[i]>>d[i];
			if (!l[i]) x_min=max(x_min,x[i]);
			if (!u[i]) y_max=min(y_max,y[i]);
			if (!r[i]) x_max=min(x_max,x[i]);
			if (!d[i]) y_min=max(y_min,y[i]);
		}
		if (x_min>x_max || y_min>y_max) cout<<0<<endl;
		else cout<<1<<" "<<x_min<<" "<<y_min<<endl;
	}
	return 0;
}