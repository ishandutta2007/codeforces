#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a;
	int b;
	int ma;
	int mi;
	cin >> a >> b;
	ma = max(a,b);
	mi = min(a,b);
	int first = mi;
	ma -= mi;
	int second = ma/2;
	cout << first << " " << second << endl;
}