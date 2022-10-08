#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin>>n>>m;
	vector<ii> points;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			points.push_back({i+1, j+1});
		}
	}
	int frontIndex=0; int endIndex=points.size()-1;
	bool front=true;
	while (frontIndex<=endIndex) {
		if (front) {
			cout<<points[frontIndex].first<<" "<<points[frontIndex].second<<'\n';
			frontIndex++;
		}
		else {
			cout<<points[endIndex].first<<" "<<points[endIndex].second<<'\n';
			endIndex--;
		}
		front^=1;
	}
	
	return 0;
}