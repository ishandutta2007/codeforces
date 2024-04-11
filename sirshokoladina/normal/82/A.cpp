#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define forn(i,n) for (int i = 0; i < (int)(n); i++)

string a[6] = {"", "Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int main() {
	int n;
	cin >> n;
	while (n > 5) {
		n = (n - 4) / 2;
	}
	cout << a[n];
}