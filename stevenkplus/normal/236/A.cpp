#include <iostream>

using namespace std;

const int MAXC = 1000;
bool in[MAXC];
int main() {
	string s;
	cin >> s;
	for(int i = 0; i < int(s.size()); ++i) {
		char c = s[i];
		in[int(c)] = true;
	}
	int dist = 0;
	for(int i = 0; i < MAXC; ++i) {
		if (in[i]) dist++;
	}
	cout<<(dist % 2 == 1? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
	return 0;
}