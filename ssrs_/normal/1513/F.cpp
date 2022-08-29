#include <bits/stdc++.h>
using namespace std;
const long long INF = 1000000000000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, INF);
	}
	void update(int k, T x){
		k += N - 1;
		ST[k] = min(ST[k], x);
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = min(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	T range_min(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return min(range_min(L, R, i * 2 + 1, l, m), range_min(L, R, i * 2 + 2, m, r));
		}
	}
	T range_min(int L, int R){
		return range_min(L, R, 0, 0, N);
	}
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<int> x;
  for (int i = 0; i < n; i++){
    x.push_back(a[i]);
    x.push_back(b[i]);
  }
  sort(x.begin(), x.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  int cnt = x.size();
  vector<int> a2(n), b2(n);
  for (int i = 0; i < n; i++){
    a2[i] = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
    b2[i] = lower_bound(x.begin(), x.end(), b[i]) - x.begin();
  }
  vector<vector<int>> add(cnt + 1), query(cnt + 1);
  for (int i = 0; i < n; i++){
    add[a2[i]].push_back(i);
    query[b2[i]].push_back(i);
  }
  long long mn = 0;
  segment_tree<long long> ST1(cnt), ST2(cnt);
  for (int i = 0; i <= cnt; i++){
    for (int j : add[i]){
      ST1.update(b2[j], -a[j] - b[j] - abs(a[j] - b[j]));
      ST2.update(b2[j], -a[j] + b[j] - abs(a[j] - b[j]));
    }
    for (int j : query[i]){
      mn = min(mn, ST1.range_min(0, a2[j] + 1) + a[j] + b[j] - abs(a[j] - b[j]));
      mn = min(mn, ST2.range_min(a2[j], cnt) - a[j] + b[j] - abs(a[j] - b[j]));
    }
  }
  segment_tree<long long> ST3(cnt), ST4(cnt);
  for (int i = cnt; i >= 0; i--){
    for (int j : add[i]){
      ST3.update(b2[j], a[j] - b[j] - abs(a[j] - b[j]));
      ST4.update(b2[j], a[j] + b[j] - abs(a[j] - b[j]));
    }
    for (int j : query[i]){
      mn = min(mn, ST3.range_min(0, a2[j] + 1) + a[j] - b[j] - abs(a[j] - b[j]));
      mn = min(mn, ST4.range_min(a2[j], cnt) - a[j] - b[j] - abs(a[j] - b[j]));
    }
  }
  long long sum = 0;
  for (int i = 0; i < n; i++){
    sum += abs(a[i] - b[i]);
  }
  cout << sum + mn << endl;
}