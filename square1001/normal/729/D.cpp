#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int n, a, b, k, c[210000]; string S;
int main() {
	cin >> n >> a >> b >> k >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '1') { c[i + 1]--; c[max(0, i - b + 1)]++; }
	}
	for (int i = 1; i < 210000; i++)c[i] += c[i - 1]; c[n - b + 1] = 10000;
	vector<pair<int, int>>E;
	int t = 0, o = 0, p = 0;
	for (int i = 0; i <= n - b + 1; i++) {
		if (c[i] == 0)t++;
		if (c[i] == 0 && c[i + 1] >= 1) { E.push_back(make_pair((t + b - 1) / b, i)); o += (t + b - 1) / b; t = 0; }
	}
	cout << o - a + 1 << endl;
	for (int i = 0; i < E.size(); i++) {
		for (int j = 0; j < E[i].first; j++) {
			if (o < a)continue;
			if (p)cout << ' '; p++;
			cout << E[i].second - j * b + 1; o--;
		}
	}
	cout << endl;
	return 0;
}