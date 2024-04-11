#include <iostream>
#include <string>
#include <set>
using namespace std;


int main() {

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int a, m;
  cin >> a >> m;
  set<int>s;
  set<int> :: iterator it;
  for(int i=1; i<=m; i++){
    s.insert(i);
  }
  while(a--){
    int l, r;
    cin >> l >> r;
    for(int i=l; i<=r; i++){
      s.erase(i);
    }
  }
  cout<<s.size()<<'\n';
  for(it=s.begin(); it!=s.end(); it++){
    cout<<*it<<" ";
  }
  

}