#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;

pair<int, int> d[MAXN];
vector<vector<int> > v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> d[i].first;
		d[i].second = i;
	}

	sort(d, d + n);
	reverse(d, d + n);

	for(int i = 0; i < n; ++i){
		v.push_back(vector<int>());
		v.back().push_back(2 * d[i].second + 1);
	}

	for(int i = 0; i < n; ++i){
		int x = i + d[i].first;

		if(x >= v.size()){
			v.push_back(vector<int>());
			v.back().push_back(2 * d[i].second + 2);
			continue;
		}

		v[x].push_back(2 * d[i].second + 2);
	}

	for(int i = 1; i < v.size(); ++i){
		for(int x: v[i]){
			cout << v[i - 1][0] << " " << x << "\n";
		}
	}

	return 0;
}