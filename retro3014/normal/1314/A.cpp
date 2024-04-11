#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll MOD = 1000000007;
const ll INFLL = 1e18;
const int INF = 1e9;
const int MAX_N = 200000;

int N;
ll arr[MAX_N+1], t[MAX_N+1];

deque<pll> dq;

ll ans=0;
priority_queue<ll> pq;

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		scanf("%lld", &arr[i]);
	}
	for(int i=1; i<=N; i++){
		scanf("%lld", &t[i]);
		dq.pb({arr[i], t[i]});
	}
	sort(dq.begin(), dq.end());
	pq.push(dq.front().second);
	ll now = dq.front().first;
	ll sum = dq.front().second;
	int idx = 0;
	while(idx<dq.size()){
		if(pq.empty()){
			idx++;
			now = dq[idx].first;
			pq.push(dq[idx].second);
			sum+=dq[idx].second;
		}
		while(idx<dq.size()-1 && dq[idx+1].first==now){
			idx++;
			pq.push(dq[idx].second);
			sum+=dq[idx].second;
		}
		sum-=pq.top();
		pq.pop();
		ans+=sum;
		now++;
	}
	printf("%lld", ans);
	return 0;
}