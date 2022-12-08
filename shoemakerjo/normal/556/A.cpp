#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int prev = -1;
	int prevcount = 0;
	int length = n;
	for (int i = 0; i < n; ++i) {
		if (s[i]=='1') {
			if (prev == -1) {
				prev = 1;
				prevcount = 1;
			}
			else if (prev == 1) prevcount++;
			else {
				if (prevcount == 0) {
					prev = 1;
					prevcount = 1;
					continue;
				}
				prevcount--;
				length-=2;
			}
		}
		else { //'0'
			if (prev == -1) {
				prev = 0;
				prevcount = 1;
				continue;
			}
			else if (prev == 0) prevcount++;
			else {
				if (prevcount == 0) {
					prev = 0;
					prevcount = 1;
					continue;
				}
				prevcount--;
				length-=2;
			}
		}
	}
	cout << length << endl;
	
}