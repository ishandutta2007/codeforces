#include<bits/stdc++.h>
#define int long long
using namespace std;
using ld=long double;
signed main(){
  ld n,h; cin>>n>>h;
  for(int i=1;i<n;i++)cout<<fixed<<setprecision(16)<<sqrt(h*h/n*i)<<" \n"[i==n-1];
}