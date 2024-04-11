#include <bits/stdc++.h>
using namespace std;
int INF = 1100000000;
struct unionfind{
	vector<int> p, sz;
	unionfind(int N){
	  p = vector<int>(N, -1);
	  sz = vector<int>(N, 1);
	}
	int root(int x){
		if (p[x] == -1){
			return x;
		} else {
			p[x] = root(p[x]);
			return p[x];
		}
	}
	bool same(int x, int y){
		return root(x) == root(y);
	}
	void unite(int x, int y){
		x = root(x);
		y = root(y);
		if (x != y){
		  if (sz[x] > sz[y]){
		    p[y] = x;
		    sz[x] += sz[y];
		  } else {
		    p[x] = y;
		    sz[y] += sz[x];
		  }
		}
	}
};
int main(){
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> E(m);
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    E[i] = make_tuple(w, u, v, i);
  }
  sort(E.rbegin(), E.rend());
  for (int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    unionfind UF(n * 2);
    int ans = INF;
    for (int j = 0; j < m; j++){
      int w = get<0>(E[j]);
      int u = get<1>(E[j]);
      int v = get<2>(E[j]);
      int id = get<3>(E[j]);
      if (l <= id && id <= r){
        UF.unite(u * 2, v * 2 + 1);
        UF.unite(u * 2 + 1, v * 2);
        if (UF.same(u * 2, u * 2 + 1) || UF.same(v * 2, v * 2 + 1)){
          ans = w;
          break;
        }
      }
    }
    if (ans == INF){
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }
}