#include <iostream>
#include <vector>
using namespace std;


int main() {
  int n;
  int alice;
  cin >> n;

  cin >> alice;
  vector<int> res;
  res.push_back(1);
  int a = 0, b = 0;
  a += alice;
  for(int i = 1; i < n; ++i) {
    int x;
    cin >> x;

    if (alice >= 2 * x) {
      res.push_back(i + 1);
      a += x;
    } else {
      b += x;
    }
  }

  if (a > b) {
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); ++i) {
      cout << res[i] << " ";
    }
    cout << "\n";
  } else {
    cout << "0\n";
  }
}