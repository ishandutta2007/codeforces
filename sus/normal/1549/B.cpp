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
bool vis[1000000];
void solve(){
  ll t; cin >> t;
  while(t--){
    ll n; cin >> n;
    string first; cin >> first;
    string second; cin >> second;
    ll count = 0;
    for(int i=0; i<n; i++){
      vis[i]=false;
    }
    for(int i=0; i<n; i++){
      if(second[i]=='1'){

      
        if(i==0){

          if(first[i]=='0' && second[i]=='1'){
            count++;

          }
          else if(first[i+1]=='1' && second[i]=='1' && vis[i+1]==false){
            count++;
            vis[i+1]=true;
          }
        }
        else if(i==n-1){
          if(first[i]=='0' && second[i]=='1'){
            count++;
          }
          else if(first[i-1]=='1' && second[i]=='1'&& vis[i-1]==false){
            count++;
            vis[i-1]=true;
          }
        }
        else {
          if(first[i]=='0' && second[i]=='1'){
            count++;
          }
          else if(first[i-1]=='1' && second[i]=='1'&& vis[i-1]==false){
            count++;
            vis[i-1]=true;
          }
          else if(first[i+1]=='1' && second[i]=='1'&& vis[i+1]==false){
            count++;
            vis[i+1]=true;
          }
        }
      }
    }
    cout << count << ln;

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