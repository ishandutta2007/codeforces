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
int b[maxn];	
int n, h;
bool check(int x)
{
	for(int j = 1; j <= x; j++)
		b[j] = a[j];
	sort(b + 1, b + x + 1);
	ll ns = 0;
	for(int i = x; i >= 1; i--)
	{
		if((x - i) & 1) continue;
		ns += b[i];
	}	
	return ns <= h;
}
int main()
{

	cin>>n>>h;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid + 1)) l = mid + 1;
		else r = mid; 
	}
	cout<<l<<endl;
	return 0;
 }