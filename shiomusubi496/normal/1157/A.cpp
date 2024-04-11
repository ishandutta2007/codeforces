#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int n; cin>>n;
  set<int> st;
  while(st.count(n)==0){
    st.insert(n);
    n+=1;
    while(n%10==0)n/=10;
  }
  cout<<st.size()<<endl;
}