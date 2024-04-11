#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define maxn 200005
#define ll long long
#define ld double
#define mod 998244353
using namespace std;
struct iv
{
	int l, r;
	iv(){l = 0, r = maxn;}
	iv(int a, int b){l = a, r = b;}
};
iv u(iv a, iv b)
{
	return iv(max(a.l, b.l), min(a.r, b.r));
}
struct bit
{
	int d[maxn];
	bit()
	{
		memset(d, 0, sizeof(d));
	}
	int lb(int x)
	{
		return x & (-x);
	}
	void ch(int pl, int num)
	{
		while(pl < maxn)
			d[pl] += num, 
			pl += lb(pl);
	}
	int q(int pl)
	{
		if(pl < 0) return 0;
		int ans = 0;
		while(pl)
			ans += d[pl], 
			pl -= lb(pl);
		return ans;
	}
	int q(iv x)
	{
		if(x.l > x.r) return 0;
		return q(x.r) - q(x.l - 1);
	}
}th[3];	
int n, q;
struct st
{
	set <int> x;
	void ins(int pl)
	{
		x.insert(pl);
	}
	void del(int pl)
	{
		x.erase(pl);
	}
	int qmx()
	{
		if(x.empty()) return 0;
		return *(--x.end());
	}
	int qmi()
	{
		if(x.empty()) return n + 1;
		return *x.begin();
	}
}m[3];
//i win i + 1
int gt(char x)
{
	if(x == 'R') return 2;
	else if(x == 'P') return 1;
	else return 0;
}
int ns[maxn];
char inp[maxn];
int cal()
{
	int ans = n;
	for(int i = 0; i < 3; i++)
	{
		// del l 
	//	cout<<i<<" "<<ans<<endl;
		iv li = iv(m[(i + 2) % 3].qmi(), m[(i + 1) % 3].qmi());
		iv ri = iv(m[(i + 1) % 3].qmx(), m[(i + 2) % 3].qmx());
		ans -= th[i].q(li), 	
	//	cout<<i<<" "<<ans<<endl;
		ans -= th[i].q(ri), 
	//	cout<<i<<" "<<ans<<" "<<ri.l<<" "<<ri.r<<endl;
	//	cout<<th[2].q(5)<<endl;
		ans += th[i].q(u(li, ri));
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", inp + 1);
	for(int i = 1; i <= n; i++)
		ns[i] = gt(inp[i]), 
		m[ns[i]].ins(i), 
		th[ns[i]].ch(i, 1);
	printf("%d\n", cal());
	for(int i = 1; i <= q; i++)
	{
		int pl;
		char s[3];
		scanf("%d", &pl);
		scanf("%s", s);
		int tr = gt(s[0]);
		
		m[ns[pl]].del(pl), 
		th[ns[pl]].ch(pl, -1);
	//	cout<<ns[i]<<" "<<i<<" "<<th[2].q(5)<<endl;
		ns[pl] = tr;
		
		m[ns[pl]].ins(pl), 
		th[ns[pl]].ch(pl, 1);
	//	cout<<ns[i]<<" "<<i<<" "<<th[2].q(5)<<endl;
		printf("%d\n", cal());
	}
	return 0;
} 
/*
2 1 1 5

 
*/