#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		BIT = vector<T>(N + 1, 0);
	}
	void add(int i, T x){
		i++;
		while (i <= N){
			BIT[i] += x;
			i += i & -i;
		}
	}
	T sum(int i){
		T ans = 0;
		while (i > 0){
			ans += BIT[i];
			i -= i & -i;
		}
		return ans;
	}
	T query(int L, int R){
		return sum(R) - sum(L);
	}
	T all(){
		return BIT[0];
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int N = s.size();
  vector<vector<vector<binary_indexed_tree<int>>>> BIT(10, vector<vector<binary_indexed_tree<int>>>(10, vector<binary_indexed_tree<int>>(4, binary_indexed_tree<int>(N))));
  for (int i = 0; i < N; i++){
    int id;
    if (s[i] == 'A'){
      id = 0;
    } else if (s[i] == 'T'){
      id = 1;
    } else if (s[i] == 'G'){
      id = 2;
    } else {
      id = 3;
    }
    for (int j = 1; j <= 10; j++){
      int r = i % j;
      int pos = i / j;
      BIT[j - 1][r][id].add(pos, 1);
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int t;
    cin >> t;
    if (t == 1){
      int x;
      char c;
      cin >> x >> c;
      x--;
      int old_id;
      if (s[x] == 'A'){
        old_id = 0;
      } else if (s[x] == 'T'){
        old_id = 1;
      } else if (s[x] == 'G'){
        old_id = 2;
      } else {
        old_id = 3;
      }
      int new_id;
      if (c == 'A'){
        new_id = 0;
      } else if (c == 'T'){
        new_id = 1;
      } else if (c == 'G'){
        new_id = 2;
      } else {
        new_id = 3;
      }
      for (int j = 1; j <= 10; j++){
        int r = x % j;
        int pos = x / j;
        BIT[j - 1][r][old_id].add(pos, -1);
        BIT[j - 1][r][new_id].add(pos, 1);
      }
      s[x] = c;
    }
    if (t == 2){
      int l, r;
      string e;
      cin >> l >> r >> e;
      l--;
      int m = e.size();
      int ans = 0;
      for (int j = 0; j < m; j++){
        int rem = (l + j) % m;
        int id;
        if (e[j] == 'A'){
          id = 0;
        } else if (e[j] == 'T'){
          id = 1;
        } else if (e[j] == 'G'){
          id = 2;
        } else {
          id = 3;
        }
        int l2 = (l + m - rem - 1) / m * m + rem;
        int r2 = (r + m - rem - 1) / m * m + rem;
        ans += BIT[m - 1][rem][id].query(l2 / m, r2 / m);
      }
      cout << ans << "\n";
    }
  }
}