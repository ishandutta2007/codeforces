#include <bits/stdc++.h>
using namespace std;
vector<int> get_groups(){
  int k;
  cin >> k;
  vector<int> id(10);
  for (int i = 0; i < k; i++){
    string S;
    cin >> S;
    for (char c : S){
      id[c - '0'] = i;
    }
  }
  return id;
}
int main(){
  while (true){
    cout << "next 0 1" << endl;
    get_groups();
    cout << "next 1" << endl;
    vector<int> id = get_groups();
    if (id[0] == id[1]){
      break;
    }
  }
  bool same = false;
  while (true){
    cout << "next 1 2" << endl;
    vector<int> id = get_groups();
    if (id[0] == id[1]){
      if (id[0] == id[2]){
        same = true;
      }
      break;
    }
  }
  while (true){
    if (same){
      cout << "next 0 1 2 3 4 5 6 7 8 9" << endl;
    } else {
      cout << "next 2 3 4 5 6 7 8 9" << endl;
    }
    vector<int> id = get_groups();
    if (id[0] == id[2]){
      same = true;
    }
    if (id[2] == id[3]){
      break;
    }
  }
  cout << "done" << endl;
}