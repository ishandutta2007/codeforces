// sus sus amongu, this code was made by sathu
// copy it if you wish, but your coding skills will perish
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <fstream>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define uwu '\n'

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int n; cin >> n;
  for(int i = 0; i<n; i++){
    string str; cin >> str;
    if(str.length()>10){
      cout << str[0] << str.length()-2 << str[str.length()-1] << uwu;
    }
    else{
      cout << str << uwu;
    }

  }
    
}