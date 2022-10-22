#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l), i##end = (r);i <= i##end;++i)
using std::cin;
using std::cout;

typedef unsigned long long u64;
typedef double db;
typedef long long ll;
typedef unsigned u32;

const int N = 100100;
int n, m, k;
int a[N], can[N], cnt[N];
std::vector<int> to[N];

using pr = std::pair<db, int>;
std::priority_queue<pr, std::vector<pr>, std::greater<pr>> pq;

int st[N],tot,best;
int main() {
	std::ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 1, k) {
		int x; cin >> x;
		can[x] = 1;
	}
	rep(i, 1, m) {
		int a, b; cin >> a >> b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	rep(i, 1, n) {
		if(!can[i]) {
			for(int x : to[i]) cnt[i] += !can[x];
			pq.emplace((db)cnt[i]/to[i].size(),i);
		}
	}
	best = 1;
	db res = -1;
	for(;pq.size();){
		if(tot+k!=n&&pq.top().first>res) res=pq.top().first,best=tot;
		pr x=pq.top();pq.pop();
		if(can[x.second])continue;
		can[x.second]=1, st[++tot]=x.second;
		for(int x : to[x.second]) if(!can[x]) --cnt[x], pq.emplace((db)cnt[x]/to[x].size(),x);
	}
	cout<<n-k-best<<'\n';
	rep(i,best+1,tot)cout<<st[i]<<' ';
}