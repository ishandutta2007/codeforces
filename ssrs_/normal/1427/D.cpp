#include <bits/stdc++.h>
using namespace std;
vector<int> sub(vector<int> A, int l, int r){
  vector<int> ans;
  for (int i = l; i < r; i++){
    ans.push_back(A[i]);
  }
  return ans;
}
void add(vector<int> &A, vector<int> B){
  for (int x : B){
    A.push_back(x);
  }
  return;
}
int main(){
  int n;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  vector<vector<int>> op;
  bool rev = false;
  for (int i = 0; i < n - 1; i++){
    /*
    cout << "i = " << i << endl;
    cout << "rev = " << rev << endl;
    cout << "c:";
    for (int j : c){
      cout << ' ' << j;
    }
    cout << endl;
    */
    int p1, p2;
    for (int j = 0; j < n; j++){
      if (c[j] == i + 1){
        p1 = j;
      }
      if (c[j] == i + 2){
        p2 = j;
      }
    }
    bool update = false;
    if (p1 < p2 && p1 != p2 - 1){
      p1 = n - 1 - p1;
      p2 = n - 1 - p2;
      reverse(c.begin(), c.end());
      rev = !rev;
      update = true;
    }
    if (p1 > p2){
      /*
      cout << "curr:" << endl;
      for (int j = 0; j < n; j++){
        cout << c[j] << ' ';
      }
      cout << endl;
      */
      vector<int> tmp;
      if (!update){
        tmp = {p2, 1, p1 - p2, n - 1 - p1};
      } else {
        tmp = {p2, p1 - p2, 1};
        for (int j = p1 + 1; j < n; j++){
          tmp.push_back(1);
        }
      }
      op.push_back(vector<int>(0));
      for (int x : tmp){
        if (x > 0){
          op.back().push_back(x);
        }
      }
      vector<vector<int>> tmp2;
      int sum = 0;
      for (int x : op.back()){
        tmp2.push_back(sub(c, sum, sum + x));
        sum += x;
      }
      reverse(tmp2.begin(), tmp2.end());
      c.clear();
      for (auto x : tmp2){
        add(c, x);
      }
      /*
      for (int x : c){
        cout << x << ' ';
      }
      cout << endl;
      */
      if (rev){
        reverse(op.back().begin(), op.back().end());
      }
    }
  }
  if (rev){
    op.push_back(vector<int>(n, 1));
  }
  int q = op.size();
  cout << q << endl;
  for (int i = 0; i < q; i++){
    int k = op[i].size();
    cout << k;
    for (int j = 0; j < k; j++){
      cout << ' ' << op[i][j];
    }
    cout << endl;
  }
}