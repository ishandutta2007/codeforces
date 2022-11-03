#include <iostream>
#include <string>

using namespace std;

int main(){
	string a, b;
	cin >> a >> b;
	if (a.size() < b.size())
		a = string(b.size() - a.size(), '0') + a;
	else
		b = string(a.size() - b.size(), '0') + b;
	cout << (a < b ? '<' : a == b ? '=' : '>') << endl;
	return 0;
}