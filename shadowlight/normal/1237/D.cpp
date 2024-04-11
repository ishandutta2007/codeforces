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
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> a(2 * n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	n += n;
	int j = 0;
	multiset <int> q;
	for (int i = 0; i < n / 2; i++) {
		if (j == i) {
			j = (j + 1) % n;
			q.insert(a[i]);
		}
		while (j != i && *q.rbegin() <= 2 * a[j]) {
			q.insert(a[j]);
			j = (j + 1) % n;
		}
		if (i == j) {
			cout << "-1 ";
		} else {
			cout << (j - i + n) % n << " ";
		}
		q.erase(q.find(a[i]));
	}

}