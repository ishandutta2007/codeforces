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
	T sum(int L, int R){
		return sum(R) - sum(L);
	}
	T all(){
		return BIT[0];
	}
};
int main(){
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> H(n);
  for (int i = 0; i < n; i++){
    int y, lx, rx;
    cin >> y >> lx >> rx;
    H[i] = make_tuple(y, lx, rx);
  }
  vector<tuple<int, int, int>> V(m);
  for (int i = 0; i < m; i++){
    int x, ly, ry;
    cin >> x >> ly >> ry;
    V[i] = make_tuple(x, ly, ry);
  }
  vector<pair<int, int>> H2(1000000, make_pair(-1, -1));
  for (int i = 0; i < n; i++){
    int y = get<0>(H[i]);
    int lx = get<1>(H[i]);
    int rx = get<2>(H[i]);
    H2[y] = make_pair(lx, rx);
  }
  long long ans = 1;
  for (int i = 0; i < n; i++){
    int lx = get<1>(H[i]);
    int rx = get<2>(H[i]);
    if (lx == 0 && rx == 1000000){
      ans++;
    }
  }
  for (int i = 0; i < m; i++){
    int ly = get<1>(V[i]);
    int ry = get<2>(V[i]);
    if (ly == 0 && ry == 1000000){
      ans++;
    }
  }
  vector<vector<int>> s(1000000), t(1000000);
  for (int i = 0; i < m; i++){
    int x = get<0>(V[i]);
    int ly = get<1>(V[i]);
    int ry = get<2>(V[i]);
    s[ly].push_back(x);
    t[ry].push_back(x);
  }
  binary_indexed_tree<int> BIT(1000000);
  for (int i = 0; i < 1000000; i++){
    for (int x : s[i]){
      BIT.add(x, 1);
    }
    if (H2[i] != make_pair(-1, -1)){
      int L = H2[i].first;
      int R = H2[i].second;
      ans += BIT.sum(L, R + 1);
    }
    for (int x : t[i]){
      BIT.add(x, -1);
    }
  }
  cout << ans << endl;
}