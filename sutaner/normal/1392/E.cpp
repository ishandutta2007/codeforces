#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n, q; 
ll a[30][30];
ll getsum(int x, int y){ 
	ll sum = 0;
	rep(i, 1, x) sum += a[i][1];
	rep(j, 2, y - 1) sum += a[x][j];
	rep(j, y - 1, n) sum += a[x + 1][j];
	rep(i, x + 2, n) sum += a[i][n];
	return sum;
}
ll getsum2(int x, int y){
	ll sum = 0;
	rep(i, 1, x) sum += a[i][1];
	rep(j, 2, y) sum += a[x][j];
	rep(i, x + 1, n) sum += a[i][y];
	rep(j, y + 1, n) sum += a[n][j];
	return sum;
}
bool vis[30][30];
ll dp[30][30];
ll DP(int r, int d){
	if (r == n - 1 && d == n - 1) return 1;
	if (vis[r][d]) return dp[r][d];
	vis[r][d] = 1;
	ll& ans = dp[r][d]; ans = 0;
	if (r < n - 1) ans += DP(r + 1, d);
	if (d < n - 1) ans += DP(r, d + 1);
	return ans;
}
char res[120];
void find_k(ll k, int r, int d){
	if (r == n - 1 && d == n - 1){
		assert(k == 1);
		return;
	}
	if (d < n - 1) {
		if (DP(r, d + 1) >= k) {res[r + d] = 'D'; find_k(k, r, d + 1); return;}
		else {res[r + d] = 'R'; find_k(k - DP(r, d + 1), r + 1, d); return;}
	}
	else {res[r + d] = 'R'; find_k(k, r + 1, d); return;}
}

int main(){
	cin >> n;
	per(i, n - 1, 1){
		rep(j, 2, n){
			//cout << i << ' ' << j << ' ' << getsum(i, j) << ' ' << getsum2(i, j) << ' ' << endl;
			a[i][j] = getsum(i, j) - getsum2(i, j) + 1;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) {
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	cin >> q;
	rep(i, 1, q){
		ll k;
		cin >> k;
		find_k(k + 1, 0, 0);
		int x = 1, y = 1;
		cout << x << ' ' << y << endl;
		srep(i, 0, 2 * n - 2){
			if (res[i] == 'D') x++;
			else y++;
			cout << x << ' ' << y << endl;
		}
	}
	return 0;
}