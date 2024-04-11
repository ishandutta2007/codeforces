#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int inf=0x3f3f3f;
const int mod=1e9+7;



int n;
int a[N];
int tp[N];
int ans[N];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++)
		{
			if (i%2==1) cout<<-1*abs(a[i])<<" ";else cout<<abs(a[i])<<" ";
		}
		cout<<endl;
	} 
}