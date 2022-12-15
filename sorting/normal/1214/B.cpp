#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int b, g, n;

	cin >> b >> g >> n;

	cout << min(b + g - n, min(b, min(g, n))) + 1 << endl;

	return 0;
}