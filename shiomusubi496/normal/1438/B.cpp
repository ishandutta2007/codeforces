#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
  int Q;
  cin>>Q;
  while(Q--){
    int N;
    cin>>N;
    set<int> S;
    for(int i=0;i<N;i++){
      int a;
      cin>>a;
      S.insert(a);
    }
    puts(S.size()==N?"NO":"YES");
  }
}