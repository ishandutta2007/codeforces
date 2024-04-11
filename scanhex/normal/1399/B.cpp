#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
cin >> t;
while(t--) {
int n;
cin >> n;
vector<int>a(n), b(n);
for(int i = 0; i < n; ++i) cin >> a[i];
for(int i=0;i<n;++i)cin>>b[i];
int mna=1e9,mnb=1e9;
for(int i =0; i < n; ++i)mna=min(mna,a[i]),mnb=min(mnb,b[i]);
long long ans = 0;
for(int i =0;i<n;++i){
int c1 = a[i]-mna;
int c2=b[i]-mnb;
ans += max(c1,c2);
}
cout<<ans<<'\n';

}
}