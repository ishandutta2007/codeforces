#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int curspeed = v0;
	int count = 1;
	int num = v0;
	while (1) {
		if (num >= c) break;
		curspeed += a;
		curspeed = min(curspeed, v1);
		num-=l;
		count++;
		num+=curspeed;
	}
	cout << count << endl;
	// cin >> c;
}