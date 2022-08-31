#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct dual_segment_tree{
	int N;
	vector<T> ST;
	dual_segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, 0);
	}
	dual_segment_tree(vector<T> A){
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
	void add(int p, T x){
		range_add(p, p + 1, x, 0, 0, N);
	}
	void all_add(T x){
		ST[0] += x;
	}
};
int main(){
  int n, k;
  cin >> n >> k;
  vector<int> l(n);
  for (int i = 0; i < n; i++){
    cin >> l[i];
  }
  long long sum = 1;
  for (int i = 0; i < n; i++){
    sum += l[i] - 2;
  }
  if (sum < k){
    cout << -1 << endl;
  } else {
    sort(l.begin(), l.end(), greater<int>());
    int tv = 400000;
    int fv = 0;
    while (tv - fv > 1){
      int mid = (tv + fv) / 2;
      long long csum = 1;
      dual_segment_tree<int> ST(400000);
      ST.add(0, 1);
      int p = 0;
      int p2 = 0;
      while (1){
        while (ST[p] == 0){
          p++;
        }
        if (p + 2 > mid){
          break;
        }
        ST.add(p, -1);
        ST.range_add(p + 2, p + 2 + (l[p2] - 1) / 2, 2);
        if (l[p2] % 2 == 0){
          ST.add(p + 1 + l[p2] / 2, 1);
        }
        csum += l[p2] - 2;
        p2++;
        if (p2 == n){
          break;
        }
      }
      long long cnt = 0;
      for (int i = 0; i <= mid; i++){
        cnt += ST[i];
      }
      if (cnt >= k){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    cout << tv << endl;
  }
}