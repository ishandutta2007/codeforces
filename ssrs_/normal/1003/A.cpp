#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> cnt(101, 0);
  for (int i = 0; i < n; i++){
    cnt[a[i]]++;
  }
  cout << *max_element(cnt.begin(), cnt.end()) << endl;
}