#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

set <int> q;

pair <int, int> query() {
	cout << "? ";
	for (int x : q) {
		cout << x + 1 << " ";
	}
	cout << endl;
	int a, b;
	cin >> a >> b;
	return {a, b};
}

int main(){
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > arr;
	for (int i = 0; i < k; i++) {
		q.insert(i);
	}
	vector <bool> ban(n, false);
	for (int i = k - 1; i < n; i++) {
		auto p = query();
		ban[p.first - 1] = true;
		arr.push_back({p.second, p.first - 1});
		q.erase(p.first - 1);
		q.insert(i + 1); 
	}
	q.erase(n);
	sort(arr.begin(), arr.end());
	int a = arr[0].second, b = arr[1].second;
	q.insert(a), q.insert(b);
	vector <bool> less(n, false);
	int less_cnt = 0;
	for (int i = 0; i < n; i++) {
		if (ban[i]) continue;
		q.erase(i);
		auto p = query();
		if (p.first - 1 == b) {
			less_cnt++;
		}
		q.insert(i);
	}
	cout << "! " << less_cnt + 1 << endl;
}