#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
vector<pair<int,int>> have;
long long earn[maxn], res[maxn];
int main() {
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		int val; scanf("%d",&val);
		have.push_back({val, i});
	}
	for(int i=1;i<=m;i++) {
		int val, x; scanf("%d%d",&val,&x);
		have.push_back({val, -i});
		earn[i] = x;
	}
	sort(have.begin(),have.end());
	long long now = 0;
	for(auto t : have) {
		if(t.second < 0) now += earn[-t.second];
		else res[t.second] = now;
	}
	for(int i=1;i<=n;i++) printf("%lld ",res[i]);
}