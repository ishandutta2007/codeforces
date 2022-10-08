#include <iostream>

using namespace std;

const int maxn=100001;
char a[maxn];
int main() {
  int n;
  cin>>n>>a;
  int eights=0, non=0;
  for (int i=0; i+10<n; i++) {
    if (a[i]=='8') eights++;
    else non++;
  }
  if (eights>non) {
    cout<<"YES\n";
  }
  else {
    cout<<"NO\n";
  }
  return 0;
}