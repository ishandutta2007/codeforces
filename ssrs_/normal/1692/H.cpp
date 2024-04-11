#include <bits/stdc++.h>
using namespace std;

struct monoid{
  long long sum, left, right, all;
  monoid(): sum(0), left(0), right(0), all(0){
  }
  monoid(int x){
    sum = x;
    left = max(x, 0);
    right = max(x, 0);
    all = max(x, 0);
  }
};
monoid f(monoid L, monoid R){
  monoid ans;
  ans.sum = L.sum + R.sum;
  ans.left = max(L.left, L.sum + R.left);
  ans.right = max(R.right, L.right + R.sum);
  ans.all = max({L.all, R.all, L.right + R.left});
  return ans;
}
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	function<T(T, T)> f;
	T E;
	segment_tree(vector<T> A, function<T(T, T)> f, T E): f(f), E(E){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, E);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = f(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
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
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> x(n);
    for (int j = 0; j < n; j++){
      cin >> x[j];
    }
    map<int, vector<int>> mp;
    for (int j = 0; j < n; j++){
      mp[x[j]].push_back(j);
    }
    segment_tree<monoid> ST(vector<monoid>(n, monoid(-1)), f, monoid());
    int mx = -1, a = -1;
    for (auto P : mp){
      for (int p : P.second){
        ST.update(p, monoid(1));
      }
      int r = ST.all().all;
      if (r > mx){
        mx = r;
        a = P.first;
      }
      for (int p : P.second){
        ST.update(p, monoid(-1));
      }
    }
    vector<int> S(n + 1);
    S[0] = 0;
    for (int j = 0; j < n; j++){
      S[j + 1] = S[j];
      if (x[j] == a){
        S[j + 1]++;
      } else {
        S[j + 1]--;
      }
    }
    int mn = 0, mnp = 0;
    int mx2 = -1;
    int l, r;
    for (int j = 1; j <= n; j++){
      if (S[j] - mn > mx2){
        mx2 = S[j] - mn;
        l = mnp;
        r = j;
      }
      if (S[j] < mn){
        mn = S[j];
        mnp = j;
      }
    }
    cout << a << ' ' << l + 1 << ' ' << r << endl;
  }
}