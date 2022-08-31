#include <bits/stdc++.h>
using namespace std;
long long INF = 5000000000000000000;
int main(){
  long long n;
  cin >> n;
  vector<long long> f = {1, 2};
  while (1){
    long long next = f[f.size() - 2] + f[f.size() - 1];
    if (next >= INF){
      break;
    }
    f.push_back(next);
  }
  cout << upper_bound(f.begin(), f.end(), n) - f.begin() - 1 << endl;
}