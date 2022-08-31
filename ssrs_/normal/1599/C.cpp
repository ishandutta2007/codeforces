#include <bits/stdc++.h>
using namespace std;
int main(){
  long long N;
  string P;
  cin >> N >> P;
  long long P_num, P_den;
  if (P == "0"){
    P_num = 0;
    P_den = 1;
  } else if (P == "1"){
    P_num = 1;
    P_den = 1;
  } else {
    P.erase(P.begin() + 1);
    P_num = stoi(P);
    int L = P.size();
    P_den = 1;
    for (int i = 0; i < L - 1; i++){
      P_den *= 10;
    }
  }
  for (int i = 0; i <= N; i++){
    long long s_num = 0, s_den = N * (N - 1) * (N - 2) * 2;
    s_num += i * (i - 1) * (i - 2) * 2;
    s_num += i * (i - 1) * (N - i) * 3 * 2;
    s_num += i * (N - i) * (N - 1 - i) * 3;
    if (s_num * P_den >= s_den * P_num){
      cout << i << endl;
      break;
    }
  }
}