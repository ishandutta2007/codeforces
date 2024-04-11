#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int tc;
	cin >> tc;
	string line;
	if ( tc > 0) getline(cin,line);
	for (int i = 1; i <= tc ;i++ ) {
		getline(cin,line);
		int miaopos = line.find("miao.");
		reverse(line.begin(),line.end());
		int lalapos = line.find(".alal");
		if (miaopos == 0 && lalapos != 0) {
			cout << "Rainbow's" << endl;
		} else if (lalapos == 0 && miaopos!=0){
			cout << "Freda's" << endl;
		} else {
			cout << "OMG>.< I don't know!" << endl;
		}
	}
	return 0;
}