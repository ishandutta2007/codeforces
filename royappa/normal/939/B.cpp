#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL n;
	int k;
	cin >> n >> k;
	vector<LL> cap(k);
	for (int i = 0; i < k; i++) {
		cin >> cap[i];
	}
	LL bestK, numBoxes;
	bestK = 0;
	numBoxes = n/cap[bestK];
	for (int i = 1; i < k; i++) {
		if ((n/cap[i])*cap[i] > cap[bestK]*numBoxes) {
			bestK = i;
			numBoxes = n/cap[i];
		}
	}
	cout << bestK+1 << " " << numBoxes << endl;
	exit(0);
}