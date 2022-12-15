#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	int n = s.size();
	vector<vector<int>> v;
	vector<int> open(n), close(n);
	vector<bool> used(n, false);
	while(true){
		open[0] = s[0] == '(';
		if(used[0])
			open[0] = 0;
		for(int i = 1; i < n; ++i){
			if(used[i]){
				open[i] = open[i - 1];
				continue;
			}
			open[i] = open[i - 1] + (s[i] == '(');
		}

		close[n - 1] = s[n - 1] == ')';
		if(used[n - 1])
			close[n - 1] = 0;
		for(int i = n - 2; i >= 0; --i){
			if(used[i]){
				close[i] = close[i + 1];
				continue;
			}
			close[i] = close[i + 1] + (s[i] == ')');
		}

		int last_possible = -1;
		for(int i = 0; i < n - 1; ++i){
			if(open[i] <= close[i + 1])
				last_possible = i;
		}

		if(last_possible == -1 || !open[last_possible])
			break;

		v.push_back({});
		for(int i = 0; i <= last_possible; ++i){
			if(!used[i] && s[i] == '('){
				v.back().push_back(i + 1);
				used[i] = true;
			}
		}

		int left_close = open[last_possible];
		for(int i = n - 1; i >= 0 && left_close; --i){
			if(!used[i] && s[i] == ')'){
				v.back().push_back(i + 1);
				used[i] = true;
				--left_close;
			}
		}

		sort(v.back().begin(), v.back().end());
	}

	cout << v.size() << "\n";
	for(vector<int> vv: v){
		cout << vv.size() << "\n";
		for(int x: vv)
			cout << x << " ";
		cout << "\n";
	}
}