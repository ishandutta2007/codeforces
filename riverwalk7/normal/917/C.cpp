#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 70
#define M 27
#define K 8

int m, c[K + 1], maskMap[(1 << K)], invMaskMap[N];
ll A[M][N][N], B[N][N], T[N][N], C[N], D[N];
const ll inf = 1E18;
map<int,int> w;

void Reset(ll A[N]){
  for(int i = 0; i < N; ++i)
    A[i] = inf;
}

void Reset(ll A[N][N]){
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      A[i][j] = inf;
}

void CopyMat(ll S[N][N], ll D[N][N]){
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      D[i][j] = S[i][j];
}

void MatMul(ll A[N][N], ll B[N][N], ll C[N][N]){
  Reset(T);

  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      for(int k = 0; k < N; ++k)
        T[i][j] = min(T[i][j], A[i][k] + B[k][j]);

  CopyMat(T, C);
}

void PreProcess(int n, int k, int b){
  for(int mask = 0, mask_map = 0; mask < (1 << k); ++mask){
    if(__builtin_popcount(mask) == b){
      maskMap[mask] = mask_map++;
      invMaskMap[maskMap[mask]] = mask;
      m = mask_map;
    }
  }

  Reset(A[0]);
  for(int x = 0; x < m; ++x){
    int i = invMaskMap[x], ci = x;
    if((i & 1) == 0){
      int cj = maskMap[(i >> 1)];
      A[0][ci][cj] = 0;
    }
    else{
      for(int l = 1; l <= k; ++l){
        if((i & (1 << l)) > 0)
          continue;
        int j = ((i | (1 << l)) >> 1), cj = maskMap[j];
        A[0][ci][cj] = c[l];
      }
    }
  }

  for(int l = 1; (1 << l) <= n; ++l)
    MatMul(A[l - 1], A[l - 1], A[l]);

  Reset(C);
  C[maskMap[(1 << b) - 1]] = 0;
}

void MultiplyPowerA(int n){
  for(int k = M - 1; k > -1 && n > 0; --k){
    if((1 << k) <= n){
      MatMul(B, A[k], B);
      n -= (1 << k);
    }
  }
}

void FillC(){
  Reset(C);
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      C[i] = min(C[i], B[j][i]);
}

void FillB(){
  Reset(B);
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      B[i][j] = C[j];
}

void MoveOneStep(int k, int p){
  Reset(D);

  for(int x = 0; x < m; ++x){
    int i = invMaskMap[x], ci = x;
    if((i & 1) == 0){
      int j = (i >> 1), cj = maskMap[j];
      D[cj] = min(D[cj], C[ci]);
      // cout << i << ' ' << j << ' ' << ci << ' ' << cj << ' ' << D[cj] << '\n';
    }
    else{
      for(int l = 1; l <= k; ++l){
        if((i & (1 << l)) > 0)
          continue;
        int j = ((i | (1 << l)) >> 1), cj = maskMap[j];
        D[cj] = min(D[cj], C[ci] + c[l] + w[p + l]);
        // cout << i << ' ' << j << ' ' << ci << ' ' << cj << ' ' << D[cj] << '\n';
      }
    }
  }

  for(int i = 0; i < N; ++i)
    C[i] = D[i];
}

int main(){
  int b, k, n, q;
  vector<int> v;

  cin >> b >> k >> n >> q;

  for(int i = 1; i <= k; ++i)
    cin >> c[i];

  while(q--){
    int p, wp;
    cin >> p >> wp;
    w[p] = wp;
    v.PB(p);
  }


  n -= (b - 1);
  PreProcess(n, k, b);

  v.PB(n);
  sort(v.begin(), v.end());

  int i = 1;
  for(auto j : v){
    int l = max(0, min(j - k, n) - i);

    if(l){
      FillB();
      MultiplyPowerA(l);
      FillC();
      i += l;
    }

    for( ; i < n && i < j; ++i)
      MoveOneStep(k, i);

    if(i == n)
      break;
  }

  cout << C[maskMap[(1 << b) - 1]] << '\n';

  return 0;
}