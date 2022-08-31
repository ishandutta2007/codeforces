#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
struct monoid{
  int cnt, all, left0, left1, right0, right1, sum0, sum1;
  monoid(){
    cnt = 1;
    all = -INF;
    left0 = -INF;
    left1 = -INF;
    right0 = -INF;
    right1 = -INF;
    sum0 = -INF;
    sum1 = -INF;
  }
  monoid(int x){
    cnt = 1;
    all = x;
    left0 = 0;
    left1 = x;
    right0 = 0;
    right1 = x;
    sum0 = 0;
    sum1 = x;
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.cnt = L.cnt + R.cnt;
  ans.all = L.all + R.all;
  ans.left0 = L.left0;
  ans.left1 = L.left1;
  if (L.cnt % 2 == 0){
    ans.left0 = max(ans.left0, L.all + R.left0);
    ans.left1 = max(ans.left1, L.all + R.left1);
  } else {
    ans.left0 = max(ans.left0, L.all + R.left1);
    ans.left1 = max(ans.left1, L.all + R.left0);
  }
  ans.right0 = R.right0;
  ans.right1 = R.right1;
  if (R.cnt % 2 == 0){
    ans.right0 = max(ans.right0, L.right0 + R.all);
    ans.right1 = max(ans.right1, L.right1 + R.all);
  } else {
    ans.right0 = max(ans.right0, L.right1 + R.all);
    ans.right1 = max(ans.right1, L.right0 + R.all);
  }
  ans.sum0 = max({L.sum0, R.sum0, L.right0 + R.left0, L.right1 + R.left1});
  ans.sum1 = max({L.sum1, R.sum1, L.right0 + R.left1, L.right1 + R.left0});
  return ans;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(int n, function<T(T, T)> f, T E): f(f), E(E){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = x;
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = f(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T all(){
		return ST[0];
	}
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<int> ans(n, 0);
  for (int i = 0; i < 2; i++){
    vector<vector<int>> id(n);
    for (int j = 0; j < n; j++){
      id[a[j]].push_back(j);
    }
    vector<int> A(n, 0), B(n, 0);
    for (int j = 0; j < n; j += 2){
      A[j]--;
    }
    for (int j = 1; j < n; j += 2){
      B[j]--;
    }
    segment_tree<monoid> ST1(n, f, monoid());
    segment_tree<monoid> ST2(n, f, monoid());
    for (int j = 0; j < n; j++){
      ST1.update(j, monoid(A[j]));
      ST2.update(j, monoid(B[j]));
    }
    for (int j = 0; j < n; j++){
      for (int k : id[j]){
        A[k]++;
        ST1.update(k, monoid(A[k]));
        B[k]++;
        ST2.update(k, monoid(B[k]));
      }
      for (int k : id[j]){
        A[k] += INF;
        ST1.update(k, monoid(A[k]));
        B[k] += INF;
        ST2.update(k, monoid(B[k]));
        if (i == 0){
          ans[k] = max(ans[k], ST1.all().sum0 - 1 - INF);
          ans[k] = max(ans[k], ST1.all().sum1 - 1 - INF);
          ans[k] = max(ans[k], ST2.all().sum0 - 1 - INF);
          ans[k] = max(ans[k], ST2.all().sum1 - 1 - INF);
        } else {
          ans[k] = max(ans[k], ST1.all().sum0 - INF);
          ans[k] = max(ans[k], ST1.all().sum1 - 1 - INF);
          ans[k] = max(ans[k], ST2.all().sum0 - INF);
          ans[k] = max(ans[k], ST2.all().sum1 - 1 - INF);
        }
        A[k] -= INF;
        ST1.update(k, monoid(A[k]));
        B[k] -= INF;
        ST2.update(k, monoid(B[k]));
      }
    }
    for (int j = 0; j < n; j++){
      a[j] = n - 1 - a[j];
    }
  }
  for (int i = 0; i < n; i++){
    cout << ans[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << endl;
}