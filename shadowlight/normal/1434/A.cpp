#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Data {
	int val;
	int i, j;
};

bool operator<(Data a, Data b) {
	return a.val < b.val;
}

const int INF = 1e9 + 7;

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector <int> a(6);
	for (int i = 0; i < 6; ++i) {
		cin >> a[i];
	}
	int n;
	cin >> n;
	sort(all(a));
	reverse(all(a));
	vector <vector <int>> b(n, vector <int> (6, 0));
	vector <Data> data;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		for (int j = 0; j < 6; ++j) {
			b[i][j] = x - a[j];
			data.pb({b[i][j], i, j});
		}
	}
	sort(all(data));

	vector <int> its(n, 0);

	multiset<int> q;
	for (int i = 0; i < n; ++i) {
		q.insert(b[i][0]);
	} 

	int res = INF;

	for (auto x : data) {
		int y = *q.rbegin() - x.val;
		res = min(res, y);
		int i = x.i;
		q.erase(q.find(b[i][its[i]]));
		++its[i];
		if (its[i] == 6) break;
		q.insert(b[i][its[i]]);
	}
	cout << res << "\n";

}