// sus sus amongu, this code was made by sathu
// copy it if you wish, but your coding skills will perish
#include <iostream>
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
#define uwu '\n'

void solve(){
  int n; cin >> n;

  if(n==2){
    cout << 2 << sp;
    cout << 1 << sp;
  }
  else if(n==3){
    cout << 3 << sp << 1 << sp << 2; 
  }
  else {
    if(n%2==0){
      cout << 2 << sp << 1 << sp;
      for(int i=3; i<=n; i++){
      if(i%2==0){
        cout << i-1 << sp;
      }
      else{
        cout << i+1 << sp;
      }

      
    }

    }
    else{
      cout << 3 << sp << 1 << sp << 2 << sp; 
      for(int i=4; i<=n; i++){
      if(i%2==1){
        cout << i-1 << sp;
      }
      else{
        cout << i+1 << sp;
      }
      
    }

    }

  }
  

  cout << uwu;

  
  
}




  


int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t; cin >> t;
  for(int i=0; i<t; i++){
    solve();
  }
}