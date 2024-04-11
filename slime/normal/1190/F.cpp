#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;
typedef long long ll;


inline ll qmul(ll x,ll y,ll mod)
{
    ll ans = (x*y-(ll)((long double)x/mod*y)*mod+mod)%mod;     
	if(ans < 0) ans += mod;
	return ans;
}
ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) res = qmul(res, a, p);
        a = qmul(a, a, p);
        b >>= 1;
    }
    return res;
}

bool miller_Rabin(ll n) {
    if (n == 2) return true;
    int s = 20, i, t = 0;
    ll u = n - 1;
    while (!(u & 1)) {
        t++; u >>= 1;
    }
    while (s--) {
        ll a = rand() % (n - 2) + 2;
        ll x = qpow(a, u, n);
        ll y = 0;
        for (int j = 0; j < t; j++) {
            y = qmul(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return false;
            x = y;
        }
        if (y != 1) return false;
    }
    return true;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll pollard_Rho(ll n, int c) {
    ll i = 1, k = 2, x = rand() % (n - 1) + 1,y = x;
    while (true) {
        i++;
        x = (qmul(x, x, n) + c) % n;
        ll p = gcd((y - x + n) % n, n);
        if (p != 1 && p != n) return p;
        if (y == x) return n;
        if (i == k) {
            y = x;
            k <<= 1;
        }
    }
}
vector<ll> res;
void Fnd(ll n, int c) {
    if (n == 1) return ;
    if (miller_Rabin(n)) {
        res.push_back(n); return ;
    }
    
    ll p = n, k = c;
    while (p >= n) p = pollard_Rho(p, c--);
    Fnd(p, k);
    Fnd(n / p, k);
}
int n;
ll m, p;
ll pr[maxn], ps[maxn];
int cnt = 0;
int tot = 0;
  	ll phi; 
ll dfs(int a, ll b)
{
	if(a == cnt + 1)
	{ 
		if(qpow(p, b, m) == 1)
			return b;
		return -1;
	}
	ll np = 1;
	for(int j = 0; j <= ps[a]; j++)
	{
		ll nr = dfs(a + 1, b * np);
		if(nr != -1)
			return nr;
		np = np * pr[a];
	}
	return -1;
}
ll ans[maxn], ncnt = 0;
int fl[maxn * 20];
int main() 
{
//	cout<<qmul(271818611107, 11688200277601, 614045312225349569)<<endl;
  	cin>>n>>m>>p;
  	Fnd(m, 107);	
  	ll np = res[0];
  	res.clear();	
	phi = m / np * (np - 1);
  	Fnd(phi, 107);
  	sort(res.begin(), res.end());
  	if(!(p % np))
  	{
  		for(int j = 1; j <= m; j++)
  			if((j == 1) || (!(j % np))) continue;
  			else 
  			{
  				ans[ncnt++] = j;
  				if(ncnt >= n) break;
			} 	
		if(ncnt >= n)
			for(int i = 0; i < ncnt; i++)
				cout<<ans[i]<<" ";
		else cout<<-1<<endl;
		return 0;
	}
  	for(int i = 0; i < res.size(); i++)
  	{
		if(i == 0 || res[i] != res[i - 1])
		  	cnt++, 
			pr[cnt] = res[i], 
			ps[cnt] = 0; 
		ps[cnt]++;
	}
	ll u = dfs(1, 1); // p 
	ll dv = phi - u;
//	cout<<dv<<endl;
//	cout<<phi<<" "<<u<<" "<<qpow(p, u, m)<<endl;
//	system("pause");
	if(dv < n) cout<<-1<<endl;
	else
	{
	//	cout<<"!!! "<<u<<" "<<endl;
		const int mxs = 2100000;
		for(int j = 1; j <= mxs && j <= m; j++)
		{
			if(!(j % np)) continue;
			if(qpow(j, u, m) == 1) continue;
			ans[ncnt++] = j;
		//	cout<<"!!!"<<j<<endl;
		//	while(1);
			if(ncnt >= n) break;	
		}	
		if(ncnt < n)
		{	// np = 2
			ncnt = 0;
			if(u <= mxs * 2)
			{
				int nr = 1;
				for(int j = 0; j < u; j++)
					fl[nr] = 1, 
					nr = 1ll * nr * p % m;
				for(int j = 1; j <= m; j++)
					if(!(j % 2)) continue;
					else
					{
						if(fl[j]) continue;
						ans[ncnt++] = j;
						if(ncnt >= n) break;
					}
			}	
			else
			{	//	
				ll dv = m - 1;
				for(int j = 0; j < u; j++)
				{
					ans[ncnt++] = dv, 
					dv = qmul(dv, p, m);
					if(ncnt >= n) break;
				}
			}
		}
		for(int j = 0; j < ncnt; j++)
			printf("%lld ", ans[j]);
	} 
  	return 0;
}
//
//&