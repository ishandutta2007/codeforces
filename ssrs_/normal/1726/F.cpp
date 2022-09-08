#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<pair<T, int>> ST;
	int t;
	dual_segment_tree(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<pair<T, int>>(N * 2 - 1, make_pair(0, 0));
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = make_pair(A[i], 1);
		}
		t = 2;
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k].first;
		T time = ST[k].second;
		while (k > 0){
			k = (k - 1) / 2;
			if (ST[k].second > time){
				ans = ST[k].first;
				time = ST[k].second;
			}
		}
		return ans;
	}
	void range_update(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] = make_pair(x, t);
		} else {
			int m = (l + r) / 2;
			range_update(L, R, x, i * 2 + 1, l, m);
			range_update(L, R, x, i * 2 + 2, m, r);
		}
	}
	void range_update(int L, int R, T x){
		range_update(L, R, x, 0, 0, N);
		t++;
	}
};
int lower_bound(dual_segment_tree<long long> &ST, int N, long long x){
  int tv = 0, fv = N + 1;
  while (fv - tv > 1){
    int mid = (tv + fv) / 2;
    if (ST[mid - 1] < x){
      tv = mid;
    } else {
      fv = mid;
    }
  }
  return tv;
}
long long get(long long a, long long t, long long r){
  if (a % t <= r){
    return a + (r - a % t);
  } else {
    return a + (r - a % t + t);
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, t;
  cin >> n >> t;
  vector<int> g(n), c(n);
  for (int i = 0; i < n; i++){
    cin >> g[i] >> c[i];
  }
  vector<int> d(n - 1);
  for (int i = 0; i < n - 1; i++){
    cin >> d[i];
  }
  vector<long long> s(n);
  s[0] = 0;
  for (int i = 0; i < n - 1; i++){
    s[i + 1] = s[i] + d[i];
  }
  for (int i = 0; i < n; i++){
    c[i] = (c[i] + s[i]) % t;
  }
  vector<long long> x;
  x.push_back(0);
  for (int i = 0; i < n; i++){
    x.push_back((g[i] - c[i] + t) % t);
    x.push_back((t - c[i]) % t);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int cnt = x.size();
  vector<long long> A(cnt);
  for (int i = 0; i < cnt; i++){
    A[i] = x[i];
  }
  dual_segment_tree<long long> ST(A);
  for (int i = 0; i < n; i++){
    int L = (g[i] - c[i] + t) % t;
    int R = (t - c[i]) % t;
    long long a = ST[0];
    if (L < R){
      if (a % t < L || a % t >= R){
        long long m1 = get(a, t, L);
        long long m2 = get(a + 1, t, R);
        int p1 = lower_bound(ST, cnt, m1);
        int p2 = lower_bound(ST, cnt, m2);
        ST.range_update(p1, p2, m2);
      } else {
        long long m1 = get(a + 1, t, L);
        long long m2 = get(a, t, R);
        int p1 = lower_bound(ST, cnt, m1);
        int p2 = lower_bound(ST, cnt, m2);
        ST.range_update(p1, cnt, m2 + t);
        ST.range_update(0, p2, m2);
      }
    } else {
      if (R <= a % t && a % t < L){
        long long m1 = get(a, t, L);
        long long m2 = get(a + 1, t, R);
        int p1 = lower_bound(ST, cnt, m1);
        int p2 = lower_bound(ST, cnt, m2);
        ST.range_update(p1, p2, m2);
      } else {
        long long m1 = get(a + 1, t, L);
        long long m2 = get(a, t, R);
        int p1 = lower_bound(ST, cnt, m1);
        int p2 = lower_bound(ST, cnt, m2);
        ST.range_update(p1, cnt, m2 + t);
        ST.range_update(0, p2, m2);
      }
    }
  }
  x.push_back(t);
  long long ans = INF;
  for (int i = 0; i < cnt; i++){
    long long s = ST[i];
    if (s == x[i]){
      ans = min(ans, s - x[i]);
    } else {
      ans = min(ans, s - (x[i + 1] - 1));
    }
  }
  cout << ans + s[n - 1] << endl;
}