#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 500005;
deque<int> Q;
int Tc, N;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int x;
	for (cin >> Tc; Tc--; ) {
		cin >> N;
		for(int i = 0 ; i < N ; i ++) {
			cin >> x;
			if(x > Q.front()) Q.push_back(x);
			else Q.push_front(x);
		}
		while(!Q.empty()) {
			x = Q.front();Q.pop_front();
			cout << x << ' ';
		}
		cout << endl;
	}

	return 0;

}