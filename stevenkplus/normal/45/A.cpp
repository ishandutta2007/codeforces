#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

const string mos[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

map<string, int> mymap;

void prec() {
	for(int i = 0; i < 12; ++i) {
		mymap[mos[i]] = i;
	}
}

int main() {
	string n;
	cin >> n;
	int diff;
	cin >> diff;
	prec();

	int cur = mymap[n];
	int end = (cur + diff) % 12;
	string ans = mos[end];
	cout << ans << endl;
}