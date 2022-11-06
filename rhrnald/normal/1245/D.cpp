#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int N = 1000001;
int n,m;

int x[N], y[N], c[N], k[N];

typedef pair<ll,pii> plp;
vector<plp> v;
int p[N];
bool on[N];
int h(int cur) {
	if(p[cur]==cur) return cur;
	p[cur]=h(p[cur]);
	return p[cur];
}

bool used[N];
vector<pii> L;

int main(void){
	scanf("%d", &n);
	for(int i=1; i<=n; i++) scanf("%d%d", x+i, y+i);
	for(int i=1; i<=n; i++) scanf("%d", c+i);
	for(int i=1; i<=n; i++) scanf("%d", k+i);
	for(int i=1; i<=n; i++) v.push_back({c[i], {i,i}});
	for(int i=1; i<n; i++)
		for(int j=i+1; j<=n; j++) {
			v.push_back({1ll*(k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j])), {i,j}});
		}

	sort(all(v));
	ll ans=0;
	int k=0;
	for(int i=1; i<=n; i++) p[i]=i;
	for(int i=0; i<sz(v); i++) {
		ll val=v[i].first;
		int a=v[i].second.first;
		int b=v[i].second.second;
		if(a==b) {
			if(on[h(a)]) continue;
			ans+=val;
			on[h(a)]=true;
			used[a]=true;
			k++;
			continue;
		}
		int aa=a, bb=b;
		a=h(a);
		b=h(b);
		if(a==b) continue;
		if(on[a] && on[b]) continue;
		ans+=val;
		p[a]=b;
		on[b]=on[a]||on[b];
		L.push_back({aa,bb});
	}
	printf("%lld\n", ans);
	printf("%d\n", k);
	for(int i=1; i<=n; i++) if(used[i]) printf("%d ", i); printf("\n");
	printf("%d\n", sz(L));
	for(pii e : L) printf("%d %d\n", e.first, e.second);
}