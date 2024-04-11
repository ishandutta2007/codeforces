#include <bits/stdc++.h>
const int N = 2e5 + 9;
using namespace std;
int n,k,m,x;
int a[N];
int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> k>>m;
		for (int i=1;i<=n;i++)
			a[i]=0;
		for (int i=0;i<m;i++)
		{
			scanf("%d",&x);
			a[x]++;
		}
		if ((n-m)%(k-1)!=0)
		{
			cout<<"No"<<endl;
			continue;
		}
		for (int i=1;i<=n;i++)
		{
			a[i]^=1;
			//cout<<i<<' '<<a[i]<<' '<<a[i-1]<<endl;
			if (a[i]==0 && a[i-1]>=(k-1)/2 && a[i-1]<=(n-m)-(k-1)/2)
			{
				cout<<"Yes"<<endl;
				break;
			}
			a[i]+=a[i-1];
			if (i==n)
				cout<<"No"<<endl;
		}
	}
	return 0;
}