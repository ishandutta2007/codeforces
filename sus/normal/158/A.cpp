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

void solve(){
  int n; int k; cin >> n; cin >> k;
  int arr[n];
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }

  int counter = 0;
  for(int i=0; i<n; i++){
    if(arr[i]>=arr[k-1] && arr[i]>0){
      counter++;
    }
  }
  cout << counter;

}

int main() {
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif
  solve();
}