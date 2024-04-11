#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
array<int, 2> p[MAXN];
unordered_set<int> has[MAXN];
set<int> row[MAXN];

bool check(array<int, 3> arr){
	return has[arr[0]].count(arr[1]) && has[arr[0]].count(arr[1] + arr[2]) && has[arr[0] + arr[2]].count(arr[1]) && has[arr[0] + arr[2]].count(arr[1] + arr[2]);
}

vector<array<int, 3> > cand;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> p[i][0] >> p[i][1];
		has[ p[i][0] ].insert(p[i][1]);
		row[ p[i][0] ].insert(p[i][1]);
		//col[ p[i][1] ].insert(p[i][0]);
	}

	int sq_n = sqrt(n);
	for(int i = 0; i < MAXN; ++i){
		if(row[i].size()  < sq_n){
			for(int it1: row[i]){
				for(int it2: row[i]){
					if(it1 >= it2){
						continue;
					}
					int side = it2 - it1;
					cand.push_back({i, it1, side});
				}
			}
		}
		else{
			for(int j = 0; j < n; ++j){
				if(p[j][0] <= i){
					continue;
				} 

				int side = p[j][0] - i;

				cand.push_back({i, p[j][1], side});
			}
		}
	}
	int ans = 0;
	for(auto c: cand){
		ans += check(c);
	}

	cout << ans << "\n";

	return 0;
}