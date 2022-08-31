//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
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
int n, k;
ll cal(vi x) {
	vi y;
	for (int j = 0; 1; j++) {
		for (int q = 0; q < k + 1; q++)
			y.pb(j);
		if (y.size() >= x.size()) break;
	}
	sort(x.begin(), x.end());
	ll ans = 0;
	for (int i = 0; i < x.size(); i++)
		ans += 1ll * x[i] * y[i];
	return ans;
} 
int x[maxn];
int main() {
	ll ans = 0;
	ll sum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	sort(x + 1, x + n + 1);
	reverse(x + 1, x + n + 1);
	for (int i = 1; i <= n; i++) {
		ans += sum;
		sum += x[i];
		if (sum < 0) {
			vi cur;
			cur.pb(sum);
			for (int j = i + 1; j <= n; j++)
				cur.pb(x[j]);
			ans += cal(cur);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}