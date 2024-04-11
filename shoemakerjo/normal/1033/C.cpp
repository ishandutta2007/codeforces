#include <bits/stdc++.h>

using namespace std;

#define maxn 100010

int n;
int nums[maxn];
bool startwin[maxn]; //canwin for this number
int myind[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		myind[nums[i]] = i;

	}

	for (int i = n; i >= 1; i--) {
		int curind = myind[i];
		for (int j = 1; j * i <= n; j++) {
			int nx1 = curind + j*i;
			int nx2 = curind - j*i;

			if (nx1 >= 0 && nx1 < n && nums[nx1] > i && !startwin[nx1]) {
				startwin[curind] = true;
			} 
			if (nx2 >= 0 && nx2 < n && nums[nx2] > i && !startwin[nx2]) {
				startwin[curind] = true;
			}
		}
	}


	for (int i = 0; i < n; i++) {
		if (startwin[i]) {
			cout << "A";
		}
		else cout << "B";
	}
	cout << endl;
}