#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E2 + 10;

int main(){
	int n, m;
	cin >> n >> m;
	string s;
	int ans = 0, cnt = 0;
	for (int i = 0; i < m; ++i){
		cin >> s;
		s.resize(MAXN, '1');
		if (!bitset<MAXN>(s).all())
			ans = max(ans, ++cnt);
		else
			cnt = 0;
	}
	printf("%d\n", ans);
	return 0;
}