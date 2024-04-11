#include <iostream>
#include <stack>
using namespace std;
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int a; cin >> a;
  int b; cin >> b;
  int ans = 0;
  while(a<=b){
    ans++;
    a*=3;
    b*=2;
  }
  cout << ans;
}