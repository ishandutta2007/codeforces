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
// head
pi uni(pi a, pi b) {
	return mp(max(a.fi, b.fi), min(a.se, b.se));
}
bool chk(pi a) {
	return a.fi <= a.se;
}
int cnt[maxn][2];
char inp[maxn];
const int inf = 1e9;
int n;
bool check(int a) {
	pi u = mp(0, inf), v = mp(0, inf), w = mp(-inf, inf);
	for (int i = 1; i <= n; i++)
		u = uni(u, mp(cnt[i][0] - a, cnt[i][0] + a)), 
		v = uni(v, mp(cnt[i][1] - a, cnt[i][1] + a)), 
		w = uni(w, mp(cnt[i][0] - cnt[i][1] - a, cnt[i][0] - cnt[i][1] + a));	
	pi cur = mp(u.fi - v.se, u.se - v.fi);
	w = uni(w, cur);
	if (chk(u) && chk(v) && chk(w)) return 1;
	return 0;
}
pi get(int a) {
	while (1) {
		pi u = mp(0, inf), v = mp(0, inf), w = mp(-inf, inf);
		for (int i = 1; i <= n; i++)
			u = uni(u, mp(cnt[i][0] - a, cnt[i][0] + a)), 
			v = uni(v, mp(cnt[i][1] - a, cnt[i][1] + a)), 
			w = uni(w, mp(cnt[i][0] - cnt[i][1] - a, cnt[i][0] - cnt[i][1] + a));	
		pi cur = mp(u.fi - v.se, u.se - v.fi);
		w = uni(w, cur);
		for (int j = w.fi; j <= w.se; j++)
			for (int i = v.fi; i <= v.se; i++) {
				int ed = i + j;
				if (i == 0 && ed == 0) continue;
				if (ed >= u.fi && ed <= u.se) {
					cout << a << endl;
					return mp(ed, i);
				}
			}
		a++;
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%s", inp + 1);
		int l = strlen(inp + 1);
		for (int j = 1; j <= l; j++)
			if (inp[j] == 'B') cnt[i][0]++;
			else cnt[i][1]++;
	}
	int l = 0, r = maxn * 2;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	pi cur = get(l);
	while (cur.fi--) printf("B");
	while (cur.se--) printf("N");
	cout << endl;
	return 0;
}