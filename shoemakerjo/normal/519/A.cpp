#include <iostream>

using namespace std;

int main() {
	// q', 'r', 'b', 'n', 'p', 'k
	//95331
	int w = 0, b = 0;
	char cur;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> cur;
			//w is cap
			if (cur == 'Q') w+=9;
			if (cur == 'R') w+=5;
			if (cur == 'B') w+=3;
			if (cur == 'N') w+=3;
			if (cur == 'P') w+=1;

			if (cur == 'q') b+=9;
			if (cur == 'r') b+=5;
			if (cur == 'b') b+=3;
			if (cur == 'n') b+=3;
			if (cur == 'p') b+=1;
		}
	}
	if (w > b) cout << "White" << endl;
	if (b > w) cout << "Black" << endl;
	if (w==b) cout << "Draw" << endl;
	// cin >> w;
}