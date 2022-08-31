#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> &B, int &M, vector<int> &S, int &X, int &Y, int C, int CS, int p){
  int N = B.size();
  if (p == N){
    if (__builtin_popcount(C) == M){
      if (S[CS] == -1){
        S[CS] = C;
      } else {
        X = C;
        Y = S[CS];
      }
    }
  } else {
    dfs(B, M, S, X, Y, C, CS, p + 1);
    if (X != -1){
      return;
    }
    if (__builtin_popcount(C) < M){
      dfs(B, M, S, X, Y, C | (1 << p), CS + B[p], p + 1);
    }
  }
}
int main(){
  int N;
  cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; i++){
    cin >> B[i];
  }
  if (N == 2){
    if (B[0] == B[1]){
      cout << "YES" << endl;
      cout << B[0] << ' ' << 0 << endl;
    } else {
      cout << "NO" << endl;
    }
  } else if (N == 3){
    if (B[0] == B[1]){
      cout << "YES" << endl;
      cout << 0 << ' ' << B[0] << ' ' << B[2] << endl;
    } else if (B[1] == B[2]){
      cout << "YES" << endl;
      cout << 0 << ' ' << B[1] << ' ' << B[0] << endl;
    } else if (B[2] == B[0]){
      cout << "YES" << endl;
      cout << 0 << ' ' << B[2] << ' ' << B[1] << endl;
    } else if ((B[0] + B[1] + B[2]) % 2 == 0){
      int S = (B[0] + B[1] + B[2]) / 2;
      cout << "YES" << endl;
      cout << S - B[0] << ' ' << S - B[1] << ' ' << S - B[2] << endl;
    } else {
      cout << "NO" << endl;
    }
  } else {
    int p = -1;
    for (int i = 0; i < N; i++){
      if (B[i] % 2 == 0){
        p = i;
      }
    }
    if (p != -1){
      vector<int> X;
      for (int i = 0; i < N; i++){
        if (i != p){
          X.push_back(i);
          if (X.size() == 3){
            break;
          }
        }
      }
      int a = -1, b = -1;
      for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
          if (B[X[i]] % 2 == B[X[j]] % 2){
            a = X[i];
            b = X[j];
          }
        }
      }
      int S = (B[p] + B[a] + B[b]) / 2;
      vector<int> A;
      A.push_back(S - B[p]);
      A.push_back(S - B[a]);
      A.push_back(S - B[b]);
      for (int i = 0; i < N; i++){
        if (i != p && i != a && i != b){
          A.push_back(B[i] - (S - B[p]));
        }
      }
      cout << "YES" << endl;
      for (int i = 0; i < N; i++){
        cout << A[i];
        if (i < N - 1){
          cout << ' ';
        }
      }
      cout << endl;
    } else {
      vector<int> B3  = B;
      if (B3.size() >= 28){
        B3.resize(28);
      }
      int X = -1, Y = -1;
      int M = min(N / 2, 13);
      vector<int> S(M * 1000000 + 1, -1);
      dfs(B3, M, S, X, Y, 0, 0, 0);
      if (X == -1 && Y == -1){
        cout << "NO" << endl;
      } else {
        int sx = 0, sy = 0;
        for (int i = 0; i < min(N, 28); i++){
          if ((X >> i & 1) == 1){
            sx += B[i];
          }
          if ((Y >> i & 1) == 1){
            sy += B[i];
          }
        }
        vector<int> X2, Y2;
        for (int i = 0; i < min(N, 28); i++){
          if ((X >> i & 1) == 1 && (Y >> i & 1) == 0){
            X2.push_back(i);
          }
          if ((Y >> i & 1) == 1 && (X >> i & 1) == 0){
            Y2.push_back(i);
          }
        }
        int cnt = X2.size();
        vector<int> B2;
        for (int i = 0; i < cnt; i++){
          B2.push_back(B[X2[i]]);
          B2.push_back(B[Y2[i]]);
        }
        vector<int> A;
        A.push_back(0);
        for (int i = 0; i < cnt * 2 - 1; i++){
          A.push_back(B2[i] - A.back());
        }
        vector<bool> used(N, false);
        for (int i = 0; i < cnt; i++){
          used[X2[i]] = true;
          used[Y2[i]] = true;
        }
        for (int i = 0; i < N; i++){
          if (!used[i]){
            A.push_back(B[i]);
          }
        }
        cout << "YES" << endl;
        for (int i = 0; i < N; i++){
          cout << A[i];
          if (i < N - 1){
            cout << ' ';
          }
        }
        cout << endl;
      }
    }
  }
}