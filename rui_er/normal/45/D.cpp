// Problem: CF45D Event Dates
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF45D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
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
const int N = 105, K = 1e7+5;

int n, ans[N], vis[K];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Segment {
	int l, r, id;
	friend bool operator < (const Segment& a, const Segment& b) {
		if(a.r != b.r) return a.r < b.r;
		return a.l < b.l;
	}
}seg[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d%d", &seg[i].l, &seg[i].r);
		seg[i].id = i;
	}
	sort(seg+1, seg+1+n);
	rep(i, 1, n) {
		rep(j, seg[i].l, seg[i].r) {
			if(!vis[j]) {
				ans[seg[i].id] = j;
				vis[j] = 1;
				break;
			}
		}
	}
	rep(i, 1, n) printf("%d%c", ans[i], " \n"[i==n]);
	return 0;
}