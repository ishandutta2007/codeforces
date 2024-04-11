#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int y, w;
	cin >> y >> w;
	int win = 6-max(y, w)+1;
	if (win == 0) cout << "0/1" << endl;
	if (win == 1) cout << "1/6" << endl;
	if (win == 2) cout << "1/3" << endl;
	if (win == 3) cout << "1/2" << endl;
	if (win == 4) cout << "2/3" << endl;
	if (win == 5) cout << "5/6" << endl;
	if (win == 6) cout << "1/1" << endl;
	cin >> y;
}