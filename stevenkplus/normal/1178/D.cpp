#include <iostream>
using namespace std;

void p(int i, int j) {
  ++i;
  ++j;
  cout << i << " " << j << "\n";
}

int main() {
  int n;
  cin >> n;
  int m;
  for(int i = n; true; ++i) {
    bool pr = true;
    for(int j = 2; j < i; ++j) {
      if (i % j == 0) {
        pr = false;
      }
    }
    if (pr) {
      m = i;
      break;
    }
  }
  cout << m << "\n";
  for(int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    p(i, j);
  }
  for(int i = 0; i < m - n; ++i) {
    int j = (i + n / 2) % n;
    p(i, j);
  }
    
}