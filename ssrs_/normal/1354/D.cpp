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
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  binary_indexed_tree<int> bit(1000000);
  for (int i = 0; i < n; i++){
    int a;
    cin >> a;
    bit.add(a - 1, 1);
  }
  for (int i = 0; i < q; i++){
    int k;
    cin >> k;
    if (k > 0){
      bit.add(k - 1, 1);
    } else {
      k = -k;
      int tv = 1000001;
      int fv = -1;
      while (tv - fv > 1){
        int mv = (tv + fv) / 2;
        int sum = bit.sum(mv);
        if (sum >= k){
          tv = mv;
        } else {
          fv = mv;
        }
      }
      bit.add(fv, -1);
    }
  }
  int ans = 0;
  for (int i = 0; i < 1000000; i++){
    if (bit.query(i, i + 1) != 0){
      ans = i + 1;
      break;
    }
  }
  cout << ans << endl;
}