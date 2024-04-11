#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int w[n];
	priority_queue<pii, vector<pii>, greater<pii>> pqi;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
		pqi.push(pii(w[i], i+1));
	}
	string line;
	cin >> line;
	priority_queue<pii> pqe; // for extroverts

	for (int i = 0; i < 2*n; i++) { 
		if (line[i] == '0') {
			pii cur = pqi.top(); pqi.pop();
			// int val = cur.first
			cout << cur.second << " ";
			pqe.push(cur);
		}
		else {
			pii cur = pqe.top(); pqe.pop();
			cout << cur.second << " ";
		}
	}
	cout << endl;
	cin >> n;
}