#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

bool pr(int x) {
	for (int i = 2; i*i <= x; i ++)
		if (x%i == 0) return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int m = 1; ; m ++) 
		if (!pr(n*m+1)) {
			cout << m << endl;
			break;
		}
	return 0;
}