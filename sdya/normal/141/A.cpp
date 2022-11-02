#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>

using namespace std;

multiset < int > A, B;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	string s1, s2, s;
	cin >> s1 >> s2 >> s;
	for (int i = 0; i < s1.size(); ++i)
		A.insert(s1[i]);
	for (int i = 0; i < s2.size(); ++i)
		A.insert(s2[i]);

	for (int i = 0; i < s.size(); ++i)
		B.insert(s[i]);

	if (A == B) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}


	return 0;
}