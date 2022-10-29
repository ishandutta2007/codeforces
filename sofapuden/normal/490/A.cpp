#include <bits/stdc++.h>
#define all(x) (x).begin, (x).end
#define rall(x) (x).rbegin, (x). rend

using namespace std;
typedef long long ll;
typedef vector<int> vi;

void solve(){
	int n; cin >> n;
	vector<vi> best(3);
	for(int i = 1, tmp; i <= n; ++i){
		cin >> tmp;
		tmp--;
		best[tmp].push_back(i);
	}
	cout << min(best[0].size(),min(best[1].size(),best[2].size())) << "\n";
	for(int i = 0; i < min(best[0].size(),min(best[1].size(),best[2].size())); ++i){
		cout << best[0][i] << " " << best[1][i] << " " << best[2][i] << "\n";
	}
		
	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	solve();
}