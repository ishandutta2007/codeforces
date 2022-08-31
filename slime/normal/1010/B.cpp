#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100005
#define mod 998244353
int tp[maxn];
int ask(int a)
{
	cout<<a<<endl;
	fflush(stdout);
	int res;
	cin>>res;
	return res;
}
int main()
{
	int x, n;
	cin>>x>>n;
	for(int i = 1; i <= n; i++)
	{
		tp[i] = ask(1);
		if(!tp[i]) return 0;
	}
	int l = 1, r = x, ns = n + 1;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		int f = ask(mid);
		ns %= n;
		if(ns == 0) ns += n;
		if(tp[ns] == -1) f *= -1;
		if(f == 0) return 0;
		if(f == 1) l = mid + 1;
		else r = mid - 1;
		ns++;
	}
	return 0;	
}