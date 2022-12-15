#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 2e5 + 7;
const long long inf = 1e15;

vector<long long> v[MAXN];
pair<long long, long long> a[MAXN];
priority_queue<long long, vector<long long>, greater<long long> > pq;

void solve(){
	long long n;

	cin >> n;

	while(!pq.empty()){
		pq.pop();
	}

	for(long long i = 0; i < n; ++i){
		v[i].clear();
	}

	for(long long i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;
		v[a[i].first].push_back(a[i].second);
	}
	//sort(a, a + n);

	long long cnt = n, ret = 0;
	for(int i = n - 1; i >= 0; --i){
		cnt -= (int)v[i].size();
		for(long long x: v[i]){
			pq.push(x);
		}
		if(cnt < i){
			while(cnt < i){
				long long x = pq.top();
				pq.pop();

				ret += x;
				++cnt;
			}
		}
	}

	cout << ret << "\n";
	return;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long t;

	cin >> t;

	while(t--){
		solve();
	}
	return 0;
}