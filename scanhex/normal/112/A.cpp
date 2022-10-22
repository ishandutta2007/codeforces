#include <iostream>
#include <string>
#define ll long long

using namespace std;

int main()
{                       
	string s1,s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); ++i) 
		s1[i] = s1[i] <= 'Z' ? s1[i] + 32 : s1[i];

	for (int i = 0; i < s1.length(); ++i) 
		s2[i] = s2[i] <= 'Z' ? s2[i] + 32 : s2[i];

	cout << s1.compare(s2);
}