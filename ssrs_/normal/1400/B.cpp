#include <bits/stdc++.h>
using namespace std;
int INF = 10000000;
template <typename T>
struct segment_tree{
	int N;
	vector<T> ST;
	segment_tree(int n){
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
	}
	segment_tree(vector<T> a){
		int n = a.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<T>(N * 2 - 1, -INF);
		for (int i = 0; i < n; i++){
			ST[N - 1 + i] = a[i];
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	T query(int L, int R, int i, int l, int r){
		if (R <= l || r <= L){
			return -INF;
		} else if (L <= l && r <= R){
			return ST[i];
		} else {
			int m = (l + r) / 2;
			return max(query(L, R, i * 2 + 1, l, m), query(L, R, i * 2 + 2, m, r));
		}
	}
	T query(int L, int R){
		return query(L, R, 0, 0, N);
	}
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    long long p, f;
    cin >> p >> f;
    long long cs, cw;
    cin >> cs >> cw;
    long long s, w;
    cin >> s >> w;
    if (s > w){
      swap(s, w);
      swap(cs, cw);
    }
    long long ans = 0;
    for (int i = 0; i <= cs; i++){
      if (s * i <= p){
        long long cs2 = cs, cw2 = cw;
        cs2 -= i;
        long long tmp = (p - s * i) / w;
        tmp = min(cw, tmp);
        cw2 -= tmp;
        long long cntA = i + tmp;
        if (f <= cs2 * s){
          long long cntB = f / s;
          ans = max(ans, cntA + cntB);
        } else if (f <= cs2 * s + cw2 * w){
          long long cntB = cs2 + (f - cs2 * s) / w;
          ans = max(ans, cntA + cntB);
        } else {
          ans = max(ans, cs + cw);
        }
      }
    }
    cout << ans << endl;
  }
}