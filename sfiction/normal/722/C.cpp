#include <cstdio>
#include <map>

using namespace std;

typedef long long ll;

const int MAXN = 1E5 + 10;

int n;
int a[MAXN], b[MAXN];
ll ans[MAXN];

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	map<int, pair<int, ll> > lst;
	for (int i = n; i >= 1; --i){
		int u = b[i];
		lst[b[i]] = make_pair(b[i], a[b[i]]);

		auto p = lst.find(u);
		ll sum = a[u];
		int l = u, r = u;
		if (p != lst.begin()){
			--p;
			if (p->second.first == u - 1){
				sum += p->second.second;
				l = p->first;
				lst.erase(p);
			}
		}
		p = ++lst.find(u);
		if (p != lst.end()){
			if (p->first == u + 1){
				sum += p->second.second;
				r = p->second.first;
				lst.erase(p);
			}
		}
		lst.erase(lst.find(u));
		lst[l] = make_pair(r, sum);
		ans[i] = max(ans[i + 1], sum);
	}
	for (int i = 2; i <= n + 1; ++i)
		printf("%I64d\n", ans[i]);
	return 0;
}