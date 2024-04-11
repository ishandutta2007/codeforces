#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int d[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i = 1; i < n; i++)
	{
		int a, b;
		cin>>a>>b;
		d[a]++, d[b]++;
	}
	for(int i = 1; i <= n; i++)	
		if(d[i] == 2)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	return 0;
}