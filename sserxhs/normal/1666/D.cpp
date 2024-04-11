#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
void work() {
	string S, T;
	cin >> S >> T;
	vector<vector<int>> app(27);
	int n = S.length();
	int m = T.length();
	for (int i = 0; i < n; i += 1) {
		app[S[i] - 'A'].push_back(i);
	}
	vector<int> pos(m);
	for (int i = m - 1; i >= 0; i -= 1) {
		if (app[T[i] - 'A'].size() == 0) {
			cout << "NO\n";
			return ;
		} 
		pos[i] = app[T[i] - 'A'].back();
		app[T[i] - 'A'].pop_back();
	}
	for (int i = 0; i < m - 1; i += 1) {
		if (pos[i + 1] < pos[i]) {
			cout << "NO\n";
			return ;
		}
	}
	cout << "YES\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		work();
	}
}