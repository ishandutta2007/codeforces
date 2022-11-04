#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

typedef pair<pii, int> pi3;
vector<pi3> L, R;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n; scanf("%d", &n);
	for(int i=1, a, b; i<=n; i++) {
		scanf("%d %d", &a, &b);
		if(a>b) L.pb(pi3(pii(a, b), i));
		else R.pb(pi3(pii(a, b), i));
	}
	if(L.size()>R.size()) {
		sort(L.begin(), L.end(), [](pi3 a, pi3 b) {
			return a.x.x<b.x.x;
		});
		printf("%d\n", L.size());
		for(pi3 p: L) printf("%d ", p.y);
	}
	else {
		sort(R.begin(), R.end(), [](pi3 a, pi3 b) {
			return a.x.x>b.x.x;
		});
		printf("%d\n", R.size());
		for(pi3 p: R) printf("%d ", p.y);
	}
}