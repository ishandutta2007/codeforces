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
int n,m,q,x;
int cnt[N];
int cc[N];
ll sum[N];
ll Q[N];
ll lft[N];
int h[N];

vector<int> G[N];
vector<pii> v;

int T[N];
void add(int x) {
	while(x<=m) {
		T[x]++;
		x+=x&(-x);
	}
}
int sm(int loc) {
	int ret=0;
	while(loc) ret+=T[loc], loc-=loc&(-loc);
	return ret;
}
int find(int x) {
	int l=0, r=m;
	while(r-l>1) {
		int mid=(r+l)/2;
		if(sm(mid)>=x) r=mid;
		else l=mid;
	}
	return r;
}
int ans[N];
int main(void){
	scanf("%d%d%d", &n, &m, &q);
	for(int i=0; i<n; i++) {scanf("%d", &x); cnt[x]++;}
	for(int i=1; i<=m; i++) G[cnt[i]].push_back(i);
	for(int i=1; i<=m; i++) cc[cnt[i]]++;
	for(int i=1; i<=n; i++) cc[i]+=cc[i-1];
	for(int i=1; i<=n; i++) sum[i]=sum[i-1]+cc[i-1];


	for(int i=0;i<q;i++) {
		scanf("%lld", Q+i); Q[i]-=n;
		if(Q[i]>sum[n]) {
			ans[i]=(Q[i]-sum[n])%m;
			if(!ans[i]) ans[i]+=m;
			continue;
		}
		h[i]=lower_bound(sum, sum+n+1, Q[i])-sum-1;
		lft[i]=Q[i]-sum[h[i]];
		v.push_back({h[i], i});
	}

	sort(all(v));
	int cur=0;
	for(int i=0; i<sz(v); i++) {
		if(v[i].first>=n) break;
		while(cur<=v[i].first) {
			for(int e : G[cur]) add(e);
			cur++;
		}
		int idx=v[i].second;
		ans[idx]=find(lft[idx]);
	}
	for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}