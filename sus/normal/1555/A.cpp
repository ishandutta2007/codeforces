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

bool isValid(int x, int y, int nx, int ny, int n){
  if ((nx <= n-1 && nx >= 0) && (ny <= -1*(n-1) && ny <= 0)) return true;
  
  
  return false;
}

void solve(){
  int t; cin >> t;
  while(t--){
    ll n; cin >> n;
    ll x = 0;
    if(n<=6){
      x = 15;
    }
    else{
      if(n%2 !=0){
        n++;
      }
      x = (n*5)/2;
    }
    cout << x << ln;
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