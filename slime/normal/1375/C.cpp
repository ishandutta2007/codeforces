//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 300005 /*rem*/
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
int n;
int a[maxn];
int pl[maxn]; 
int main() {
	int t;
	cin >> t;
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if (a[1] < a[n]) printf("YES\n");
		else printf("NO\n");
		/*
		int mn = n;
		int fl = 1;
		for (int i = 1; i <= n - 1; i++) {
			mn = min(mn, a[i]);
			if (mn == n - i + 1) fl = 0;
		}
		if (fl) printf("YES\n");
		else printf("NO\n");
		*/
	}
	return 0;
}