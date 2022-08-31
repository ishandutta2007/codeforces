#include <bits/stdc++.h>
using namespace std;
const long long INF = 1100000000000000000;
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
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
    a[i]--;
  }
  vector<pair<int, int>> cnt(m);
  for (int i = 0; i < m; i++){
    cnt[i] = make_pair(0, i);
  }
  for (int i = 0; i < n; i++){
    cnt[a[i]].first++;
  }
  sort(cnt.begin(), cnt.end());
  vector<int> s(m + 1);
  s[0] = 0;
  for (int i = 0; i < m; i++){
    s[i + 1] = s[i] + cnt[i].first;
  }
  vector<long long> S(m + 1);
  S[0] = 0;
  S[m] = INF;
  if (m > 1){
    S[1] = cnt[1].first - cnt[0].first;
    for (int i = 1; i < m - 1; i++){
      S[i + 1] = S[i] + (long long) (cnt[i + 1].first - cnt[i].first) * (i + 1);
    }
  }
  vector<pair<long long, int>> query(q);
  for (int i = 0; i < q; i++){
    long long k;
    cin >> k;
    query[i] = make_pair(k, i);
  }
  sort(query.begin(), query.end());
  binary_indexed_tree<int> BIT(m);
  vector<int> ans(q);
  int p = 0;
  for (int i = 0; i < q; i++){
    long long add = query[i].first - n;
    while (S[p] < add){
      BIT.add(cnt[p].second, 1);
      p++;
    }
    long long R = add - S[p - 1] - 1;
    long long r = R % p;
    int tv = 0;
    int fv = m + 1;
    while (fv - tv > 1){
      int mid = (tv + fv) / 2;
      if (BIT.sum(mid) <= r){
        tv = mid;
      } else {
        fv = mid;
      }
    }
    int id = query[i].second;
    ans[id] = tv;
  }
  for (int i = 0; i < q; i++){
    cout << ans[i] + 1 << "\n";
  }
}