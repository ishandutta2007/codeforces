#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

static bool diffSmallEnough(int diff, int z, vector<int> &a) {
  int n=a.size();
  for (int i=0; i+diff<n; i++)
    if (a[i+diff]-a[i]<z)
      return false;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, z;
  cin>>n>>z;
  vector<int> a;
  for (int i=0; i<n; i++) {
    int temp;
    cin>>temp;
    a.push_back(temp);
  }
  sort(a.begin(), a.end());

  int min=(n+1)/2, max=n;
  while (min!=max) {
    int mid=(min+max)/2;
    if (diffSmallEnough(mid, z, a)) {
      max=mid;
    }
    else {
      min=mid+1;
    }
  }
  int count=n-min;
  cout<<count<<'\n';

  return 0;
}