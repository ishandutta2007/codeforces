#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i].first;
	for(int i = 0; i < n; ++i)
		cin >> v[i].second;

	sort(v.begin(), v.end());

	multiset<int> ms;
	long long ans = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		ms.insert(v[i].second);
		sum += v[i].second;
		if(i + 1 == n || v[i + 1].first != v[i].first){
			int cnt = v[i + 1].first - v[i].first;
			while(!ms.empty() && cnt--){
				long long x = *ms.rbegin();
				ms.erase(ms.find(x));
				sum -= x;
				ans += sum;
			}
		}
	}

	cout << ans << "\n";
}