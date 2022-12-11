#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int h; cin >> h; ++h;
	vector<int> cts(h, 0);
	for (int i = 0; i < h; ++i) {
		cin >> cts[i];
	}
	bool possible = false;
	for (int i = 0; i < h - 1; ++i) {
		if (cts[i] > 1 && cts[i+1] > 1) {
			possible = true;
		}
	}
	if (!possible) {
		cout << "perfect\n";
		return 0;
	}
	cout << "ambiguous\n";
	vector<vector<int>> indices(h, vector<int>()); 
	int counter = 1;
	for (int layer = 0; layer < h; ++layer) {
		for (int nil = 0; nil < cts[layer]; ++nil) {
			indices[layer].push_back(counter++);
		}
		reverse(indices[layer].begin(), indices[layer].end());
	}
	// print the first tree
	cout << "0";
	for (int layer = 1; layer < h; ++layer) {
		for (int i = 0; i < cts[layer]; ++i) {
			cout << " " << indices[layer-1][0];
		}
	}
	cout << endl;
	// print the second tree
	cout << "0";
	for (int layer = 1; layer < h; ++layer) {
		cout << " " << indices[layer-1][0];
		for (int i = 1; i < cts[layer]; ++i) {
			cout << " " << indices[layer-1][(cts[layer-1] > 1 ? 1 : 0)];
		}
	}
	cout << endl;
	return 0;
}