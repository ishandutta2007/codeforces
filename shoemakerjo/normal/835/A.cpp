#include <iostream>

using namespace std;

int main() {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int end1 = t1+v1*s + t1;
	int end2 = t2+v2*s + t2;
	if (end1 < end2) {
		cout << "First" << endl;
	}
	else if (end2 < end1) {
		cout << "Second" << endl;
	}
	else cout << "Friendship" << endl;
	// cout << end1 << " " << end2 << endl;
	// cin >> s;
}