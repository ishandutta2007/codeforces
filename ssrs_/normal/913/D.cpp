#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct binary_indexed_tree{
	int N;
	vector<T> BIT;
	binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
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
	T sum(int L, int R){
		return sum(R) - sum(L);
	}
};
int main(){
  int n, T;
  cin >> n >> T;
  vector<int> a(n), t(n);
  for (int i = 0; i < n; i++){
    cin >> a[i] >> t[i];
  }
  vector<vector<int>> id(n);
  for (int i = 0; i < n; i++){
    id[a[i] - 1].push_back(i);
  }
  vector<pair<int, int>> P(n);
  for (int i = 0; i < n; i++){
    P[i] = make_pair(t[i], i);
  }
  sort(P.begin(), P.end());
  vector<int> pos(n);
  for (int i = 0; i < n; i++){
    pos[P[i].second] = i;
  }
  binary_indexed_tree<int> cnt0(n), cnt1(n);
  binary_indexed_tree<long long> sum0(n), sum1(n);
  for (int i = 0; i < n; i++){
    cnt1.add(i, 1);
    sum1.add(i, P[i].first);
  }
  int mx_s = 0;
  int mx_k = 0;
  int mx_x = 0;
  int mx_y = 0;
  for (int i = 1; i <= n; i++){
    if (sum0.sum(i) + sum1.sum(i) <= T){
      int tv = i, fv = -1;
      int y = i;
      while (tv - fv > 1){
        int mid = (tv + fv) / 2;
        int c0 = cnt0.sum(mid);
        int tv2 = n, fv2 = 0;
        while (tv2 - fv2 > 1){
          int mid2 = (tv2 + fv2) / 2;
          if (c0 + cnt1.sum(mid2) >= i){
            tv2 = mid2;
          } else {
            fv2 = mid2;
          }
        }
        if (sum0.sum(c0) + sum1.sum(tv2) <= T){
          tv = mid;
          y = tv2;
        } else {
          fv = mid;
        }
      }
      int s = cnt1.sum(y);
      if (s > mx_s){
        mx_s = s;
        mx_k = i;
        mx_x = tv;
        mx_y = y;
      }
    }
    for (int j : id[i - 1]){
      cnt1.add(pos[j], -1);
      sum1.add(pos[j], -t[j]);
      cnt0.add(pos[j], 1);
      sum0.add(pos[j], t[j]);
    }
  }
  vector<int> p;
  for (int i = 0; i < n; i++){
    if (a[i] < mx_k && pos[i] < mx_x){
      p.push_back(i);
    }
    if (a[i] >= mx_k && pos[i] < mx_y){
      p.push_back(i);
    }
  }
  cout << mx_s << endl;
  cout << mx_k << endl;
  for (int i = 0; i < mx_k; i++){
    cout << p[i] + 1;
    if (i < mx_k - 1){
      cout << ' ';
    }
  }
  cout << endl;
}