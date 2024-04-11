#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=100007;
int n,m;
int a[N];
bool ok[3];
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin>>n;
  for (int i=0;i<n;++i) cin>>a[i];
  vector<pair<int,int>> b(n);
  for (int i=0;i<n;++i){
    b[i].first=1-(a[i]%3==0), b[i].second=i;
  }
  sort(b.begin(),b.end());
  vector<int> ans(n,0);
  for (int i=0;i<n/2;++i) ans[b[i].second]=1;
  if (b[n/2].first) cout<<0<<"\n";
  else cout<<2<<"\n";
  for (auto c:ans) cout<<c;
  return 0;
}