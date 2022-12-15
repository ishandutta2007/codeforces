#include <bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5 + 7;
pair<int, int> points[kMaxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> points[i].first >> points[i].second;

	if(n & 1){
		cout << "No\n";
		return 0;
	}

	for(int i = 0; i < n / 2; ++i){
		pair<int, int> next_point = points[(i + n / 2 + 1) % n];
		if(points[i + n / 2].first - next_point.first != points[i + 1].first - points[i].first){
			cout << "No\n";
			return 0;
		}
		if(points[i + n / 2].second - next_point.second != points[i + 1].second - points[i].second){
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
	return 0;
}