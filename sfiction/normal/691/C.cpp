#include <bits/stdc++.h>

using namespace std;

int main(){
	string s;
	cin >> s;
	int b = s.find_first_of('.');
	if (b == string::npos)
		b = s.size();
	else
		s.erase(b, 1);

	int p = s.find_first_not_of('0');
	s.erase(s.begin(), s.begin() + p);
	s.erase(s.begin() + s.find_last_not_of('0') + 1, s.end());
	if (s.size() > 1)
		s.insert(1, 1, '.');
	cout << s;
	if (b -= p + 1)
		cout << 'E' << b << endl;
	return 0;
}