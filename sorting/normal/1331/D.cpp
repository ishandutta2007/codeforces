#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	cout << (s.back() - '0') % 2 << "\n";
}