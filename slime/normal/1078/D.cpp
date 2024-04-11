#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <deque>
#define mod 998244353
#define maxn 100005
#define maxnod 4000005
#define maxid 500005
#define ll long long
using namespace std;
int idcnt;
int n;
int tu(int x)
{
	while(x <= 0) x += n;
	while(x > n) x -= n;
	return x;
}
struct iv
{
	int l, r;
	void upd()
	{
		l = tu(l), r = tu(r);
	}
};
bool check(iv a, int b)
{
	if(tu(b - a.l) > tu(a.r - a.l)) return 0;
	return 1;
}
iv u(iv a, iv b)
{
	if(check(b, a.l)) swap(a, b);
	if(check(b, a.l))
	{
		iv n1;
		n1.l = 1, n1.r = n;
		return n1;
	}
	iv n1;
	n1.l = a.l, n1.r = tu(a.l + max(tu(b.r - a.l), tu(a.r - a.l)));
	return n1;
}
struct ST
{
	int l, r;
	ST *ch[2];
	iv ns;
}p[maxnod], *root[17];
int stcnt = 0;
iv ns[maxn];
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r;
	if(l == r) 
	{
		a->ns = ns[l];
		return;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &p[stcnt++], a->ch[1] = &p[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	a->ns = u(a->ch[0]->ns, a->ch[1]->ns);
}
iv q(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
		return a->ns;
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else 
		return 
		u(
			q(a->ch[0], l, mid), 
			q(a->ch[1], mid + 1, r)
		);
}
iv up(iv x, int i)
{
	int l = x.l, r = x.r;
	if(r >= l) return q(root[i], l, r);
	else
	{
		iv n1 = q(root[i], l, n); 
		iv n2 = q(root[i], 1, r);
		return u(n1, n2);
	}
}
bool full(iv x)
{
	return((n == 1) || (tu(x.r - x.l) == n - 1));
}
int r[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &r[i]);
	for(int j = 0; j < 17; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(j == 0)
			{
				ns[i].l = i - r[i], ns[i].r = i + r[i];
				if(2 * r[i] + 1 >= n) ns[i].l = 2, ns[i].r = 1;
				ns[i].upd();
			}
			else
				ns[i] = up(q(root[j - 1], i, i), j - 1);
		}
	//	cout<<j<<endl;
		root[j] = &p[stcnt++];
		bdtree(root[j], 1, n);
	//	cout<<"BUILD"<<endl;
	}
	if(n == 1)
	{
		printf("0\n");
		return 0;
	}
	for(int i = 1; i <= n; i++)
	{
		int ans = 0;
		iv x1;
		x1.l = x1.r = i;
		for(int j = 16; j >= 0; j--)
		{
			if(full(up(x1, j))) continue;
			else
			{
				iv n1 = up(x1, j);
			//	cout<<n1.l<<" "<<n1.r<<" "<<full(n1)<<endl;
			}
			x1 = up(x1, j), ans += (1 << j);
		}
		ans++;
		printf("%d ", ans);
	}
	return 0;
}