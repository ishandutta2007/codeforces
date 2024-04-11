#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	string S, T;
	cin >> S >> T;
	vector<vector<int> > gs(27), gt(27);
	for (int i = 0; i < N; ++i) {
		gs[S[i] == '?' ? 26 : S[i] - 'a'].push_back(i);
		gt[T[i] == '?' ? 26 : T[i] - 'a'].push_back(i);
	}
	vector<pair<int, int> > ans;
	for (int i = 0; i <= 26; ++i) {
		while (!gs[i].empty() && !gt[i].empty()) {
			ans.push_back(make_pair(gs[i].back(), gt[i].back()));
			gs[i].pop_back();
			gt[i].pop_back();
		}
		while (!gs[i].empty() && !gt[26].empty()) {
			ans.push_back(make_pair(gs[i].back(), gt[26].back()));
			gs[i].pop_back();
			gt[26].pop_back();
		}
		while (!gt[i].empty() && !gs[26].empty()) {
			ans.push_back(make_pair(gs[26].back(), gt[i].back()));
			gs[26].pop_back();
			gt[i].pop_back();
		}
	}
	cout << ans.size() << '\n';
	for (pair<int, int> i : ans) {
		cout << i.first + 1 << ' ' << i.second + 1 << '\n';
	}
	return 0;
}