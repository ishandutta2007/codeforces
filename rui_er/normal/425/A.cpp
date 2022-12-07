// LUOGU_RID: 96167328
// Problem: CF425A Sereja and Swaps
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF425A
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 205;

int n, k, a[N], ans = -0x3f3f3f3f;
priority_queue<int> O;
priority_queue<int, vector<int>, greater<int> > I;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(L, 1, n) {
		rep(R, L, n) {
			O.push(-0x3f3f3f3f);
			rep(i, 1, n) {
				if(L <= i && i <= R) I.push(a[i]);
				else O.push(a[i]);
			}
			rep(_, 1, k) {
				int x = I.top(), y = O.top();
				if(x >= y) break;
				I.pop(); O.pop();
				I.push(y); O.push(x);
			}
			int now = 0;
			for(; !I.empty(); I.pop()) now += I.top();
			chkmax(ans, now);
			for(; !O.empty(); O.pop());
		}
	}
	printf("%d\n", ans);
	return 0;
}