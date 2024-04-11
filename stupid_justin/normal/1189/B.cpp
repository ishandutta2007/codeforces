#include <bits/stdc++.h>
#define N 1e5+5
#define inf 0x3f3f3f3f
#define MOD1e9+7
using namespace std;
int n,one=0,zero=0;
int a[100005];
int main() {
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if (a[n-1]>=a[n-2]+a[n-3])
	{
		cout<<"NO"<<endl;
	}
	else
	{
		cout<<"YES"<<endl;
		for (int i=0;i<n-2;i++) cout<<a[i]<<" ";
		cout<<a[n-1]<<" "<<a[n-2]<<endl;
	}
}