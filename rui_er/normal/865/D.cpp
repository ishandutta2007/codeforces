//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(ll (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(ll (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 3e5+5;

ll n, a[N], ans;
priority_queue<ll, vector<ll>, greater<ll> > q;

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		q.push(a[i]);
		ll tp = q.top();
		if(tp < a[i]) {
			ans += a[i] - tp;
			q.pop();
			q.push(a[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}