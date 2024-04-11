#include <iostream>
#include <string>
using namespace std;

int main() {
	int ans = 0;
	int n;
	cin >> n;
	string cur;
	for (int i = 0; i < n; ++i) {
		cin >> cur;
		if (cur == "Icosahedron") ans+=20;
		if (cur == "Cube") ans+=6;
		if (cur == "Tetrahedron") ans+=4;
		if (cur == "Octahedron") ans+=8;
		if (cur == "Dodecahedron") ans+=12;
	}
	cout << ans << endl;
	// cin >> n;
}