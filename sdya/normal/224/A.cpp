#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; ++i) {
		int j = s1 / i;
		{
			int k = s2 / i;
			if (i * j == s1 && i * k == s2 && j * k == s3) {
				cout << 4 * (i + j + k) << endl;
				return 0;
			}
		}
		{
			int k = s3 / i;
			
			if (i * j == s1 && i * k == s3 && j * k == s2) {
				cout << 4 * (i + j + k) << endl;
				return 0;
			}
		}
	}
	return 0;
}