#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = 0;
    for (int S1 = 0; S1 <= 1; S1++){
    for (int S2 = 0; S2 <= 1; S2++){
    for (int S3 = 0; S3 <= 1; S3++){
    for (int S4 = 0; S4 <= 1; S4++){
    for (int S5 = 0; S5 <= 1; S5++){
    for (int S6 = 0; S6 <= 1; S6++){
    for (int S7 = 0; S7 <= 1; S7++){
      int A = 0, B = 0, C = 0;
      if (S1 == 1){
        A++;
      }
      if (S2 == 1){
        B++;
      }
      if (S3 == 1){
        C++;
      }
      if (S4 == 1){
        A++;
        B++;
      }
      if (S5 == 1){
        B++;
        C++;
      }
      if (S6 == 1){
        C++;
        A++;
      }
      if (S7 == 1){
        A++;
        B++;
        C++;
      }
      if (a >= A && b >= B && c >= C){
        ans = max(ans,S1 + S2 + S3 + S4 + S5 + S6 + S7);
      }
    }
    }
    }
    }
    }
    }
    }
    cout << ans << endl;
  }
}