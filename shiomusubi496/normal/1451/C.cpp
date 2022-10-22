#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int n,k;
    string a,b;
    cin>>n>>k>>a>>b;
    vector<int> A(27),B(27);
    for(char c:a)A[c-'a']++;
    for(char c:b)B[c-'a']++;
    for(int i=0;i<26;i++){
      if(A[i]<B[i])goto home;
      if((A[i]-B[i])%k)goto home;
      A[i+1]+=A[i]-B[i];
    }
    puts("YES");
    continue;
    home:;
    puts("NO");
  }
}