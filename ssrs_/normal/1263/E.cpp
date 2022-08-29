#include <bits/stdc++.h>
using namespace std;
const int INF = 100000000;
template <typename T>
struct lazy_segment_tree{
	int N;
	vector<T> mn, mx;
	vector<T> lazy;
	lazy_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		mn = vector<T>(N * 2 - 1, 0);
		mx = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
	}
	lazy_segment_tree(vector<int> &A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		mn = vector<T>(N * 2 - 1, 0);
		mx = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			mn[N - 1 + i] = A[i];
			mx[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
			mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
		}
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		mn[i] += lazy[i];
    mx[i] += lazy[i];
		lazy[i] = 0;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			lazy[i] += x;
			eval(i);
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			mn[i] = min(mn[i * 2 + 1], mn[i * 2 + 2]);
			mx[i] = max(mx[i * 2 + 1], mx[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	pair<T, T> all(){
		eval(0);
    return make_pair(mn[0], mx[0]);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<char> t(n, '.');
  int p = 0;
  int cnt = 0;
  lazy_segment_tree<int> ST(n);
  for (int i = 0; i < n; i++){
    if (s[i] == 'R'){
      p++;
    } else if (s[i] == 'L'){
      if (p > 0){
        p--;
      }
    } else {
      int add = 0;
      if (t[p] == '('){
        add--;
        cnt--;
      }
      if (t[p] == ')'){
        add++;
        cnt++;
      }
      t[p] = s[i];
      if (t[p] == '('){
        add++;
        cnt++;
      }
      if (t[p] == ')'){
        add--;
        cnt--;
      }
      ST.range_add(p, n, add);
    }
    if (cnt != 0){
      cout << -1;
    } else {
      pair<int, int> P = ST.all();
      if (P.first < 0){
        cout << -1;
      } else {
        cout << P.second;
      }
    }
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}