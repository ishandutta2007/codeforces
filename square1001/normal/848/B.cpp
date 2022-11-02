#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N, W, H, g[100009], p[100009], t[100009], ansx[100009], ansy[100009]; vector<int> v[200009];
int main() {
	cin >> N >> W >> H;
	for (int i = 0; i < N; i++) {
		cin >> g[i] >> p[i] >> t[i];
		v[p[i] - t[i] + 100000].push_back(i);
	}
	for (int i = 0; i <= 200000; i++) {
		vector<pair<int, int> > cx, cy;
		for (int j : v[i]) {
			if (g[j] == 1) cx.push_back(make_pair(p[j], j));
			if (g[j] == 2) cy.push_back(make_pair(p[j], j));
		}
		sort(cx.begin(), cx.end());
		sort(cy.begin(), cy.end());
		for (int j = 0; j < cx.size(); j++) {
			int lpos = j + cy.size();
			if (lpos < cx.size()) {
				ansx[cx[j].second] = cx[lpos].first;
				ansy[cx[j].second] = H;
			}
			else {
				ansx[cx[j].second] = W;
				ansy[cx[j].second] = cy[cx.size() + cy.size() - lpos - 1].first;
			}
		}
		for (int j = 0; j < cy.size(); j++) {
			int lpos = cy.size() - j - 1;
			if (lpos < cx.size()) {
				ansx[cy[j].second] = cx[lpos].first;
				ansy[cy[j].second] = H;
			}
			else {
				ansx[cy[j].second] = W;
				ansy[cy[j].second] = cy[cx.size() + cy.size() - lpos - 1].first;
			}
		}
	}
	for (int i = 0; i < N; i++) cout << ansx[i] << ' ' << ansy[i] << endl;
	return 0;
}