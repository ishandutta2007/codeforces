#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int nums[k];
	for (int i = 0; i < k; i++) {
		cin >> nums[i];
	}
	int fo = n;
	int tw = n*2;
	int on = 0;
	bool ok = true;
	int cur;
	int vals[4];
	for (int i = 0; i < 4; i++) {
		vals[i] = 0;
	}
	for (int i = 0; i < k; i++) {
		if (tw < 0 || fo < 0 || on < 0)  ok = false;
		cur = nums[i];
		while (cur >= 4) {
			if (fo > 0) {
				fo--;
			}
			else tw-=2;
			cur-=4;
		}
		vals[cur]++;
	}
	for (int i = 0; i < vals[3]; i++) {
		if (tw < 0 || fo < 0 || on < 0)  ok = false;

		if (fo > 0) {
			fo--;
		}
		else if (tw > 0) {
			tw--;
			vals[1]++;
		}
		else {
			vals[1]++;
			vals[2]++;
		}
	}
	for (int i = 0; i < vals[2]; i++) {
		if (tw > 0) tw--;
		else {
			if (fo > 0) {
				fo--;
				on++;
			}
			else {
				vals[1]+=2;
			}
		}
	}
	for (int i = 0; i < vals[1]; i++) {
		if (fo > 0) {
			fo--;
			on++;
		}
		else if (tw > 0) tw--;
		else if (on > 0) on--;
		else ok = false;
	}
	if (fo >= 0 && tw >= 0 && ok) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
	cin >> n;
}