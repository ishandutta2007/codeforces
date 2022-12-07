#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define pii pair<int, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define maxn 2019
#define maxs
#define maxnode
#define ls ch[o][0]
#define rs ch[o][1]
#define M 
#define Hash
#define Base 
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define mem(x, v) memset(x, sizeof(x), v)
using namespace std;

int n, k;
char s[maxn];
pii ans[maxn];
int cs = 0;
int a[maxn];

int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		cs = 0;
		scanf("%d%d", &n, &k);
		scanf("%s", s + 1);
		int l = 1, r = n;
		while (l < r){
			while (s[l] == '(') l++;
			while (s[r] == ')') r--;
			if (l < r) ans[++cs] = pii(l, r), reverse(s + l, s + r + 1);
		}
		l = 2, r = (n >> 1) + 1;
		srep(i, 1, k) ans[++cs] = pii(l, r), l += 2, r++;
		printf("%d\n", cs);
		rep(i, 1, cs) printf("%d %d\n", ans[i].fi, ans[i].se);
	}
	return 0;
}