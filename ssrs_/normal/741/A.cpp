#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cycle_decomposition(vector<int> &P){
	int N = P.size();
	vector<bool> used(N, false);
	vector<vector<int>> ans;
	for (int i = N - 1; i >= 0; i--){
		if (used[i]) continue;
		vector<int> C;
		C.push_back(i);
		while (C.front() != P[C.back()]){
			C.push_back(P[C.back()]);
			used[C.back()] = true;
		}
	ans.push_back(C);
	}
	return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  vector<int> q(n, 0);
  for (int i = 0; i < n; i++){
    q[p[i]]++;
  }
  bool ok = true;
  for (int i = 0; i < n; i++){
    if (q[i] != 1){
      ok = false;
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    vector<vector<int>> c = cycle_decomposition(p);
    int cnt = c.size();
    vector<int> sz(cnt);
    for (int i = 0; i < cnt; i++){
      if (c[i].size() % 2 == 0){
        sz[i] = c[i].size() / 2;
      } else {
        sz[i] = c[i].size();
      }
    }
    int ans = 1;
    for (int i = 0; i < cnt; i++){
      ans = lcm(ans, sz[i]);
    }
    cout << ans << endl;
  }
}