#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  long long ans = 0;
  for (int i = A + B; i <= B + C; i++){
    long long tmp;
    if (i < min(A + C, B + B)){
      tmp = i - (A + B) + 1;
    } else if (i <= max(A + C, B + B)){
      tmp = min(B - A + 1, C - B + 1);
    } else {
      tmp = (B + C) - i + 1;
    }
    int lb = C;
    int ub = min(D, i - 1);
    if (ub < lb){
      ub = lb - 1;
    }
    ans += tmp * (ub - lb + 1);
  }
  cout << ans << endl;
}