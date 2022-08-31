#include <bits/stdc++.h>
using namespace std;
int main(){
  mt19937 mt(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
  int n, k;
  cin >> n >> k;
  int small = -1, big = -1;
  while (small == -1 || big == -1){
    int q = mt() % n;
    cout << "? " << q + 1 << endl;
    int c;
    cin >> c;
    if (c < k){
      small = q;
    }
    if (c > k){
      big = q;
    }
  }
  if (big < small){
    big += n;
  }
  while (1){
    int mid = (small + big) / 2;
    cout << "? " << mid % n + 1 << endl;
    int c;
    cin >> c;
    if (c == k){
      cout << "! " << mid % n + 1 << endl;
      break;
    }
    if (c < k){
      small = mid;
    }
    if (c > k){
      big = mid;
    }
  }
  /*
  int n = 13, k = 100, p = 4;
  vector<int> a(n, k);
  for (int i = 0; i < 10; i++){
    for (int j = 0; j < n; j++){
      cout << a[j] << ' ';
    }
    cout << endl;
    vector<int> b(n, 0);
    for (int j = 0; j < n; j++){
      if (j != p){
        b[(j + n - 1) % n] += a[j] / 2;
        b[(j + 1) % n] += (a[j] + 1) / 2;
      } else {
        b[(j + 1) % n] += a[j];
      }
    }
    swap(a, b);
  }
  */
}