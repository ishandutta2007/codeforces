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
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  int sz = cycle_decomposition(p).size();
  int ans;
  if (sz == 1){
    ans = 0;
  } else {
    ans = sz;
  }
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += b[i];
  }
  if (sum % 2 == 0){
    cout << ans + 1 << endl;
  } else {
    cout << ans << endl;
  }
}