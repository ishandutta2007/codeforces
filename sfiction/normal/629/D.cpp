#include <cmath>
#include <cstdio>
#include <map>
#include <utility>

#define st first
#define nd second

using namespace std;

typedef long long ll;

int main(){
	int n;
	scanf("%d", &n);
	map<ll, ll> lst;
	lst[0] = 0;
	for (int R, H, i = 0; i < n; ++i){
		scanf("%d%d", &R, &H);
		ll S = R * (ll)R * H;
		auto l = lst.lower_bound(S), r = l;
		ll T = (--r)->nd + S;
		r = l;
		for (; r != lst.end() && r->nd <= T; ++r);
		lst.erase(l, r);
		lst[S] = T;
	}
	printf("%.12f\n", (--lst.end())->nd * 3.1415926535898);
	return 0;
}