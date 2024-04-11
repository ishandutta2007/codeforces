#include <bits/stdc++.h>
#include <unistd.h>
#define ll long long
#define inf 1000000007
#define inf16 0x3f3f3f3f
#define INF 1000000000000000007LL
#define VI vector<int>
#define VPII vector<pair<int, int> >
#define VLL vector<ll>
#define PII pair<int, int>
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
using namespace std;

#define int long long
const int MOD = 1e9+7;

int n, ans;

int t[1<<17];
int ab[1<<17];
int de[1<<17];

int res[1<<17];

int f[1<<17];

int fpow(int a, int b)
{
	if(b==0)
		return 1;

	if(b==1)
		return a%MOD;

	if(b%2)
		return a*fpow(a, b-1)%MOD;
	else
	{
		int q = fpow(a, b/2);
		return q*q%MOD;
	}
}

int neg(int a)
{
	return (~a)&((1<<17)-1);
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	f[0] = 0;
	f[1] = 1;

	for(int i = 2; i < 1<<17; ++i)
	{
		f[i] = (f[i-1]+f[i-2])%MOD;
	}

	cin >> n;

	for(int i = 1; i <= n; ++i)
	{
		int x;
		cin >> x;
		++t[x];
	}

	for(int i = 0; i < 1<<17; ++i)
	{
		int m = neg(i);

		for(int j = m; j > 0; j = (j-1)&m)
		{
			ab[i|j] += t[i]*t[j];
		}

		ab[i|0] += t[i]*t[0];
	}

	for(int i = 0; i < 1<<17; ++i)
	{
		de[i] = t[i];
	}

	for(int len = 1; len < 1<<17; len <<= 1) 
	{
    	for(int i = 0; i < 1<<17; i += 2 * len) 
    	{
        	for(int j = 0; j < len; j++) 
        	{
            	int u = de[i+j];
            	int v = de[i+len+j];
            
                de[i+j] = (u+v)%MOD;	
                de[i+len+j] = (u-v+MOD)%MOD;
       		}
   		}
    }

    for(int i = 0; i < 1<<17; ++i)
    {
    	de[i] *= de[i];
    	de[i] %= MOD;
    }

    for(int len = 1; len < 1<<17; len <<= 1) 
	{
    	for(int i = 0; i < 1<<17; i += 2 * len) 
    	{
        	for(int j = 0; j < len; j++) 
        	{
            	int u = de[i+j];
            	int v = de[i+len+j];
            
                de[i+j] = (u+v)%MOD;
                de[i+len+j] = (u-v+MOD)%MOD;
       		}
   		}
    }

    for(int i = 0; i < 1<<17; ++i)
    {
    	de[i] *= fpow(1<<17, MOD-2);
    	de[i] %= MOD;
    }

    for(int i = 0; i < 1<<17; ++i)
    {
    	t[i] = t[i]%MOD*f[i]%MOD;
    	de[i] = de[i]%MOD*f[i]%MOD;
    	ab[i] = ab[i]%MOD*f[i]%MOD;
    }

    for(int i = 0; i < 17; ++i)
    {
    	for(int j = 0; j < 1<<17; ++j)
    	{
    		if(!(j&(1<<i)))
    		{
    			t[j] += t[j|(1<<i)];
    			t[j] %= MOD;
    			ab[j] += ab[j|(1<<i)];
    			ab[j] %= MOD;
    			de[j] += de[j|(1<<i)];
    			de[j] %= MOD;
    		}
    	}
    }

    for(int i = 0; i < 1<<17; ++i)
    {
    	res[i] = t[i]*ab[i]%MOD*de[i]%MOD;
    }

    for(int i = 0; i < 17; ++i)
    {
    	for(int j = 0; j < 1<<17; ++j)
    	{
    		if(!(j&(1<<i)))
 			{
    			res[j] -= res[j|(1<<i)];
    			res[j] += MOD;
    			res[j] %= MOD;
    		}
    	}
    }

    for(int i = 0; i < 17; ++i)
    {
    	ans += res[1<<i];
    	ans %= MOD;
    }

    cout << ans;
}