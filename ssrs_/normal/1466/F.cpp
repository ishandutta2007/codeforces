#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
struct unionfind{
	vector<int> p;
	vector<bool> ok;
	unionfind(int N): p(N, -1), ok(N, false){
	};
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
			p[x] = y;
			if (ok[x]){
				ok[y] = true;
			}
		}
	}
	bool isok(int x){
		return ok[root(x)];
	}
	void update(int x){
		ok[root(x)] = true;
	}
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> k(n);
  vector<vector<int>> x(n);
  for (int i = 0; i < n; i++){
    cin >> k[i];
    x[i] = vector<int>(k[i]);
    for (int j = 0; j < k[i]; j++){
      cin >> x[i][j];
      x[i][j]--;
    }
  }
  unionfind UF(m);
  vector<int> S;
  long long ans = 1;
  for (int i = 0; i < n; i++){
    if (k[i] == 2){
      int u = x[i][0];
      int v = x[i][1];
      if (!UF.same(u, v) && !(UF.isok(u) && UF.isok(v))){
        UF.unite(u, v);
        S.push_back(i);
        ans *= 2;
        ans %= MOD;
      }
    } else {
      int v = x[i][0];
      if (!UF.isok(v)){
        UF.update(v);
        S.push_back(i);
        ans *= 2;
        ans %= MOD;
      }
    }
  }
  int C = S.size();
  cout << ans << ' ' << C << endl;
  for (int i = 0; i < C; i++){
    cout << S[i] + 1;
    if (i < C - 1){
      cout << ' ';
    }
  }
  cout << endl;
}