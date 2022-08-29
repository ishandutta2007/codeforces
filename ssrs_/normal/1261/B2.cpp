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
};
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  map<int, vector<int>> mp;
  for (int i = 0; i < n; i++){
    mp[a[i]].push_back(i);
  }
  vector<int> id;
  for (auto itr = mp.rbegin(); itr != mp.rend(); itr++){
    for (auto x : (*itr).second){
      id.push_back(x);
    }
  }
  int m;
  cin >> m;
  vector<vector<pair<int, int>>> query(n);
  for (int i = 0; i < m; i++){
    int k, pos;
    cin >> k >> pos;
    k--;
    pos--;
    query[k].push_back(make_pair(pos, i));
  }
  binary_indexed_tree<int> BIT(n);
  vector<int> ans(m);
  for (int i = 0; i < n; i++){
    BIT.add(id[i], 1);
    int cnt = query[i].size();
    for (int j = 0; j < cnt; j++){
      int pos = query[i][j].first;
      int id = query[i][j].second;
      int tv = -1;
      int fv = n + 1;
      while (fv - tv > 1){
        int mid = (tv + fv) / 2;
        if (BIT.sum(mid) <= pos){
          tv = mid;
        } else {
          fv = mid;
        }
      }
      ans[id] = a[tv];
    }
  }
  for (int i = 0; i < m; i++){
    cout << ans[i] << endl;
  }
}