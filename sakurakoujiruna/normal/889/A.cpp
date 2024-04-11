#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

const int N = 2e5L + 11;
bool v[N];
int a[N];

int main() {
	ios :: sync_with_stdio(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = n; i >= 1; i --) if(!v[i]) {
		ans ++;
		for(int j = i; j && !v[j]; j = a[j])
			v[j] = 1;
	}
	cout << ans << '\n';
	
	return 0;
}