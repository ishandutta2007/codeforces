#include <bits/stdc++.h>
using namespace std;
struct unionfind{
	vector<int> p;
	unionfind(int N): p(vector<int>(N, -1)){
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
		}
	}
};
int main(){
  int m, n;
  cin >> m >> n;
  vector<int> a(m);
  for (int i = 0; i < m; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++){
    cin >> b[i];
  }
  vector<tuple<int, int, int>> E;
  for (int i = 0; i < m; i++){
    int s;
    cin >> s;
    for (int j = 0; j < s; j++){
      int A;
      cin >> A;
      A--;
      int cost = a[i] + b[A];
      E.push_back(make_tuple(cost, i, m + A));
    }
  }
  int V = n + m;
  unionfind UF(V);
  long long ans = 0;
  sort(E.rbegin(), E.rend());
  int cnt = E.size();
  for (int i = 0; i < cnt; i++){
    int cost = get<0>(E[i]);
    int v = get<1>(E[i]);
    int w = get<2>(E[i]);
    if (UF.same(v, w)){
      ans += cost;
    } else {
      UF.unite(v, w);
    }
  }
  cout << ans << endl;
}