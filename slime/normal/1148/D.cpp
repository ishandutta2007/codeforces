#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 300005
#define sq 355
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
int a[maxn], b[maxn]; 
struct th
{
	int id, num;
	bool operator < (const th &u)const
	{
		return num < u.num;
	}
}p[maxn];
int main()
{
	cin>>n;
	int cnt[2] = {0, 0};
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &a[i], &b[i]), 
		cnt[0] += (a[i] > b[i]), 
		cnt[1] += (b[i] > a[i]);
	int fl = 0;
	if(cnt[0] > cnt[1])
		fl = 1;
	cout<<max(cnt[0], cnt[1])<<endl;
	int ns = 0;
	for(int i = 1; i <= n; i++)
	{
		int nr = a[i] < b[i];
		if(fl) nr ^= 1;
		if(nr)
			p[ns].id = i, p[ns++].num = a[i];
	}
	sort(p, p + ns);
	if(!fl)
		for(int i = ns - 1; i >= 0; i--)
			printf("%d ", p[i].id);
	else
		for(int i = 0; i < ns; i++)
			printf("%d ", p[i].id);
	return 0;
} 
/*
2 1 1 5

 
*/