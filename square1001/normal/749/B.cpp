#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#pragma warning(disable : 4996)
using namespace std;
int a1, a2, b1, b2, c1, c2;
int main() {
	cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
	int av1 = b1 - a1, av2 = b2 - a2;
	int bv1 = c1 - b1, bv2 = c2 - b2;
	int cv1 = a1 - c1, cv2 = a2 - c2;
	cout << 3 << endl;
	cout << a1 + bv1 << ' ' << a2 + bv2 << endl;
	cout << a1 - bv1 << ' ' << a2 - bv2 << endl;
	cout << a1 + av1 - cv1 << ' ' << a2 + av2 - cv2 << endl;
	return 0;
}