#include <iostream>
#include <string>
using namespace std;

int main() {
	int k; cin >> k;
	string line;
	cin >> line;
	int sod = 0;
	int nums[10];
	for (int i = 0; i < 10; i++) {
		nums[i] = 0;
	}
	int cur;
	for (int i = 0; i < line.length(); i++) {
		cur = line[i]-'0';
		nums[cur]++;
		sod+=cur;
	}
	int change = 0;
	for (int i = 0; i < 10; i++) {
		while (sod < k && nums[i] > 0) {
			nums[i]--;
			sod += 9-i;
			change++;
		}
	}
	cout << change << endl;
	// cin >> k;
}