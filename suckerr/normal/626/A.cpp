#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int N = 222;

int main() {
	static char buffer[N];
	int n;

	scanf("%d", &n);
	scanf("%s", buffer);
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		for (int j = i; j < n; j++) {
			if (buffer[j] == 'U') {
				y++;
			} else if (buffer[j] == 'D') {
				y--;
			} else if (buffer[j] == 'L') {
				x--;
			} else if (buffer[j] == 'R') {
				x++;
			}
			if (x == 0 && y == 0) {
				answer++;
			}
		}
	}
	cout << answer << endl;
	return 0;
}