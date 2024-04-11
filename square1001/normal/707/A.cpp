#include <string>
#include <iostream>
using namespace std;
int H, W; string s;
int main() {
	cin >> H >> W;
	bool f = true;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> s;
			if (s != "B" && s != "G" && s != "W") f = false;
		}
	}
	cout << (f ? "#Black&White" : "#Color") << endl;
	return 0;
}