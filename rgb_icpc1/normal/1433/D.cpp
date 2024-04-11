#include <bits/stdc++.h>
using namespace std;

#define MX 6000
typedef pair<int, int> pii;
vector<pii> ans;
int rt[MX], A[MX];

int find_root(int i) {
	if(i == rt[i]) return i;
	return rt[i] = find_root(rt[i]);
}

void merge(int i, int j) {
	i = find_root(i);
	j = find_root(j);
	rt[j] = i;
}

int main() {
//	freopen("in.txt", "r", stdin);
	
	int Tc; cin >> Tc;
	while(Tc --) {
		ans.clear();
		int N; cin >> N;
		for(int i = 0; i < N; i ++) cin >> A[i];
		
		for(int i = 0; i < N; i ++) rt[i] = i;
		for(int i = 0; i < N; i ++) for(int j = i + 1; j < N; j ++) if(find_root(i) != find_root(j) && A[i] != A[j]) {
			merge(i, j);
			ans.push_back(pii(i, j));
		}
		int ok = 1;
		for(int i = 0; i < N; i ++) rt[i] = find_root(i);
		for(int i = 0; i < N; i ++) if(rt[i] != rt[0]) ok = 0;
		if(ok == 0) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			assert(ans.size() == N - 1);
			for(int i = 0; i < N - 1; i ++) cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
		}
	}
	
	return 0;
}