#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100005
#define ll long long
#define ld double
using namespace std;
int mod;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
} 

int tcnt, p[10];
struct vec
{
	int d[10];
	int n1;
	vec(){memset(d, 0, sizeof(d)), n1 = 1;}
	vec operator + (vec a)
	{
		vec r;
		for(int i = 0; i < tcnt; i++)
			r.d[i] = d[i] + a.d[i];
		r.n1 = n1 * (ll)a.n1 % mod;
		return r;
	}
	void otp()
	{
		for(int i = 0; i < tcnt; i++)
			cout<<p[i]<<"^"<<d[i]<<"*";
		cout<<n1<<endl;
	}
};
vec tr(int x)
{
	vec res;
	for(int i = 0; i < tcnt; i++)
	{
		res.d[i] = 0;
		while(!(x % p[i]))
			res.d[i]++, x /= p[i];	
	}		
	res.n1 = x % mod;
	return res;
}
int tr(vec x)
{
	ll n1 = 1;
	for(int i = 0; i < tcnt; i++)
		n1 = n1 * ksm(p[i], x.d[i]) % mod;
	n1 = n1 * x.n1 % mod;
	return n1;
}
struct ST
{
	int l, r;
	int lz, sum;
	short tp; // tp : 0 empty 1 : not
	vec lz2;
	ST *ch[2];
}stp[maxn << 1], *root;
int stcnt = 0;
int x[maxn];
void upd(ST *a)
{
	a->sum = (a->ch[0]->sum + a->ch[1]->sum) % mod;
}
void actlz(ST *a, int b, vec c)
{
	a->lz2 = a->lz2 + c;
	a->lz = 1ll * b * a->lz % mod;
	a->sum = 1ll * b * a->sum % mod;
	a->tp = 1;
//	cout<<"ADDD"<<a->l<<" "<<a->r<<" "<<b<<" "<<a->sum<<endl;
//	a->lz2.otp();
}
void pushdown(ST *a)
{
	if(a->tp)
	{
		//cout<<"PUSH"
		for(int i = 0; i < 2; i++)
			actlz(a->ch[i], a->lz, a->lz2);
		a->lz = 1, 
		a->lz2 = vec(), 
		a->tp = 0;
	}
}
void bdtree(ST *a, int l, int r)
{
	a->l = l, a->r = r, a->tp = 0, a->lz = 1;
	if(l == r)
	{
		a->sum = a->lz = x[l] % mod;
		a->lz2 = tr(x[l]);
		return;
	}
	int mid = (l + r) >> 1;
	a->ch[0] = &stp[stcnt++], a->ch[1] = &stp[stcnt++];
	bdtree(a->ch[0], l, mid), 
	bdtree(a->ch[1], mid + 1, r);
	upd(a);
}
int lz;
vec lz2;
void mult(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
	{
		actlz(a, lz, lz2);
		return;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) mult(a->ch[0], l, r);
	else if(l > mid) mult(a->ch[1], l, r);
	else mult(a->ch[0], l, mid), 
		mult(a->ch[1], mid + 1, r);
	upd(a);
}
void dv(ST *a, int pl)
{
	if(a->l == a->r)
	{
		//a->lz2.otp();
		a->lz2 = a->lz2 + lz2;
		a->sum = tr(a->lz2);
		return;
	}
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if(pl <= mid) dv(a->ch[0], pl);
	else dv(a->ch[1], pl);
	upd(a);
}
int q(ST *a, int l, int r)
{
	if(a->l == l && a->r == r)
		return a->sum;
	pushdown(a);
	int mid = (a->l + a->r) >> 1;
	if(r <= mid) return q(a->ch[0], l, r);
	else if(l > mid) return q(a->ch[1], l, r);
	else return (q(a->ch[0], l, mid) + q(a->ch[1], mid + 1, r)) % mod;
}
int n;
int prs[maxn], bpr[maxn];
int main()
{
	scanf("%d%d", &n, &mod);
	for(int i = 0; i < maxn; i++)
		bpr[i] = 1;
	int phi = mod;
	int ls = mod;
	for(int i = 2; i < maxn; i++)
	{
		if(!bpr[i]) continue;
		for(int j = 2; j * i < maxn; j++)
			bpr[i * j] = 0;
		if(!(mod % i)) 
			p[tcnt++] = i, 
			phi /= i, 
			phi *= (i - 1);
		while(!(ls % i))
			ls /= i;
	}
	if(ls != 1)
		p[tcnt++] = ls, 
		phi /= ls, 
		phi *= (ls - 1);
	for(int i = 1; i <= n; i++)	
		scanf("%d", &x[i]);
	root = &stp[stcnt++];
	bdtree(root, 1, n);
	int qs;
	scanf("%d", &qs);
	for(int i = 0; i < qs; i++)
	{
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		if(t == 1)
		{
			int x;
			scanf("%d", &x);
			lz = x;
			lz2 = tr(x);
			mult(root, l, r);
		} 
		else if(t == 2)
		{
			lz2 = tr(r);
			for(int i = 0; i < tcnt; i++)	
				lz2.d[i] *= -1;
			lz2.n1 = ksm(lz2.n1, phi - 1);
			dv(root, l);
		}
		else
		{
			printf("%d\n", q(root, l, r));
		}
	}
	return 0;
} 
/*5 100
4 1 2 3 5
3
1 2 3 6
1 1 5 1
3 2 4
*/