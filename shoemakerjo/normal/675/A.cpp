#include <iostream>

using namespace std;

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	if (c == 0) {
		if (a == b) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (c > 0) {
		if (b >= a && (b-a)%c==0) {
			cout <<"YES" << endl;
		}
		else cout << "NO" << endl;
	}
	else {
		if (b<=a && (a-b)%(-c)==0) {
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	// cin >> a;
}