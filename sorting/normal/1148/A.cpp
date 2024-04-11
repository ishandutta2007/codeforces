#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b, c;

	cin >> a >> b >> c;

	long long res = 2 * c + 2 * min(a, b);

	if(min(a, b) != max(a, b)){
		res++;
	}

	cout << res << "\n";

	return 0;
}