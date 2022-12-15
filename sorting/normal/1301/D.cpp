#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int total = 2 * ((n - 1) * m + (m - 1) * n);
	if(k > total){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";

	vector<pair<int, string> > steps;
	for(int i = 0; i < m - 1; ++i){
		if(n != 1){
			steps.push_back({n - 1, "DRL"});
			steps.push_back({n - 1, "U"});
		}
		steps.push_back({1, "R"});
	}
	if(n != 1){
		steps.push_back({n - 1, "D"});
		steps.push_back({n - 1, "U"});
	}
	if(m != 1)
		steps.push_back({m - 1, "L"});

	//for(auto x: steps)
	//	cout << x.first << " " << x.second << endl;

	vector<pair<int, string> > real_steps;
	for(int i = 0; i < steps.size(); ++i){
		if(steps[i].first * steps[i].second.size() > k){
			if(k >= steps[i].second.size())
				real_steps.push_back({k / steps[i].second.size(), steps[i].second});
			k %= steps[i].second.size();
			int idx = 0;
			for(int j = 0; j < k; ++j){
				string str = "";
				str += steps[i].second[idx++];
				real_steps.push_back({1, str});
			}
			break;
		}
		else{
			real_steps.push_back(steps[i]);
			k -= steps[i].first * steps[i].second.size();
		}
	}

	cout << real_steps.size() << "\n";
	for(auto st: real_steps)
		cout << st.first << " " << st.second << "\n";

	return 0;
}