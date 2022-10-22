#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n,q;
    string s;
    cin>>n>>q>>s;
    vector<bool> ok1(n),ok2(n);
    bool o1=false,o0=false;
    for(int i=0;i<n;i++){
      ok1[i]=(s[i]=='0'?o0:o1);
      (s[i]=='0'?o0:o1)=true;
    }
    o1=false,o0=false;
    for(int i=n-1;i>=0;i--){
      ok2[i]=(s[i]=='0'?o0:o1);
      (s[i]=='0'?o0:o1)=true;
    }
    while(q--){
      int l,r;
      cin>>l>>r;
      puts(ok1[l-1]||ok2[r-1]?"YES":"NO");
    }
  }
}