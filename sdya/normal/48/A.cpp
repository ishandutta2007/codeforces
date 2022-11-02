#include <iostream>
#include <string>
#include <string.h>
#include <cstring>

using namespace std;

string s1, s2, s3;

bool g(string s1, string s2)
{
	if (s1 == "rock" && s2 == "scissors") return true;
	if (s1 == "scissors" && s2 == "paper") return true;
	if (s1 == "paper" && s2 == "rock") return true;
	return false;
}

int main()
{
	cin >> s1;
	cin >> s2;
	cin >> s3;
	if (g(s1, s2) && g(s1, s3)) cout << "F" << endl; else
		if (g(s2, s1) && g(s2, s3)) cout << "M" << endl; else
			if (g(s3, s1) && g(s3, s2)) cout << "S" << endl; else
				cout << "?" << endl;
	return 0;
}