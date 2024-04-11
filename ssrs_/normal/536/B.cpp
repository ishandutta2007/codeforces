#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
vector<int> z_algorithm(string S){
	int N = S.size();
	vector<int> ans(N);
	for (int i = 1, j = 0; i < N; i++){
		if (i + ans[i - j] < j + ans[j]){
			ans[i] = ans[i - j];
		} else {
			int k = max(0, j + ans[j] - i);
			while (i + k < N && S[k] == S[i + k]){
				k++;
			}
			ans[i] = k;
			j = i;
		}
	}
	ans[0] = N;
	return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  string p;
  cin >> p;
  vector<int> y(m);
  for (int i = 0; i < m; i++){
    cin >> y[i];
    y[i]--;
  }
  int L = p.size();
  vector<int> Z = z_algorithm(p);
  bool ok = true;
  for (int i = 0; i < m - 1; i++){
    int d = y[i + 1] - y[i];
    if (d < L){
      if (Z[d] != L - d){
        ok = false;
      }
    }
  }
  if (!ok){
    cout << 0 << endl;
  } else {
    vector<int> imos(n + 1, 0);
    for (int i = 0; i < m; i++){
      imos[y[i]]++;
      imos[y[i] + L]--;
    }
    for (int i = 0; i < n; i++){
      imos[i + 1] += imos[i];
    }
    long long ans = 1;
    for (int i = 0; i < n; i++){
      if (imos[i] == 0){
        ans *= 26;
        ans %= MOD;
      }
    }
    cout << ans << endl;
  }
}