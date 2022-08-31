#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  reverse(a.begin(), a.end());
  vector<int> b;
  set<int> st;
  for (int i = 0; i < n; i++){
    if (!st.count(a[i])){
      st.insert(a[i]);
      b.push_back(a[i]);
    }
  }
  reverse(b.begin(), b.end());
  int x = b.size();
  cout << x << endl;
  for (int i = 0; i < x; i++){
    cout << b[i];
    if (i < x - 1){
      cout << ' ';
    }
  }
  cout << endl;
}