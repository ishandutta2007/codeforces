#include<iostream>
#include<algorithm>
#define MAXN 200005
#define mod 998244353
#define LL long long

using namespace std;

int t;
int n, m, k, q;
int a[MAXN][2];
bool flag1[MAXN], flag2[MAXN];
LL cnt, cnt2, cnt3;

LL qpow(LL x, LL y)
{
	LL tmp = x;
	LL res = 1;
	while(y)
	{
		if(y%2 == 1) res = res * tmp % mod;
		y = y >> 1;
		tmp = tmp * tmp % mod;
	} 
	return res;
}

int main()
{
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k >> q;
		for(int i = 1; i <= q; i++)
		    cin >> a[i][0] >> a[i][1];
		cnt = 0; cnt2 = 0; cnt3 = 0;
		for(int i = q; i >= 1; i--)
		{
			if(flag1[a[i][0]] && flag2[a[i][1]]) continue;
			if(cnt2 == n || cnt3 == m) continue;
			cnt++;
			if(!flag1[a[i][0]]) cnt2++;
			if(!flag2[a[i][1]]) cnt3++;
			flag1[a[i][0]] = 1;
			flag2[a[i][1]] = 1;
		}
		cout << qpow(k, cnt) << endl;
		for(int i = q; i >= 1; i--)
		{
			flag1[a[i][0]] = 0;
			flag2[a[i][1]] = 0;
		}
	}
	
	return 0;
}