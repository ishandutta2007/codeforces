#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) cout << (char)(i % m + 97);
	return 0;
}