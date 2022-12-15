#include <bits/stdc++.h>

using namespace std;

struct Point{
	int x, y;

	Point(){}
};

const int MAXN = 1e3 + 7;
const int inf = 1e6 + 8;

void output(const vector<int> &ans){
	cout << (int)ans.size() << "\n";
	for(int idx: ans)
		cout << idx << " ";
	cout << "\n";
}

Point p[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> p[i].x >> p[i].y;

	while(true){
		int cnt[2][2] = {{0, 0}, {0, 0}};

		for(int i = 0; i < n; ++i){
			int rem1 = (p[i].x + inf) & 1;
			int rem2 = (p[i].y + inf) & 1;

			++cnt[rem1][rem2];
		}

		bool ok = true;
		for(int rem1 = 0; rem1 < 2 && ok; ++rem1){
			for(int rem2 = 0; rem2 < 2 && ok; ++rem2){
				if(cnt[rem1][rem2] == n){
					for(int i = 0; i < n; ++i){
						p[i].x = (p[i].x + (p[i].x & 1)) / 2;
						p[i].y = (p[i].y + (p[i].y & 1)) / 2;
					}
					ok = false;
					break;
				}
			}
		}

		if(!ok)
			continue;

		if((cnt[0][0] || cnt[1][1]) && (cnt[0][1] || cnt[1][0])){
			vector<int> ans;
			for(int i = 0; i < n; ++i){
				if((p[i].x + p[i].y) & 1)
					ans.push_back(i + 1);
			}

			output(ans);
			break;
		}

		vector<int> ans;
		for(int i = 0; i < n; ++i){
			if(p[i].x & 1){
				ans.push_back(i + 1);
			}
		}

		output(ans);
		break;
	}

	return 0;
}