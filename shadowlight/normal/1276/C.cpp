#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <pair <int, int> > counts;
	map <int, int> cnt;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	for (auto t : cnt) {
		counts.push_back({t.second, t.first});
	}
	sort(counts.begin(), counts.end());
	int it = 0;
	int sum = 0;
	int max_sz = 0;
	int row = -1;
	for (int len = 1; len <= n; len++) {
		while (it < (int) counts.size() && counts[it].first < len) {
			sum += counts[it++].first;
		}
		int total = sum + len * (counts.size() - it);	
		int now_sz = (total / len) * len;
		if (now_sz < (ll) len * len) continue;
		if (now_sz > max_sz) {
			max_sz = now_sz;
			row = len;
		}
	}
	cout << max_sz << "\n";
	int col = max_sz / row;
	cout << row << " " << col << "\n";
	vector <pair <int, int> > lst;
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			lst.push_back({i, (i + j) % col});
		}
	}
	int now = 0;
	vector <vector <int> > matrix(row, vector <int> (col, 0));
	for (int i = counts.size() - 1; i >= 0; i--) {
		counts[i].first = min(counts[i].first, row);
		while (now < lst.size() && counts[i].first) {
			//cout << lst[now].first << " " << lst[now].second << " " << counts[i].second << endl;
			matrix[lst[now].first][lst[now].second] = counts[i].second;
			counts[i].first--;
			now++; 
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}