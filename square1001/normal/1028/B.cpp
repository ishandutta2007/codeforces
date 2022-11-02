#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	int half = 1000;
	string ls = "4" + string(half - 1, '9') + string(half - 1, '0') + "1";
	string rs = "5" + string(half - 1, '0') + string(half, '9');
	cout << ls << endl;
	cout << rs << endl;
	return 0;
}