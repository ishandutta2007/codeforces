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
ll x[3];
int ls = -1;
bool chk(int ls) {
	ll mx = 0;
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++)
			if (x[i] == x[j])
				return 0;
	for (int i = 0; i < 3; i++)
		if (chkmax(mx, x[i])) ;
	if (ls == -1 || x[ls] != mx) return 1;
	ll d1 = (x[ls] - x[(ls + 1) % 3]), d2 = (x[ls] - x[(ls + 2) % 3]);
	if (d1 > d2) swap(d1, d2);
	if (d2 % d1) return 1;
	ll cur = d2 / d1;
	if ((cur & (-cur)) == cur) return 0;
	return 1;
}
int main() {
	for (int i = 0; i < 3; i++)
		cin >> x[i];
//	ll y[3] = {x[0], x[1], x[2]};
	cout << "First" << endl;
	fflush(stdout);
	ll q = 1e10;
	cout << q << endl;
	fflush(stdout);
	int p;
	cin >> p;
	x[p - 1] += q;
	cout << 3 * x[p - 1] - x[0] - x[1] - x[2] << endl;
	fflush(stdout);
	int r;
	cin >> r;
	int e = 6 - r - p - 1;
	cout << x[p - 1] - x[e] << endl;
	fflush(stdout);
	int m;
	cin >> m;
	assert(m == 0);
	return 0;
}