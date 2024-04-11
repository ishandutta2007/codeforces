#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
template <typename T>
struct range_add_range_max{
	int N;
	vector<T> ST;
	vector<T> lazy;
	range_add_range_max(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		lazy = vector<T>(N * 2 - 1, 0);
	}
	void eval(int i){
		if (i < N - 1){
			lazy[i * 2 + 1] += lazy[i];
			lazy[i * 2 + 2] += lazy[i];
		}
		ST[i] += lazy[i];
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
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	T range_max(int L, int R, int i, int l, int r){
		eval(i);
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return max(range_max(L, R, i * 2 + 1, l, m), range_max(L, R, i * 2 + 2, m, r));
		}
	}
	T range_max(int L, int R){
		return range_max(L, R, 0, 0, N);
	}
};
int main(){
  int n, k, m;
  cin >> n >> k >> m;
  range_add_range_max<int> S(4000001);
  for (int i = 0; i < 400000; i++){
    S.range_add(i + 1, i + 2, i + 1);
  }
  set<pair<int, int>> st;
  multiset<int> st2;
  for (int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    int c = y + abs(k - x);
    if (!st.count(make_pair(y, x))){
      st.insert(make_pair(y, x));
      st2.insert(c);
      S.range_add(0, c, 1);
    } else {
      st.erase(make_pair(y, x));
      st2.erase(st2.find(c));
      S.range_add(0, c, -1);
    }
    if (st.empty()){
      cout << 0 << endl;
    } else {
      int mx = *prev(st2.end());
      int tmp = S.range_max(0, mx + 1);
      cout << max(tmp, n) - n << endl;
    }
  }
}