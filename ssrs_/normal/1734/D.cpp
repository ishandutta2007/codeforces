#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct sparse_table{
	vector<vector<T>> ST;
	sparse_table(vector<T> &A){
		int N = A.size();
		int LOG = 32 - __builtin_clz(N);
		ST = vector<vector<T>>(LOG, vector<T>(N));
		for (int i = 0; i < N; i++){
			ST[0][i] = A[i];
		}
		for (int i = 0; i < LOG - 1; i++){
			for (int j = 0; j < N - (1 << i); j++){
				ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
			}
		}
	}
	T range_min(int L, int R){
		int d = 31 - __builtin_clz(R - L);
		return min(ST[d][L], ST[d][R - (1 << d)]);
	}
};
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int n, k;
    cin >> n >> k;
    k--;
    vector<int> a(n);
    for (int j = 0; j < n; j++){
      cin >> a[j];
    }
    vector<int> L;
    for (int j = k - 1; j >= 0; j--){
      L.push_back(a[j]);
    }
    vector<int> R;
    for (int j = k + 1; j < n; j++){
      R.push_back(a[j]);
    }
    int N = L.size();
    int M = R.size();
    vector<long long> SL(N + 1);
    SL[0] = 0;
    for (int j = 0; j < N; j++){
      SL[j + 1] = SL[j] + L[j];
    }
    vector<long long> SR(M + 1);
    SR[0] = 0;
    for (int j = 0; j < M; j++){
      SR[j + 1] = SR[j] + R[j];
    }
    vector<int> pL = {0};
    for (int j = 1; j <= N; j++){
      if (SL[j] > SL[pL.back()]){
        pL.push_back(j);
      }
    }
    vector<int> pR = {0};
    for (int j = 1; j <= M; j++){
      if (SR[j] > SR[pR.back()]){
        pR.push_back(j);
      }
    }
    sparse_table<long long> ST1(SL), ST2(SR);
    int cntL = pL.size();
    int cntR = pR.size();
    long long sum = a[k];
    int p1 = 0, p2 = 0;
    bool ok = true;
    while (true){
      if (sum + ST1.range_min(pL[p1], N + 1) - SL[pL[p1]] >= 0){
        break;
      }
      if (sum + ST2.range_min(pR[p2], M + 1) - SR[pR[p2]] >= 0){
        break;
      }
      if (p1 == cntL - 1 && p2 == cntR - 1){
        ok = false;
        break;
      }
      bool okL = false;
      if (p1 < cntL - 1){
        if (sum + ST1.range_min(pL[p1], pL[p1 + 1]) - SL[pL[p1]] >= 0){
          okL = true;
        }
      }
      if (okL){
        sum += SL[pL[p1 + 1]] - SL[pL[p1]];
        p1++;
      } else {
        bool okR = false;
        if (p2 < cntR - 1){
          if (sum + ST2.range_min(pR[p2], pR[p2 + 1]) - SR[pR[p2]] >= 0){
            okR = true;
          }
        }
        if (okR){
          sum += SR[pR[p2 + 1]] - SR[pR[p2]];
          p2++;
        } else {
          ok = false;
          break;
        }
      }
    }
    if (ok){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}