// Problem: D. Sofa Thief
// Contest: Codeforces - Training Round #1 (1400-1700-1900-2000-2100-2200, 120min)
// URL: https://codeforces.com/group/iw2l909Oqc/contest/396416/problem/D
// Memory Limit: 256 MB
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
const int N = 1e5+5;

#define y1 y114514
int d, n, m, x1[N], y1[N], x2[N], y2[N], sl[N], sr[N], st[N], sb[N], cntl, cntr, cntt, cntb;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &d, &n, &m);
	rep(i, 1, d) {
		scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
		if(x1[i] > x2[i]) swap(x1[i], x2[i]);
		if(y1[i] > y2[i]) swap(y1[i], y2[i]);
		++sl[x1[i]]; ++sr[x2[i]];
		++st[y1[i]]; ++sb[y2[i]];
	}
	scanf("%d%d%d%d", &cntl, &cntr, &cntt, &cntb);
	rep(i, 1, n) sl[i] += sl[i-1];
	per(i, n, 1) sr[i] += sr[i+1];
	rep(i, 1, m) st[i] += st[i-1];
	per(i, m, 1) sb[i] += sb[i+1];
	rep(i, 1, d) {
		int nowl = sl[x2[i]-1] - (x1[i] == x2[i] - 1);
		int nowr = sr[x1[i]+1] - (x1[i] == x2[i] - 1);
		int nowt = st[y2[i]-1] - (y1[i] == y2[i] - 1);
		int nowb = sb[y1[i]+1] - (y1[i] == y2[i] - 1);
		if(nowl == cntl && nowr == cntr && nowt == cntt && nowb == cntb) return printf("%d\n", i)&0;
	}
	puts("-1");
	return 0;
}