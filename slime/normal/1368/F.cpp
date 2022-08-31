//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
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
int tp[maxn];
int fl[maxn];
int main() {
	int mn = 1e9, pl = 0;
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++) {
		int ns = (n / k);
		if (n % k) ns++;
		ns += (k - 1);
		if (chkmin(mn, ns)) pl = k;
	}
	for (int i = 1; i <= n; i += pl) 
		for (int j = i; j < (i + pl) && j <= n; j++) {
			if (j == i + pl - 1 || j == n) fl[j] = 0;
			else fl[j] = 1;
		}
	while (1) {
		int tot = 0;
		for (int i = 1; i <= n; i++)
			tot += tp[i];
		if (tot >= n - mn) {
			cout << 0 << endl;
			break;
		}
		cout << pl << ' ';
		int cnt = pl;
		for (int i = 1; i <= n; i++)
			if (!tp[i] && fl[i]) {
				cnt--;
				cout << i << ' ';
				tp[i] = 1;
				if (cnt == 0) break;
			}
		cout << endl;
		fflush(stdout);	
		int res;
		cin >> res;
		for (int i = 1; i <= pl; i++) {
			tp[res] = 0;
			res++;
			if (res > n) res = 1;
		}
	}
	return 0;
}