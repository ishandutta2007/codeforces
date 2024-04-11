#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int t;
	cin >> t;
	for (int k = 0; k < t; ++k) {
		string strn;
		int s;
		cin >> strn >> s;
		vector<int> n = { 0, 0 };
		int summ = 0;
		for (char x : strn) {
			n.push_back(x - '0');
			summ += x - '0';
		}

		reverse(n.begin(), n.end());
		vector<int> moves(n.size(), 0);
		int non_zero = 0;
		for (int i = 0; i < n.size() - 1; ++i) {
			
			for (int j = i; n[j] >= 10; ++j) {
				if (n[j] != 10) {
					summ -= n[j] - 10 - 1;
				}
				else {
					summ -= n[j] - 1;
				}
				n[j + 1] += 1;
				n[j] = n[j] - 10;
			}
			if (summ <= s) {
				break;
			}
			non_zero = i;
			moves[i] += 10 - n[i];
			for (int j = i; moves[j] >= 10; ++j) {
				moves[j] -= 10;
				++moves[j + 1];
				non_zero = j + 1;
			}
			++n[i + 1];
			summ -= n[i] - 1;
			n[i] = 0;
		}

		for (int i = non_zero; i >= 0; --i) {
			cout << moves[i];
		}
		cout << '\n';
	}
	return 0;
}