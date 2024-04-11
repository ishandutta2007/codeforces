#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define image(a) {sort(all(a)), a.resize(unique(all(a)) - a.begin());}
const int maxc = (int)1e6 + 10;
int a[maxc];
int main(){
  int n;            
  cin >> n;
  int mx = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[x]++;
    if (a[x] > a[mx]) {
      mx = x;
    }
  }
  cout << mx << endl;
  return 0;
}