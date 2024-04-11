#include <iostream>

using namespace std;

int coords[101][2];
bool visited[101];
int n;

void flood(int cur) {
	for (int i = 0; i < n; i++) {
		if (visited[i] ) continue;
		if (coords[cur][0] == coords[i][0] || 
			coords[cur][1] == coords[i][1]) {
			visited[i] = true;
			flood(i);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> coords[i][0] >> coords[i][1];
		visited[i] = false;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			ans++;
			visited[i] = true;
			flood(i);
		}
	}
	cout << ans -1 << endl;
	cin >> n;
}