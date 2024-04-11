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
	int unite(int x, int y){
		x = root(x);
		y = root(y);
    if (p[x] < p[y]){
      swap(x, y);
    }
    p[y] += p[x];
    p[x] = y;
    return -p[y];
	}
};
int main(){
  int n, d;
  cin >> n >> d;
  vector<int> x(d), y(d);
  for (int i = 0; i < d; i++){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  unionfind UF(n);
  int c = 1;
  for (int i = 0; i < d; i++){
    if (!UF.same(x[i], y[i])){
      UF.unite(x[i], y[i]);
    } else {
      c++;
    }
    vector<int> S;
    for (int j = 0; j < n; j++){
      if (UF.root(j) == j){
        S.push_back(-UF.p[j]);
      }
    }
    sort(S.begin(), S.end(), greater<int>());
    c = min(c, (int) S.size());
    int ans = 0;
    for (int j = 0; j < c; j++){
      ans += S[j];
    }
    ans--;
    cout << ans << endl;
  }
}