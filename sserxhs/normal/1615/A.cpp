#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin>>t;
	while (t--)
	{
		int n,r=0,x;
		cin>>n;
		for (int i=1;i<=n;i++) cin>>x,r+=x;
		if (r%n==0) cout<<"0\n"; else cout<<"1\n";
	}
}