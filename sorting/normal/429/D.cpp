#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 7;
const long long inf = 1e18;

pair<long long, long long> p[maxn];

long long solve(int l, int r){
	if(l == r){
		return inf;
	}

	int mid = (l + r) / 2;
	long long res = min(solve(l, mid), solve(mid + 1, r));

	vector<pair<long long, long long> > v;

	for(int i = mid; i >= l; i--){
		if((p[i].second - p[mid + 1].second) * (p[i].second - p[mid + 1].second) >= res){
			break;
		}
		v.push_back(p[i]);
	}
	for(int i = mid + 1; i <= r; i++){
		if((p[i].second - p[mid].second) * (p[i].second - p[mid].second) >= res){
			break;
		}
		v.push_back(p[i]);
	}

	sort(v.begin(), v.end());

	for(int i = 0; i < (int)v.size(); i++){
		for(int j = i + 1; j < min((int)v.size(), i + 8); j++){
			res = min(res, (v[i].first - v[j].first) * (v[i].first - v[j].first) + (v[i].second - v[j].second) * (v[i].second - v[j].second));
		}
	}

	return res;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;

	cin >> n;

	for(long long i = 1; i <= n; i++){
		cin >> p[i].first;
		p[i].first += p[i-1].first;
		p[i].second = i;
	}

	cout << solve(1, n) << "\n";

	return 0;
}