//#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
#define maxn 300005
#define ll long long
using namespace std;
deque<int> x;
int A[maxn], B[maxn];
int ns[maxn];
int main()
{
	int n, q;
	cin>>n>>q;
	for(int i = 0; i < n; i++)
	{
		int x1;
		scanf("%d", &x1);
		x.push_back(x1);
	}
	for(int i = 1; i <= n - 1; i++)
	{
		int a = x.front();
		x.pop_front();
		int b = x.front();
		x.pop_front();
		A[i] = a, B[i] = b;
		x.push_front(max(a, b)), 
		x.push_back(min(a, b));
	}
	for(int i = 0; i < n; i++)
		ns[i] = x.front(), 
		x.pop_front();
	for(int i = 0; i < q; i++)
	{
		ll tm;
		scanf("%lld", &tm);
		if(tm <= n - 1) printf("%d %d\n", A[tm], B[tm]);
		else
		{
			tm %= (n - 1);
			if(tm == 0) tm += n - 1;
			printf("%d %d\n", ns[0], ns[tm]);
		}
	}
	return 0;
}