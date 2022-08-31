#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct RAQ{
	int N;
	vector<T> ST;
	RAQ(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	RAQ(vector<T> A){
		int n = A.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = A[i];
		}
	}
	T operator [](int k){
		k += N - 1;
		T ans = ST[k];
		while (k > 0){
			k = (k - 1) / 2;
			ans += ST[k];
		}
		return ans;
	}
	void range_add(int L, int R, T x, int i, int l, int r){
		if (R <= l || r <= L){
			return;
		} else if (L <= l && r <= R){
			ST[i] += x;
			return;
		} else {
			int m = (l + r) / 2;
			range_add(L, R, x, i * 2 + 1, l, m);
			range_add(L, R, x, i * 2 + 2, m, r);
			return;
		}
	}
	void range_add(int L, int R, T x){
		range_add(L, R, x, 0, 0, N);
	}
	void point_add(int i, T x){
	  range_add(i, i + 1, x);
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> h(n);
  for (int i = 0; i < n; i++){
    cin >> h[i];
  }
  RAQ<long long> S(n);
  stack<int> st;
  S.point_add(0, h[0]);
  for (int i = 1; i < n; i++){
    S.point_add(i, h[i]);
    if (S[i] == S[i - 1]){
      st.push(i - 1);
    }
    while (1){
      long long d = S[i] - S[i - 1];
      if (d < 2){
        break;
      }
      if (st.empty()){
        long long r = (d - 1) / (i + 1);
        if (r > 0){
          S.range_add(0, i, r);
          S.point_add(i, - r * i);
        } else {
          S.range_add(0, d - 1, 1);
          S.point_add(i, 1 - d);
          st.push(d - 2);
        }
      } else {
        int f = st.top();
        st.pop();
        if (f + d > i){
          S.range_add(f + 1, i, 1);
          S.point_add(i, f + 1 - i);
        } else {
          S.range_add(f + 1, f + d, 1);
          S.point_add(i, 1 - d);
          st.push(f + d - 1);
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << S[i] << ' ';
  }
  cout << endl;
}