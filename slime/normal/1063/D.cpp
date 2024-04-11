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
ll ans = -1; 
ll n, k, l, r;
struct seg
{
	ll k, b;
	seg(){k = b = 0;}
	seg(ll s, ll r){k = s, b = r;}
	seg operator - (seg x)
	{
		return seg(k - x.k, b - x.b);
	}
	void otp()
	{
		cout<<"SEG "<<k<<"X + "<<b<<endl;
	}
};
void upd(ll &ls, ll &rs, seg n1)
{
	if(n1.k == 0)
		if(n1.b < 0) ls = rs + 1;
		else return ;
	else
	{
		if(n1.k > 0) 
		{
			if(n1.b > 0) return ;
			ll nr = (-n1.b) / n1.k;
			if(nr * n1.k < -n1.b) nr++;
			ls = max(ls, nr);
		//	cout<<"@!#!@#@!"<<nr<<" "<<ls<<endl;
		}
		else
		{
			if(n1.b < 0)
			{
				ls = rs + 1;
				return ;
			}
			ll nr = n1.b / (-n1.k);
			rs = min(rs, nr);
		}
	}
}
void work(ll ls, ll rs, seg lb, seg rb)
{
//	cout<<"WORK"<<ls<<" "<<rs<<endl;
//	lb.otp(), rb.otp();
	for(ll i = k; i >= 0; i = k / ((k / i) + 1))
	{
		ll nl = k / (i + 1) + 1;
		ll nr = rs;
		if(i) nr = k / i;
		nl = max(nl, ls), nr = min(nr, rs);
		//cout<<i<<" "<<nl<<" "<<nr<<endl;
		if(nl > nr) 
		{
			if(!i) break;
			continue;
		}
		seg n1 = seg(-i, k + 1);
//		n1.otp(); 	
//cout<<i<<" "<<nl<<" "<<nr<<endl;
		upd(nl, nr, rb - n1);
		upd(nl, nr, n1 - lb);
	//	cout<<nl<<" "<<nr<<endl;
	//	n1.otp();
	//	(rb - n1).otp();
		if(nl > nr) 
		{
			if(!i) break;
			continue;
		}
		ans = max(ans, nr);
		if(i == 0) break;
	}
}
ll th[4];
int main()
{
	scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
	r -= (l - 1);
	if(r <= 0) r += n;
	k--;
	if(k == 0)
	{
		if(r == 1)
		{
			printf("%lld\n", n);
			return 0;
		}
		else
		{
			printf("-1\n");
			return 0;
		}
	}
	th[0] = n;
	th[1] = n + r;
	th[2] = 2 * n - r + 1;
	th[3] = 2 * n + 1;
	sort(th, th + 4);
	for(int i = 0; i < 3; i++)
	{
		if(th[i] < n) continue;
		if(th[i + 1] > 2 * n + 1) continue;
		seg rb = seg(0, 2 * r);
		if(th[i + 1] <= n + r)	
			rb = seg(1, r - n);
		seg lb = seg(0, r);
		if(th[i] >= 2 * n - r + 1)
			lb = seg(1, 2 * r - 2 * n - 1);
		work(th[i], th[i + 1] - 1, lb, rb);
	}
	if(ans == -1) printf("-1\n");
	else printf("%lld\n", ans - n);
	return 0;
} 
/*
2 1 1 5

 
*/