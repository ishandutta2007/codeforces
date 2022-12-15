#include <bits/stdc++.h>

using namespace std;

const long long N = 2e5 + 7;

long long a[N], b[N];
vector<pair<long long, bool>> v;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long n, m, ta, tb, k;

	cin >> n >> m >> ta >> tb >> k;

	for(long long i = 0; i < n; i++){
		cin >> a[i];
		v.push_back({a[i] + ta, 0});
	}
	for(long long i = 0; i < m; i++){
		cin >> b[i];
		v.push_back({b[i], 1});
	}

	sort(v.begin(), v.end());

	if(k >= n || k >= m){
		cout << "-1\n";
		return 0;
	}

	long long a_cnt = 0, b_cnt = 0, pr = 0;
	long long res = -1;


	for(int i = 0; i < (int)v.size(); i++){
		if(!v[i].second){
			a_cnt++;
		}
		else{
			b_cnt++;
			//cout << a_cnt << " " << b_cnt << endl;
			pr = min(pr + 1, min(a_cnt, b_cnt));
			if(pr > k){
				res = v[i].first + tb;
				break;
			}
		}
	}

	cout << res << "\n";

	return 0;
}