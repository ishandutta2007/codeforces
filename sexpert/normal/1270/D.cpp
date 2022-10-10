#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
vector<int> v;

void ask(int i) {
	cout << "? ";
	for(int j = 1; j <= k + 1; j++) {
		if(j != i)
			cout << j << " ";
	}
	cout << '\n';
	cout.flush();
	int p, x;
	cin >> p >> x;
	v.push_back(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= k + 1; i++) ask(i);
	sort(v.begin(), v.end());
	int p = 0;
	for(;;p++)
		if(v[p] != v[p + 1])
			break;
	cout << "! " << k - p << '\n';
	cout.flush();
}