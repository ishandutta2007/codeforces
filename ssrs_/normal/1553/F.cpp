#include <bits/stdc++.h>
using namespace std;
const int MAX = 300001;
vector<pair<int, pair<int, int>>> quotient_ranges(int N){
	vector<pair<int, pair<int, int>>> ans;
	for (int i = 1; i * i <= N; i++){
		ans.push_back(make_pair(N / i, make_pair(i, i)));
	}
	for (int i = N / ((int) sqrt(N) + 1); i >= 1; i--){
		ans.push_back(make_pair(i, make_pair(N / (i + 1) + 1, N / i)));
	}
	return ans;
}
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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> c(MAX, 0);
  binary_indexed_tree<long long> BIT1(MAX), BIT2(MAX);
  BIT1.add(a[0], 1);
  BIT2.add(a[0], a[0]);
  c[a[0]] = 1;
  vector<long long> p(n);
  p[0] = 0;
  for (int i = 1; i < n; i++){
    p[i] = p[i - 1];
    p[i] += BIT2.sum(0, a[i]);
    vector<pair<int, pair<int, int>>> Q = quotient_ranges(a[i]);
    int cnt = Q.size();
    for (int j = 0; j < cnt; j++){
      int L = Q[j].second.first;
      int R = Q[j].second.second;
      if (L == R){
        if (c[L] == 1){
          p[i] += a[i] % L;
        }
      } else {
        p[i] += BIT1.sum(L, R + 1) * a[i] - BIT2.sum(L, R + 1) * Q[j].first;
      }
    }
    p[i] += BIT1.sum(a[i], MAX) * a[i];
    for (int j = a[i]; j < MAX; j += a[i]){
      int L = j, R = min(j + a[i], MAX);
      p[i] += BIT2.sum(L, R) - BIT1.sum(L, R) * j;
    }
    BIT1.add(a[i], 1);
    BIT2.add(a[i], a[i]);
    c[a[i]] = 1;
  }
  for (int i = 0; i < n; i++){
    cout << p[i];
    if (i < n - 1){
      cout << ' ';
    }
  }
  cout << "\n";
}