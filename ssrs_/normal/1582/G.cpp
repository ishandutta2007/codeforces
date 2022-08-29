#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
const int MAX = 1000000;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n, int x){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, x);
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans = min(ans, ST[k]);
		}
		return ans;
	}
	void range_chmin(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = min(ST[i], x);
			return;
		} else {
			int m = (l + r) / 2;
			range_chmin(L, R, x, i * 2 + 1, l, m);
			range_chmin(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_chmin(int L, int R, T x){
		range_chmin(L, R, x, 0, 0, N);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<char> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> prime(MAX + 1, -1);
  for (int i = 2; i <= MAX; i++){
    if (prime[i] == -1){
      for (int j = i * 2; j <= MAX; j += i){
        prime[j] = i;
      }
    }
  }
  vector<vector<pair<int, int>>> id(MAX);
  for (int i = 0; i < n; i++){
    int x = a[i];
    while (prime[x] != -1){
      int p = prime[x];
      int cnt = 0;
      while (x % p == 0){
        x /= p;
        cnt++;
      }
      if (b[i] == '*'){
        id[p].push_back(make_pair(cnt, i));
      } else {
        id[p].push_back(make_pair(-cnt, i));
      }
    }
    if (x > 1){
      if (b[i] == '*'){
        id[x].push_back(make_pair(1, i));
      } else {
        id[x].push_back(make_pair(-1, i));
      }
    }
  }
  dual_segment_tree<int> ST(n, n);
  for (int i = 0; i < MAX; i++){
    if (!id[i].empty()){
      int cnt = id[i].size();
      stack<pair<int, int>> st;
      st.push(make_pair(-INF, n + 1));
      st.push(make_pair(0, n));
      for (int j = cnt - 1; j >= 0; j--){
        int p = id[i][j].second;
        int pp;
        if (j == 0){
          pp = -1;
        } else {
          pp = id[i][j - 1].second;
        }
        if (id[i][j].first < 0){
          ST.range_chmin(pp + 1, p + 1, p);
          int nxt = st.top().first - id[i][j].first;
          st.push(make_pair(nxt, p));
        } else {
          int nxt = st.top().first - id[i][j].first;
          while (st.size() >= 2){
            pair<int, int> P = st.top();
            st.pop();
            if (st.top().first < nxt){
              st.push(P);
              break;
            }
          }
          int r = st.top().second;
          ST.range_chmin(pp + 1, p + 1, r);
          st.push(make_pair(nxt, p));
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++){
    ans += ST[i] - i;
  }
  cout << ans << endl;
}