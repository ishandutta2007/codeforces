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
typedef pair<int, int> pi;
#define yes cout << "YES" << '\n'
#define no  cout << "NO" << '\n'
#define uwu '\n'

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  int t; cin >> t;
  for(int i=0; i<t; i++){
    bool fair = true;
    int a; int b; int c; int d; cin >> a; cin >> b; cin >> c; cin >> d;
    int c1; int c2;
    if(max(a,b)<min(d,c)){
      fair = false;
    }

    if(max(d,c)<min(a,b)){
      fair = false;
    }


    if(fair==true){
      yes;
    }
    else{
      no;
    }
  }
}