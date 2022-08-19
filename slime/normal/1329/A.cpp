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
int m, n;
int l[maxn]; 
int p[maxn];
ll s[maxn];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		scanf("%d", &l[i]), s[i] = l[i];
	int ed = n;
	for (int i = 1; i <= m; i++)
		s[i] += s[i - 1];
	for (int i = m; i >= 1; i--) {
		int ur = min(ed, n - l[i] + 1);
		if (!ed) {
			cout << -1 << endl;
			return 0;
		}	
		ur = min((ll)ur, s[i - 1] + 1);
		if (ur + l[i] - 1 < ed) {
			cout << -1 << endl;
			return 0;
		}
		p[i] = ur;
		ed = ur - 1; 
	}
	if (ed) cout << -1 << endl;
	else {
		for (int i = 1; i <= m; i++)
			printf("%d ", p[i]);
	}
	return 0;
}