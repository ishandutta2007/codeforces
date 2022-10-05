#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int arr[n];
    arr[0] = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] == 'E') {
        arr[i] = arr[i - 1];
      } else {
        arr[i] = arr[i - 1] + 1;
      }
    }
    int flag = 0;
    if (s[0] == 'E') {
      if (arr[0] == arr[n - 1]) {
        flag = 1;
      }
    } else {
      if (arr[0] != arr[n - 1]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      cout << "YES" << endl;
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        arr[i] = arr[(i + n - 1) % n];
      }
    }
    flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'N') {
        if (arr[i] == arr[(i + n - 1) % n]) {
          flag = 1;
          break;
        }
      }
    }
    if (flag == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }
}