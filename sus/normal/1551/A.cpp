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
#include <sstream>
#include <string>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define sp " "
#define ln '\n'



void solve(){
  int t; cin >> t;
  for(int i=0; i<t; i++){
    int n; cin >> n;
    int c1 = 0;
    int c2 = 0;
    if(n==1){
      cout << 1 << sp << 0 << ln;
    }
    else{
      if(n%3==0){
        c1 = n/3;
        c2 = c1;
        cout << c1 << sp << c2 << ln;
      }
      else if(n%3==1){
        c1 = n/3+1;
        c2 = n/3;
        cout << c1 << sp << c2 << ln;
      }
      else{
        c1 = n/3;
        c2 = c1+1;
        cout << c1 << sp << c2 << ln;
      }
    }
  }
}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();

  
}