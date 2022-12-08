#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int high = n+1;
	int low = 1;
	int last = 1;
	cout << 1 << " ";
	
	for (int i = 0; i < k-1; i++) {
		if (i%2 == 0) {
			high--;
			cout << high << " ";
			last = high;
		}
		else {
			low++;
			cout << low << " ";
			last = low;
		}
	}
	if (last == low) {
		for (int i = low+1; i < high; i++) {
			cout << i << " ";
		}
	}
	else {
		for (int i = high-1; i > low; i--) {
			cout << i << " ";
		}
	}
	cout << endl;
	cin >> n;
}