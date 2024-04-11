#include <bits/stdc++.h>
using namespace std;
const int maxA = 200;
//point decrement all max query
vector<int> segtree(vector<int> &A){
	int N = 1;
	while (N < A.size()){
		N = N * 2;
	}
	vector<int> ST(N * 2 - 1);
	for (int i = 0; i < A.size(); i++){
		ST[i + N - 1] = A[i];
	}
	for (int i = A.size() + N - 1; i < N * 2 - 1; i++){
		ST[i] = 0;
	}
	for (int i = N - 2; i >= 0; i--){
		ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
	}
	return ST;
}
void segtree_update(vector<int> &ST, int i){
	int N = (ST.size() + 1) / 2;
	i = i + N - 1;
	ST[i]--;
	while (i > 0){
		i = (i - 1) / 2;
		ST[i] = max(ST[i * 2 + 1], ST[i * 2 + 2]);
	}
	return;
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
      a[j]--;
    }
    vector<vector<int>> S(n + 1, vector<int>(maxA, 0));
    for (int j = 0; j < n; j++){
      for (int k = 0; k < maxA; k++){
        S[j + 1][k] = S[j][k];
      }
      S[j + 1][a[j]]++;
    }
    int m = 0;
    for (int j = 0; j < maxA; j++){
      //O
      int L = -1;
      int R = n;
      int c = S[n][j] / 2;
      vector<int> ST = segtree(S[n]);
      int X = ST.size();
      for (int k = 0; k < c; k++){
        L++;
        R--;
        segtree_update(ST, j);
        segtree_update(ST, j);
        while (a[L] != j){
          segtree_update(ST, a[L]);
          L++;
        }
        while (a[R] != j){
          segtree_update(ST, a[R]);
          R--;
        }
        m = max(m, k * 2 + ST[0] + 2);
      }
      m = max(m, S[n][j]);
    }
    cout << m << endl;
  }
}