//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
 
int w, h, n;
set<int> cutX, cutY;
multiset<int> disX, disY;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%d%d%d", &w, &h, &n);
	cutX.insert(0);
	cutX.insert(h);
	disX.insert(h);
	cutY.insert(0);
	cutY.insert(w);
	disY.insert(w);
	while(n --> 0) {
		char op[2];
		int k;
		scanf("%s%d", op, &k);
		auto& s = (op[0] == 'H') ? cutX : cutY;
		auto& d = (op[0] == 'H') ? disX : disY;
		auto itL = s.lower_bound(k);
		auto itR = itL;
		if(itL != s.begin()) --itL;
		s.insert(k);
		d.erase(d.lower_bound(*itR-*itL));
		d.insert(*itR-k);
		d.insert(k-*itL);
		printf("%lld\n", 1LL*(*--disX.end())*(*--disY.end()));
	}
    return 0;
}