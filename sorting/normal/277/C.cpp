#include <bits/stdc++.h>

using namespace std;

map<int, vector<pair<int, int> > > row, col;
vector<int > groups_r, groups_c;

int main (){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;

	cin >> n >> m >> k;

	for(int i = 0; i < k; i++){
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		if(x1 > x2){
			swap(x1, x2);
		}
		if(y1 > y2){
			swap(y1, y2);
		}

		if(x1 == x2){
			row[x1].push_back({y1 , y2});
		}else{
			col[y1].push_back({x1, x2});
		}
	}

	for(auto t: row){
		auto v = t.second;

		sort(v.begin(), v.end());

		int mx;

		for(int i = 0; i < v.size(); i++){
			if(i == 0){
				groups_r.push_back(m - (v[i].second - v[i].first) );
				mx = v[i].second;
			}else{
				if(v[i].second > mx){
					groups_r.back() -= v[i].second - max(mx, v[i].first);
					mx = v[i].second;
				}
			}
		}
	}

	for(auto t: col){
		auto v = t.second;

		sort(v.begin(), v.end());

		int mx;

		for(int i = 0; i < v.size(); i++){
			if(i == 0){
				groups_c.push_back(n - (v[i].second - v[i].first) );
				mx = v[i].second;
			}else{
				if(v[i].second > mx){
					groups_c.back() -= v[i].second - max(mx, v[i].first);
					mx = v[i].second;
				}
			}
		}
	}

	int xor_value = 0;

	for(auto x: groups_c){
		xor_value ^= x;
		//cout << x << " c\n";
	}
	for(auto x: groups_r){
		xor_value ^= x;
		//cout << x << "r\n";
	}

	if( (n - 1 - groups_r.size()) & 1){
		xor_value ^= m;
	}
	if( (m - 1 - groups_c.size()) & 1){
		xor_value ^= n;
	}

	if(xor_value){
		cout << "FIRST\n";

		if((m ^ xor_value) < m){
			if(groups_r.size() != n-1){
				int pr = 1;

				for(auto group: row){
					//cout << group.first << " group.first\n";

					if(group.first != pr){
						break;
					}

					pr++;
				}

				//cout << "t\n";

				cout << pr << " 0 " << pr << " " << m - (m ^ xor_value) << "\n";

				return 0;
			}
		}

		if((n ^ xor_value) < n){
			if(groups_c.size() != m-1){
				int pr = 1;

				for(auto group: col){
					//cout << group.first << " group.first\n";

					if(group.first != pr){
						break;
					}
					pr++;
				}

				cout << "0 " << pr << " " << n - (n ^ xor_value) << " " << pr << "\n";

				return 0;
			}
		}
		int i = 0;

		for(auto it = row.begin(); it != row.end(); it++, i++){
			int x = groups_r[i];

			if((x ^ xor_value) < x){
				vector<pair<int, int> > v = it->second;

				sort(v.begin(), v.end());

				int target = x - (x ^ xor_value);
				int cnt = 0, mx = 0;

				//cout << target << "\n";

				for(pair<int, int> p: v){
					if(p.second > mx){
						if(p.first > mx){
							cnt += p.first - mx;
						}

						if(cnt >= target){
							cout << it->first << " " << 0 << " " << it->first << " " << p.first - (cnt - target) << "\n";

							return 0;
						}

						mx = max(mx, p.second);
					}
				}

				cnt += m - mx;

				if(cnt >= target){
					cout << it->first << " " << 0 << " " << it->first << " " << m - (cnt - target) << "\n";

					return 0;
				}
			}
		}

		i = 0;

		for(auto it = col.begin(); it != col.end(); it++, i++){
			int x = groups_c[i];

			if((x ^ xor_value) < x){
				vector<pair<int, int> > v = it->second;

				sort(v.begin(), v.end());

				int target = x - (x ^ xor_value);
				int cnt = 0, mx = 0;

				for(pair<int, int> p: v){
					if(p.second > mx){
						if(p.first > mx){
							cnt += p.first - mx;
						}

						if(cnt >= target){
							cout << 0 << " " << it->first << " " <<  p.first - (cnt - target) << " " << it->first << "\n";

							return 0;
						}

						mx = max(mx, p.second);
					}
				}

				cnt += n - mx;

				if(cnt >= target){
					cout << 0 << " " << it->first << " " <<  n - (cnt - target) << " " << it->first << "\n";

					return 0;
				}
			}
		}

	}else{
		cout << "SECOND\n";

		return 0;
	}

	return 0;
}