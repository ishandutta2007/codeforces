#include <iostream>
typedef long long ll;
using namespace std;
const int maxn=300001;
ll a[maxn], diffs[maxn];
int n, m;

ll gcd(ll a, ll b) {
  if (b==0) return a;
  return gcd(b, a%b);
}

int main() {
  cin>>n>>m;
  for (int i=0; i<n; i++) cin>>a[i];
  for (int i=0; i<m; i++) cin>>diffs[i];
  ll gcdd=0;
  for (int i=1; i<n; i++)
    gcdd=gcd(gcdd, a[i]-a[0]);
  for (int i=0; i<m; i++) {
    if (gcdd%diffs[i]==0) {
      cout<<"YES\n"<<a[0]<<" "<<i+1<<'\n';
      return 0;
    }
  }
  cout<<"NO\n";
  return 0;

}