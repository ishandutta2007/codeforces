#include <bits/stdc++.h>
using namespace std;
void solve(){
  int N, K;
  cin >> N;
  K = 5;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  int zero = 0;
  for (int i = 0; i < N; i++){
    if (A[i] == 0){
      zero++;
    }
  }
  if (zero > N - K){
    cout << 0 << endl;
  } else {
    vector<pair<long long, bool>> B;
    for (int i = 0; i < N; i++){
      if (A[i] > 0){
        B.push_back(make_pair(A[i], false));
      }
      if (A[i] < 0){
        B.push_back(make_pair(-A[i], true));
      }
    }
    N -= zero;
    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    long long prod1 = 1;
    int cnt = 0;
    for (int i = 0; i < K; i++){
      prod1 *= B[i].first;
      if (B[i].second){
        cnt++;
      }
    }
    if (cnt % 2 == 0){
      cout << prod1 << endl;
    } else {
      if (N == K){
        if (zero > 0){
          cout << 0 << endl;
        } else {
          cout << - prod1 << endl;
        }
      } else {
        bool pos1 = false;
        long long pos_small;
        bool neg1 = false;
        long long neg_small;
        for (int i = 0; i < K; i++){
          if (B[i].second){
            neg1 = true;
            neg_small = B[i].first;
          } else {
            pos1 = true;
            pos_small = B[i].first;
          }
        }
        bool pos2 = false;
        long long pos_large;
        bool neg2 = false;
        long long neg_large;
        for (int i = K; i < N; i++){
          if (B[i].second){
            if (!neg2){
              neg_large = B[i].first;
            }
            neg2 = true;
          } else {
            if (!pos2){
              pos_large = B[i].first;
            }
            pos2 = true;
          }
        }
        if ((pos1 && neg2) && !(neg1 && pos2)){
          prod1 /= pos_small;
          prod1 *= neg_large;
          cout << prod1 << endl;
        } else if (!(pos1 && neg2) && (neg1 && pos2)){
          prod1 /= neg_small;
          prod1 *= pos_large;
          cout << prod1 << endl;
        } else if (!(pos1 && neg2) && !(neg1 && pos2)){
          if (zero > 0){
            cout << 0 << endl;
          } else {
            long long prod2 = 1;
            for (int i = N - K; i < N; i++){
              prod2 *= B[i].first;
            }
            cout << - prod2 << endl;
          }
        } else {
          if (pos_large * pos_small < neg_large * neg_small){
            prod1 /= pos_small;
            prod1 *= neg_large;
            cout << prod1 << endl;
          } else {
            prod1 /= neg_small;
            prod1 *= pos_large;
            cout << prod1 << endl;
          }
        }
      }
    }
  }
}
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    solve();
  }
}