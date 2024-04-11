//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 1005 /*rem*/
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
int t;
int n;
int a[maxn];
int tp[maxn], cnt[maxn];
vi res;
void act(int t) {
	int pl = 0;
	while (cnt[pl]) pl++;
	res.pb(t);
	cnt[a[t]]--;
	a[t] = pl;
	cnt[pl]++;
}
int main() {
	cin >> t;
	while (t--) {
		res.clear();
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			cnt[a[i]]++;
		}
		for (int x = 0; x < n; x++) 
			for (int j = 0; j < n; j++) {
				if (!cnt[j]) {
					act(j + 1);
					break;
				}
			}
	/*	
		for (int i = 1; i <= n; i++)
			if (tp[i]) act(i);
		for (int i = 1; i <= n; i++)
			cout << a[i] << ' ';
	*/	for (int i = 0; i < n; i++) {
			for (int j = i + 2; j <= n; j++) {
				if (a[j] == i)
					act(j);
			}
			if (a[i + 1] != i) act(i + 1);
		}
		cout << res.size() << endl;
		for (auto v : res) printf("%d ", v);
		cout << endl;
	}
	return 0;
}