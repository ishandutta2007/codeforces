#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
	unionfind(int N){
		p = vector<int>(N, -1);
	}
	int root(int x){
		if (p[x] < 0){
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
			if (p[x] < p[y]){
				swap(x, y);
			}
			p[y] += p[x];
			p[x] = y;
		}
	}
};
int main(){
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  unionfind UF1(n);
  for (int i = 0; i < m1; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    UF1.unite(u, v);
  }
  unionfind UF2(n);
  for (int i = 0; i < m2; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    UF2.unite(u, v);
  }
  vector<pair<int, int>> ans;
  while (true){
    int p = -1;
    bool ok = false;
    for (int i = 0; i < n; i++){
      if (!UF1.same(0, i)){
        p = i;
        if (!UF2.same(0, i)){
          ans.push_back(make_pair(0, i));
          UF1.unite(0, i);
          UF2.unite(0, i);
          ok = true;
          break;
        }
      }
    }
    if (p == -1){
      break;
    }
    if (!ok){
      bool ok2 = false;
      for (int i = 0; i < n; i++){
        if (!UF1.same(i, p) && !UF2.same(i, p)){
          ok2 = true;
          ans.push_back(make_pair(i, p));
          UF1.unite(i, p);
          UF2.unite(i, p);
          break;
        }
      }
      if (!ok2){
        break;
      }
    }
  }
  int h = ans.size();
  cout << h << endl;
  for (int i = 0; i < h; i++){
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
  }
}