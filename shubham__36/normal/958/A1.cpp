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
	int n;
	cin>>n;
	vs a(n);
	vs b(n);
	for (int i=0; i<n; i++)
		cin>>a[i];
	for (int i=0; i<n; i++)
		cin>>b[i];
	vs c=a;
	if (c==b)
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[n-1-j][i];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	//cout<<c[0]<<endl;
	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[n-1-i][n-1-j];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[j][n-1-i];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[i][n-1-j];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}
	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[n-1-i][j];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}

	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[n-1-j][n-1-i];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}

	c=a;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
			c[i][j]=a[j][i];
	}
	if (check(b,c))
	{
		cout<<"Yes"<<endl;
		return 0;
	}

	cout<<"No"<<endl;
    return 0; 
}