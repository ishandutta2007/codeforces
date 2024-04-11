#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 500005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
int n;
int a[maxn];
int b[maxn];
struct th
{
	ll s[maxn];
	th(){memset(s, 0, sizeof(s));}
	void init()
	{
		memset(s, 0, sizeof(s));
	}
	void ch(int pl, int num)
	{
		s[pl] += num;
	}
	void upd()
	{
		for(int i = 1; i < maxn; i++)
			s[i] += s[i - 1];
	}
	ll q(int r)
	{
		return s[r];
	}
}p[2];
ll lmx = 0;
int cnt[maxn];
bool check()
{
	memset(cnt, 0, sizeof(cnt));
	p[0].init(), p[1].init();
	sort(a, a + n);
	int tt = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if(a[i] >= n) tt++, a[i]--;//, cout<<"!!!"<<endl;
		int lst = n - 1 - a[i];
		p[0].ch(lst, 1), 
		p[1].ch(lst, lst);
	}
	p[0].upd(), p[1].upd();
	ll ns = 0;
	int fl = 1;
	for(int i = 1; i <= n; i++)
	{
		ns += a[i - 1];
		cnt[n - 1 - a[i - 1]]++;
		if(n - 1 - a[i - 1] < i - 1) ns++;
		ns += cnt[i - 1];
		ll nt = p[0].q(i - 1) * i - p[1].q(i - 1);
	//	cout<<i<<" "<<ns<<" "<<nt<<endl;
		if(ns < nt) 
		{
			fl = 0;
			lmx = max(lmx, nt - ns);
		}
	}
	lmx += tt;
	if(fl)
		return 1;
	else return 0;
}
bool ch(int t)
{
	if(t >= n + 1) return 0;
	for(int i = 0; i < n; i++)
		a[i] = b[i];
	a[n] = t;
	n++;
	int ans = check();
	n--;
	return ans;
} 
int main()
{
	scanf("%d", &n);
	int t2 = 0;
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]), 
		t2 ^= b[i];
	sort(b, b + n);
	for(int i = 0; i < n; i++)
		a[i] = b[i];
	check();
	if((lmx & 1) != (t2 & 1)) lmx++;
	int ls = lmx;
//	cout<<ls<<endl;
	if(!ch(ls)) 
	{
		printf("-1\n");
		return 0;
	}
	int l = ls;
	for(int i = 19; i >= 1; i--)
		if(ch(l + (1 << i))) l += (1 << i);
	for(int i = ls; i <= l; i += 2)
		printf("%d ", i);
	return 0;
}