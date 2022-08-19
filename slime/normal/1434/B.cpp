//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
set<int> cur;
int tp[maxn];
int ans[maxn];
int pl[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 2 * n; i++) {
		char inp[10];
		scanf("%s", inp);
		if (inp[0] == '+')
			tp[i] = 0;
		else {
			int x;
			scanf("%d", &x);
			pl[x] = i;
			tp[i] = x;
		}
		cur.insert(i);
	}
	for (int i = 1; i <= n; i++) {
		int u = pl[i];
		#define iter set<int>::iterator
		iter h = cur.lower_bound(u);
	//	cout << i << ' ' << u << endl;
		if (h == cur.begin()) {
			cout << "NO" << endl;
			return 0;
		}
		h--;
	//	cout << (*h) << endl;
		if (tp[*h]) {
			cout << "NO" << endl;
			return 0;
		}
		ans[*h] = i;
		cur.erase(h);
		cur.erase(u);
	}
	cout << "YES" << endl;
	for (int i = 1; i <= 2 * n; i++)
		if (tp[i] == 0)
			printf("%d ", ans[i]);
	return 0;
}