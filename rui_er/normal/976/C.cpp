//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 1e6+5;

int n;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Segment {
	int L, R, id;
	Segment(int a=0, int b=0, int c=0) : L(a), R(b), id(c) {}
	friend bool operator < (const Segment& a, const Segment& b) {
		if(a.L != b.L) return a.L < b.L;
		return a.R > b.R;
	}
}seg[N];

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d%d", &seg[i].L, &seg[i].R), seg[i].id = i;
	sort(seg+1, seg+1+n);
	int id = 1;
	rep(i, 2, n) {
		if(seg[i].R > seg[id].R) id = i;
		else return printf("%d %d\n", seg[i].id, seg[id].id)&0;
	}
	puts("-1 -1");
	return 0;
}