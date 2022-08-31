#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 5005
#define inf 1000000007
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int a[maxn];
int main()
{
	int k;
	cin>>k;
	int nl = 1500, ns = k + nl + 1;
	cout<<nl + 1<<endl;
	cout<<-1<<" ";
	for(int i = 1; i <= nl; i++	)
		a[i] = min(1000000, ns), 
		ns -= a[i], 
		cout<<a[i]<<" ";
	return 0;
 }