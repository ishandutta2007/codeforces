#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;

int n;
array<int, 4> sides[MAXN];

bool is_ok(){
	multiset<int> lims[2];
	vector<array<int, 3> > events;
	for(int i = 0; i < n; ++i){
		events.push_back({sides[i][0], 0, i});
		events.push_back({sides[i][1], 1, i});
		//events.push_back({sides[i][2], 2, i});
		//events.push_back({sides[i][3], 3, i});
	}

	sort(events.begin(), events.end());

	for(array<int, 3> event: events){
		if(event[1] == 0){
			if(!lims[0].empty() && !lims[1].empty()){
				if(sides[event[2]][3] < *lims[0].rbegin() || sides[event[2]][2] > *lims[1].begin())
					return false;
			}

			lims[0].insert(sides[event[2]][2]);
			lims[1].insert(sides[event[2]][3]);
			continue;
		}
		if(event[1] == 1){
			lims[0].erase( lims[0].find(sides[event[2]][2]) );
			lims[1].erase( lims[1].find(sides[event[2]][3]) );
			continue;
		}
	}

	return true;
}

void solve(){
	if(!is_ok()){
		cout << "NO\n";
		return;
	}

	for(int i = 0; i < n; ++i){
		swap(sides[i][0], sides[i][2]);
		swap(sides[i][1], sides[i][3]);
	}

	if(!is_ok()){
		cout << "NO\n";
		return;
	}

	cout << "YES\n";
}

void read(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 4; ++j)
			cin >> sides[i][j];
	}
}

int main(){
	read();
	solve();
}