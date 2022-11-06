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
ll x[N];
int y[N];

typedef pair<ll,int> pli;
vector<pli> v;
vector<ll> idx;
int main(void){
	scanf("%d", &n);
	for(int i=0; i<n; i++) scanf("%lld", x+i);
	for(int i=0; i<n; i++) scanf("%d", y+i);
	for(int i=0; i<n; i++) v.push_back({x[i], y[i]});

	sort(all(v));

	for(int i=1; i<n; i++) {
		if(v[i].first==v[i-1].first) {
			idx.push_back(v[i].first);
		}
	}
	idx.erase(unique(all(idx)), idx.end());
	ll ans=0;
	for(int i=0; i<n; i++) {
		for(ll ix : idx) {
			if(!(v[i].first&(~ix))) {
				ans+=v[i].second;
				break;
			}
		}
	}
	printf("%lld", ans);
}