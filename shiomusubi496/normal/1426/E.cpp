#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n,ar,as,ap,br,bs,bp;
  cin>>n>>ar>>as>>ap>>br>>bs>>bp;
  int cnt=(ar<=bs)+(as<=bp)+(ap<=br);
  cout<<max(ar+bs-n,0LL)+max(as+bp-n,0LL)+max(ap+br-n,0LL)<<' ';
  cout<<(ar<=bs?ar:bs)+(as<=bp?as:bp)+(ap<=br?ap:br);
  cout<<'\n';
}