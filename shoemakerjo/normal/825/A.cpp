#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int val = 0;
	int mult = 1;
	string line;
	cin >> line;
	bool innum = false;
	int ct = 0;
	int pt = n-1;
	while (pt >= 0) {
		ct = 0;
		while (pt >= 0 && line[pt]=='1') {
			pt--;
			ct++;
		} 
		if (pt >= 0 && line[pt]=='0') pt--;
		val += mult*ct;
		mult*=10;
	}
	cout << val << endl;
	cin >> n;
}