#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;
array<int, 6> merge(array<int, 6> A, array<int, 6> B){
  array<int, 6> ans;
  ans[0] = A[0] + B[0];
  ans[1] = A[1] + B[1];
  ans[2] = A[2] + B[2];
  ans[3] = min(A[0] + B[3], A[3] + B[1]);
  ans[4] = min(A[1] + B[4], A[4] + B[2]);
  ans[5] = min({A[0] + B[5], A[3] + B[4], A[5] + B[2]});
  return ans;
}
struct segment_tree{
	int N;
	vector<array<int, 6>> ST;
	segment_tree(string S){
    int n = S.size();
		N = 1;
		while (N < n){
			N *= 2;
		}
		ST = vector<array<int, 6>>(N * 2 - 1, {0, 0, 0, INF, INF, INF});
		for (int i = 0; i < n; i++){
      if (S[i] == 'a'){
        ST[N - 1 + i] = {1, 0, 0, 1, 0, 1};
      }
      if (S[i] == 'b'){
        ST[N - 1 + i] = {0, 1, 0, 0, 1, 0};
      }
      if (S[i] == 'c'){
        ST[N - 1 + i] = {0, 0, 1, 0, 0, 0};
      }
      ST[N - 1 + i][S[i] - 'a'] = 1;
		}
		for (int i = N - 2; i >= 0; i--){
			ST[i] = merge(ST[i * 2 + 1], ST[i * 2 + 2]);
		}
	}
	void update(int k, char c){
		k += N - 1;
    if (c == 'a'){
      ST[k] = {1, 0, 0, 1, 0, 1};
    }
    if (c == 'b'){
      ST[k] = {0, 1, 0, 0, 1, 0};
    }
    if (c == 'c'){
      ST[k] = {0, 0, 1, 0, 0, 0};
    }
		while (k > 0){
			k = (k - 1) / 2;
			ST[k] = merge(ST[k * 2 + 1], ST[k * 2 + 2]);
		}
	}
	array<int, 6> all(){
		return ST[0];
	}
};
int main(){
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  segment_tree ST(s);
  for (int j = 0; j < q; j++){
    int i;
    char c;
    cin >> i >> c;
    i--;
    ST.update(i, c);
    array<int, 6> res = ST.all();
    int ans = min({res[0], res[1], res[2], res[3], res[4], res[5]});
    cout << ans << "\n";
  }
}