#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;
int q;
long long a[3];
int main()
{
	cin>>q;
	while(q--)
	{
		for (int i=0;i<3;i++) cin>>a[i];
			cout<<(a[0]+a[1]+a[2])/2<<endl;
	}
	return 0;
}