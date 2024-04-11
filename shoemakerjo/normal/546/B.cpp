#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int nums[n*2+1];
	for (int i = 0; i <= 2*n; i++) {
		nums[i] = 0;
	}
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		nums[cur]++;
	}
	int cost = 0;
	int goal = 0;
	for (int i = 0; i <= 2*n; i++) {
		goal = max(goal, i);
		while (nums[i] > 1) {
			while (nums[goal] > 0) {
				goal++;

			}
			nums[goal] = 1;
			nums[i]--;
			cost+=goal-i;
		}
	}
	cout << cost << endl;
	// cin >> n;
}