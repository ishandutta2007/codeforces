#include <bits/stdc++.h>
using namespace std;

const int N = 2e6L + 11;
int p[N];

int main() {
	for(int i = 2; i < N; i ++) if(!p[i])
		for(int j = i; j < N; j += i) if(!p[j]) p[j] = i;
	ios :: sync_with_stdio(0);
	int n, x; cin >> n >> x;
	set <int> st;
	for(int i = 1; i <= n; i ++) {
		int x; cin >> x; st.insert(x);
	}
	if(x == 2) cout << "0\n";
	else if(st.count(1)) cout<< "1\n";
	else {
		int ans = 0;
		for(int i = 2; i < x; i ++) if(p[i] == i) {
			if(st.count(i)) ans ++;
			else {
				ans = -1;
				break;
			}
		}
		cout << ans << '\n';
	}
}