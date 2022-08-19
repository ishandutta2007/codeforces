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
char x[15] = {"codeforces"};
int cnt[15];
int main() {
	for (int i = 1; i <= 10; i++)
		cnt[i] = 1;
	int pl = 1;
	ll k;
	cin >> k;
	while (1) {
		ll ns = 1;
		for (int i = 1; i <= 10; i++)
			ns *= cnt[i];
		if (ns >= k) break;
		cnt[pl]++;
		pl++;
		if (pl == 11) pl = 1;
	}
	for (int i = 1; i <= 10; i++)
		while (cnt[i]--)
			printf("%c", x[i - 1]);
	return 0;
}