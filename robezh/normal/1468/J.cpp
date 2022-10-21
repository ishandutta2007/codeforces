#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e16;
const int maxn = 2e5 + 5;

int n,m,k;
vector<pair<int,pair<int,int>>> way;
int head[maxn];

int findhead(int x) {
	if(head[x] == x) return x;
	return head[x] = findhead(head[x]);
}

void solve(int tnum) {
	scanf("%d%d%d",&n,&m,&k);
	long long best = inf;
	way.clear();
	for(int i=1;i<=m;i++) {
		int u,v,val; scanf("%d%d%d",&u,&v,&val);
		way.push_back({val, {u,v}});
		best = min(best, (long long)abs(val - k));
	}
	sort(way.begin(),way.end());
	int cnt = 0;
	long long ans = 0;
	for(int i=1;i<=n;i++) head[i] = i;
	for(auto e : way) {
		int u = e.second.first, v = e.second.second, val = e.first;
		if(val > k) {
			if(findhead(u) != findhead(v)) {
				head[findhead(u)] = findhead(v);
				ans += val - k;
			}
		}
		else {
			if(findhead(u) != findhead(v)) {
				head[findhead(u)] = findhead(v);
				cnt++;
			}
			if(cnt == n-1) {
				printf("%lld\n",best);
				return ;
			}
		}
	}
	printf("%lld\n",ans);
}

int main() {
	int tnum; scanf("%d",&tnum);
	for(int i=1;i<=tnum;i++) solve(i);
}