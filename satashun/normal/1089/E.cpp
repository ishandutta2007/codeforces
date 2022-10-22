#include <bits/stdc++.h>

using namespace std;

int N;

void out(bool first, int x, int y) {
	cout << (first ? "" : " ") << char('a' + x) << char('1' + y);
}

int main() {
	cin >> N;
	if(N <= 56) {
		int x = 0, y = 0;
		int i = 0;
		while(true) {
			out(i == 0, x, y);
			++i;
			if(i < N - 1) {
				if(y % 2 == 0) {
					if(x <= 6) ++x;
					else ++y;
				} else {
					if(x >= 1) --x;
					else ++y;
				}
			} else break;
		}
		if(x != 7) {
			out(false, x, 7);
			out(false, 7, 7);
		} else {
			out(false, 7, 6);
			out(false, 7, 7);
		}
		cout << endl;
	} else {
		int x = 0, y = 0;
		int i = 0;
		while(true) {
			out(i == 0, x, y);
			++i;
			if(i < 48) {
				if(y % 2 == 0) {
					if(x <= 6) ++x;
					else ++y;
				} else {
					if(x >= 1) --x;
					else ++y;
				}
			} else break;
		}
		out(false, 0, 6);
		out(false, 7, 6);
		out(false, 6, 6);
		out(false, 5, 6);
		out(false, 4, 6);
		out(false, 3, 6);
		out(false, 2, 6);
		out(false, 1, 6);
		int a[7] = {1, 0, 2, 3, 4, 5, 6};
		for(i = 0; i < N - 56; ++i) {
			out(false, a[i], 7);
		}
		out(false, 7, 7);
		cout << endl;
	}
	return 0;
}