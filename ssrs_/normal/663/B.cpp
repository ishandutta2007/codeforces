#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    string S;
    cin >> S;
    S = S.substr(4);
    int L = S.size();
    set<int> st;
    for (int i = 0; i < L; i++){
      string T = S.substr(L - 1 - i);
      int j = 0;
      while (1){
        string tmp = to_string(j) + T;
        int x = stoi(tmp);
        if (x >= 1989 && !st.count(x)){
          st.insert(x);
          if (i == L - 1){
            cout << x << endl;
          }
          break;
        }
        j++;
      }
    }
  }
}