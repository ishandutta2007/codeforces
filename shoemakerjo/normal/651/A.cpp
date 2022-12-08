#include <iostream>

using namespace std;

int main() {
	int a1, a2;
	cin >> a1 >> a2;
	int min_lasted = 0;
	
	while (a1 > 0 && a2 > 0 && !(a1==1 && a2==1)) {
		min_lasted++;
		if (a1 < a2) {
			a1++;
			a2-=2;
		}
		else {
			a2++;
			a1-=2;
		}
	}
	cout << min_lasted << endl;
	// cin >> a1;
}