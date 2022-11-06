#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], dis[N];
ll res1[N], tot1, res2[N], tot2;
ll indeg[N];
struct Edge {
	int v, nxt;
}e[N];
int ne, h[N];
void add(ll u, ll v) {
    e[++ne].v = v;
    e[ne].nxt = h[u];
    h[u] = ne;
}

void toposort() {
	queue<ll> q;
    for(int i=1;i<=n;i++) {
    	if(!indeg[i]) {
    		q.push(i);
		}
	}
    while(!q.empty()) {
        ll u = q.front();
		q.pop();
        for(int i=h[u];i;i=e[i].nxt) {
            ll v = e[i].v;
            if(dis[u] > 0) {
                dis[v] += dis[u];
                res1[++tot1] = u;
            } 
			else {
				res2[++tot2] = u;
			}
            if(--indeg[v] == 0) {
            	q.push(v);
			}
        }
    }
}

int main() {
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) {
    	scanf("%lld", &a[i]);
		dis[i] = a[i];
	} 
    for(int i=1;i<=n;i++) {
        ll x;
        scanf("%lld", &x);
        add(i, x);
        ++indeg[x];
    }
    toposort();
    ll ans = 0;
    for(int i=1;i<=n;i++) {
    	ans += dis[i];
	}
    printf("%lld\n", ans);
    for(int i=1;i<=tot1;i++) {
    	printf("%lld ", res1[i]);
	}
    for(int i=tot2;i>=1;i--) {
    	printf("%lld ", res2[i]);
	}
	puts("");
    return 0;
}