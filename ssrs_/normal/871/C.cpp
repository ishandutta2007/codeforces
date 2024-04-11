#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long modpow(long long a, long long b){
	long long ans = 1;
	while (b > 0){
		if (b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}
		a *= a;
		a %= MOD;
		b /= 2;
	}
	return ans;
}
int main(){
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; i++){
    cin >> x[i] >> y[i];
  }
  vector<int> x2 = x;
  sort(x2.begin(), x2.end());
  x2.erase(unique(x2.begin(), x2.end()), x2.end());
  int cntx = x2.size();
  map<int, int> mpx;
  for (int i = 0; i < cntx; i++){
    mpx[x2[i]] = i;
  }
  for (int i = 0; i < n; i++){
    x[i] = mpx[x[i]];
  }
  vector<int> y2 = y;
  sort(y2.begin(), y2.end());
  y2.erase(unique(y2.begin(), y2.end()), y2.end());
  int cnty = y2.size();
  map<int, int> mpy;
  for (int i = 0; i < cnty; i++){
    mpy[y2[i]] = i;
  }
  for (int i = 0; i < n; i++){
    y[i] = mpy[y[i]];
  }
  vector<vector<int>> E(cntx + cnty);
  for (int i = 0; i < n; i++){
    E[x[i]].push_back(cntx + y[i]);
    E[cntx + y[i]].push_back(x[i]);
  }
  int V = cntx + cnty;
  vector<int> c(V, -1);
  int cnt = 0;
  for (int i = 0; i < V; i++){
    if (c[i] == -1){
      c[i] = cnt;
      queue<int> Q;
      Q.push(i);
      while (!Q.empty()){
        int v = Q.front();
        Q.pop();
        for (int w : E[v]){
          if (c[w] == -1){
            c[w] = cnt;
            Q.push(w);
          }
        }
      }
      cnt++;
    }
  }
  vector<int> cnte(cnt, 0), cntv(cnt, 0);
  for (int i = 0; i < V; i++){
    cntv[c[i]]++;
    for (int j : E[i]){
      if (j > i){
        cnte[c[i]]++;
      }
    }
  }
  long long ans = 1;
  for (int i = 0; i < cnt; i++){
    long long tmp = modpow(2, cntv[i]);
    if (cnte[i] < cntv[i]){
      tmp--;
    }
    ans *= tmp;
    ans %= MOD;
  }
  cout << ans << endl;
}