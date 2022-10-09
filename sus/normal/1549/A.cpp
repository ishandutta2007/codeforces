// sus sus amongu, this code was made by sathu
// copy it if you wish, but your coding skills will perish
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <stdio.h>   
#include <stdlib.h> 
#include <algorithm>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'
 
void fastIO(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
 
 
 
void solve(){
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    if(n==3){
      cout << 1 << sp << 3 << ln;
    }
    else {
      int a = n-1;
      int b = a/2;
      cout << b << sp << a << ln;
    }
  }
}
 

   
 
int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  fastIO();
  solve();
 
  
}