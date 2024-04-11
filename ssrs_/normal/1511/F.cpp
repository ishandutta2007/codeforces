#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
vector<vector<long long>> matmul(vector<vector<long long>> A, vector<vector<long long>> B){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				ans[i][k] += A[i][j] * B[j][k];
				ans[i][k] %= MOD;
			}
		}
	}
	return ans;
}
vector<vector<long long>> matexp(vector<vector<long long>> A, long long b){
	int N = A.size();
	vector<vector<long long>> ans(N, vector<long long>(N, 0));
	for (int i = 0; i < N; i++){
		ans[i][i] = 1;
	}
	while (b > 0){
		if (b % 2 == 1){
			ans = matmul(ans, A);
		}
		A = matmul(A, A);
		b /= 2;
	}
	return ans;
}
int main(){
  int n, m;
  cin >> n >> m;
  vector<string> S(n);
  for (int i = 0; i < n; i++){
    cin >> S[i];
  }
  vector<pair<string, string>> state;
  for (int i = 0; i < n; i++){
    int sz = S[i].size();
    for (int j = 0; j <= sz; j++){
      for (int k = 0; k <= sz - j; k++){
        string s = S[i].substr(j, k);
        string t = S[i].substr(j);
        state.push_back(make_pair(s, t));
      }
    }
  }
  sort(state.begin(), state.end());
  state.erase(unique(state.begin(), state.end()), state.end());
  int cnt = state.size();
  map<pair<string, string>, int> mp;
  for (int i = 0; i < cnt; i++){
    mp[state[i]] = i;
  }
  vector<vector<long long>> A(cnt, vector<long long>(cnt, 0));
  for (int i = 0; i < cnt; i++){
    string s = state[i].first;
    string t = state[i].second;
    if (!s.empty()){
      s.erase(s.begin());
      t.erase(t.begin());
      int id = mp[make_pair(s, t)];
      A[i][id]++;
    } else if (!t.empty()){
      for (int j = 0; j < n; j++){
        int mn = min(S[j].size(), t.size());
        if (S[j].substr(0, mn) == t.substr(0, mn)){
          string s2 = S[j].substr(1);
          string t2 = t.substr(1);
          if (s2.size() > t2.size()){
            swap(s2, t2);
          }
          int id = mp[make_pair(s2, t2)];
          A[i][id]++;
        }
      }
    } else {
      for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
          int mn = min(S[j].size(), S[k].size());
          if (S[j].substr(0, mn) == S[k].substr(0, mn)){
          string s2 = S[j].substr(1);
          string t2 = S[k].substr(1);
          if (s2.size() > t2.size()){
            swap(s2, t2);
          }
          int id = mp[make_pair(s2, t2)];
            A[i][id]++;
          }
        }
      }
    }
  }
  A = matexp(A, m);
  cout << A[0][0] << endl;
}