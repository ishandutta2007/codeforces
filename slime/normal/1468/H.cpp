//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
const int maxn = 1e6 + 5; 
int fl[maxn];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k, m;
		cin >> n >> k >> m;
		for (int j = 1; j <= n; j++)
			fl[j] = 0;
		for (int j = 0; j < m; j++)	{
			int r;
			scanf("%d", &r);
			fl[r] = 1;
		}
		if ((n - m) % (k - 1)) cout << "no" << endl;
		else {
			int cnt = 0, tot = n - m;
			int flag = 0;
			for (int j = 1; j <= n; j++) {
				if (!fl[j]) cnt++;
				else {
					int dv = (k - 1) / 2;
					if (cnt >= dv && cnt <= tot - dv) flag = 1;
				}
			}
			if (flag) cout << "yes" << endl;
			else cout << "no" << endl;
		}
	}
	return 0;
}