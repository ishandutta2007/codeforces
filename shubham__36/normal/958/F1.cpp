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
	int n,m;
	cin>>n>>m;
	v arr(n+1);
	for (int i=1; i<=n; i++)
		cin>>arr[i];
	v b(m+1,0);
	for (int i=1; i<=m; i++)
		cin>>b[i];
	v count(m+1,0);
	for (int i=1; i<=n; i++)
	{
		count=v(m+1,0);
		for (int j=i; j<=n; j++)
		{
			count[arr[j]]++;
			if (count==b)
			{
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
    return 0; 
}