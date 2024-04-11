// Problem: D. Permutation Restoration
// Contest: Codeforces - Educational Codeforces Round 131 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1701/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 5e5+5;

int T, n, a[N], b[N];
set<int> st;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Segment {
	int L, R, id;
}s[N];

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d", &n);
		rep(i, 1, n) {
			scanf("%d", &b[i]);
			if(b[i]) {
				s[i].L = i / (b[i] + 1) + 1;
				s[i].R = i / b[i];
			}
			else {
				s[i].L = i + 1;
				s[i].R = n;
			}
			s[i].id = i;
		}
		sort(s+1, s+1+n, [](const Segment& a, const Segment& b) {
			if(a.R != b.R) return a.R < b.R;
			if(a.L != b.L) return a.L < b.L;
			return a.id < b.id;
		});
		st.clear();
		rep(i, 1, n) st.insert(i);
		rep(i, 1, n) {
			auto it = st.lower_bound(s[i].L);
			a[s[i].id] = *it;
			st.erase(it);
		}
		rep(i, 1, n) printf("%d%c", a[i], " \n"[i==n]);
	}
	return 0;
}