#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

int n, k;

queue <int> q;

int iter = 0;

bool query(int tp, int pos = -1) {
	iter++;
	if (!tp) {
		cout << "? " << pos + 1 << endl;
		string ret;
		cin >> ret;
		return (ret == "Y");
	} else {
		cout << "R" << endl;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	vector <bool> alive(n, true);
	int block = (k == 1 ? 1 : k / 2);
	for (int s = 0; s < n; s += block) {
		for (int i = 0; i < block; i++) {
			if (query(0, s + i)) {
				alive[s + i] = false;
			}
		}
		query(1);
	}

	int sz = n / block;
	for (int i = 0; i < sz; i++) {
		for (int j = i + 1; j < sz; j++) {
			for (int k = 0; k < block; k++) {
				if (!alive[i * block + k]) continue;
				query(0, i * block + k);
			}
			for (int k = 0; k < block; k++) {
				if (!alive[j * block + k]) continue;
				if (query(0, j * block + k)) {
					alive[j * block + k] = false;
				}
			}
			query(1);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += alive[i];
	}
	cout << "! " << cnt << endl;

}