#include <bits/stdc++.h>

using namespace std;

vector<int> segs;
int k;

bool check(int val) {
	int ck = k;
	int csum = 0;
	for (int i = 0; i < segs.size(); i++) {
		if (segs[i] > val) return false;
		if (csum + segs[i] > val) {
			ck--;
			csum = segs[i];
		}
		else csum += segs[i];
	}
	return ck >= 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k;
	string line;
	getline(cin, line);
	getline(cin, line);
	// cout << line << endl;
	
	int cl = 0;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' '|| line[i] == '-') {
			cl++;
			segs.push_back(cl);
			cl = 0;
		}
		else cl++;
	}
	if (cl != 0) segs.push_back(cl);
	int low = 0;
	int high = 1000000000;

	while (low < high) {
		int mid = (low+high)/2;
		// cout << mid << " ";
		if (check(mid)) {
			high = mid;
			// cout << "worked";
		}
		else low = mid+1;
		// cout << endl;
	}
	cout << low << endl;
	cin >> k;

}