#include <bits/stdc++.h>
using namespace std;
int main(){
  int h;
  cin >> h;
  vector<int> a(h + 1);
  for (int i = 0; i <= h; i++){
    cin >> a[i];
  }
  int X = -1;
  for (int i = 1; i < h; i++){
    if (a[i] >= 2 && a[i + 1] >= 2){
      X = i;
    }
  }
  if (X == -1){
    cout << "perfect" << endl;
  } else {
    vector<int> ans1;
    ans1.push_back(-1);
    for (int i = 1; i <= h; i++){
      int p = ans1.size() - 1;
      for (int j = 0; j < a[i]; j++){
        ans1.push_back(p);
      }
    }
    int S = 0;
    for (int i = 0; i <= X; i++){
      S += a[i];
    }
    vector<int> ans2 = ans1;
    ans2[S]--;
    cout << "ambiguous" << endl;
    int sz = ans1.size();
    for (int i = 0; i < sz; i++){
      cout << ans1[i] + 1;
      if (i < sz - 1){
        cout << ' ';
      }
    }
    cout << endl;
    for (int i = 0; i < sz; i++){
      cout << ans2[i] + 1;
      if (i < sz - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}