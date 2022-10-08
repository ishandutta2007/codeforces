#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
const int square=3, circle=1, tri=2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  int a[101];
  cin>>n;
  for (int i=0; i<n; i++) cin>>a[i];

  int total=0;
  for (int i=0; i+1<n; i++) {
    if ((a[i]==square&&a[i+1]==tri)||(a[i]==tri&&a[i+1]==square)) {
      cout<<"Infinite\n";
      return 0;
    }
    if (a[i]==circle) {
      if (a[i+1]==square) {
        total+=4;
      }
      if (a[i+1]==tri) {
        if (i==0||a[i-1]!=square)
          total+=3;
        else
          total+=2;
      }
    }
    if (a[i]==tri) {
      if (a[i+1]==circle) {
        total+=3;
      }
      else {
        assert(false);
      }
    }
    if (a[i]==square) {
      if (a[i+1]==circle) {
        total+=4;
      }
      else {
        assert(false);
      }
    }
  }
  cout<<"Finite\n"<<total<<'\n';
  return 0;
}