#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	int fsize, mosize, ssize, masize;
	cin >> fsize >> mosize >> ssize >> masize;
	int sizebound = 2*fsize;
	for (int car3 = masize; car3 <= sizebound; ++car3) {
		for (int car2 = masize; car2 < car3; ++car2) {
			for (int car1 = masize; car1 < car2; ++car1) {
				if ((fsize <= car3) && (car3 <= 2*fsize) &&
					(mosize <= car2) && (car2 <= 2*mosize) &&
					(ssize <= car1) && (car1 <= 2*ssize) &&
					(car1 <= 2*masize) && !(car2 <= 2*masize) && !(car3 <= 2*masize)) {
					cout << car3 << " " << car2 << " " << car1 << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}