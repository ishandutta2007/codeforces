#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
	vector<int>x1(4);
	vector<int>x2(4);
	vector<int>y1(4);
	vector<int>y2(4);
	for (int i = 0; i < 4; i++) {
		cin >> x1[i] >> y1[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> x2[i] >> y2[i];
	}
	int xmi1 = x1[0];
	int xma1 = x1[0];
	int ymi1 = y1[0];
	int yma1 = y1[0];
	for (int i = 1; i < 4; i++) {
		xmi1 = min(xmi1, x1[i]);
		ymi1 = min(ymi1, y1[i]);
		xma1 = max(xma1, x1[i]);
		yma1 = max(yma1, y1[i]);
	}
	vector<vector<int>>a(((xma1 + 1) - (xmi1)) * (yma1 + 1 - ymi1), vector<int>(2));
	for (int i = 0; i < (xma1 + 1 - xmi1) * (yma1 + 1 - ymi1); i++) {
		a[i][0] = i % (yma1 + 1 - ymi1) + xmi1;
		a[i][1] = i / (yma1 + 1 - ymi1) + ymi1;
	}
	int xmi2 = x2[0];
	int xma2 = x2[0];
	int ymi2 = y2[0];
	int yma2 = y2[0];
	for (int i = 1; i < 4; i++) {
		xmi2 = min(xmi2, x2[i]);
		ymi2 = min(ymi2, y2[i]);
		xma2 = max(xma2, x2[i]);
		yma2 = max(yma2, y2[i]);
	}
	vector<vector<int>>b(50000, vector<int>(2, -1000));
	int k = 0;
	for (int i = 0; i < (yma2 - ymi2) / 2 + 1; i++) {
		for (int j = 0; j < 2 * i + 1; j++) {
			b[k][0] = (xmi2 + xma2) / 2 - i + j;
			b[k][1] = ymi2 + i;
			k += 1;
		}
	}
	
	for (int i = 1; i < (yma2 - ymi2) / 2 + 1; i++) {
		for (int j = 0; j < (yma2 - ymi2) + 1 - 2 * i; j++) {
			b[k][1] = (ymi2 + yma2) / 2 + i;
			b[k][0] = xmi2 + i + j;
			k += 1;
		}
	}
	for (int i = 0; i < (int)b.size(); i++) {
		for (int j = 0; j < (int)a.size(); j++) {
			if (b[i][0] == -1000) {
				cout << "NO";
				return 0;
			}
			if (b[i][0] == a[j][0] && b[i][1] == a[j][1]) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}