#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define MAX 15000001
#define vs vector<string> 
bool check(vs a,vs b)
{
	return (a==b);
}
int main() 
{
	int n,p;
	cin>>n>>p;
	v arr(n+1,0);
	v prefix(n+1,0);
	for (int i=1; i<=n; i++)
	{
		cin>>arr[i];
		prefix[i]=(prefix[i-1]+arr[i])%p;
	}
	ll maxi=0;
	ll sum=0;
	for (int i=n; i>=2; i--)
	{
		sum=(sum+arr[i])%p;
		maxi=max(maxi,(sum+prefix[i-1]));
	}
	cout<<maxi<<endl;

    return 0; 
}