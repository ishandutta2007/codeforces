#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> a(4);
  for (int i = 0; i < 4; i++){
    cin >> a[i];
  }
  int l = 0;
  while (a[0] == 0){
    a.erase(a.begin());
    l++;
  }
  while (a.back() == 0){
    a.pop_back();
  }
  vector<int> ans;
  if (a.size() == 1){
    if (a[0] == 1){
      ans = vector<int>(a[0], l);
    }
  }
  if (a.size() == 2){
    if (a[0] == a[1] - 1){
      for (int i = 0; i < a[0]; i++){
        ans.push_back(l + 1);
        ans.push_back(l);
      }
      ans.push_back(l + 1);
    } else if (a[0] == a[1]){
      for (int i = 0; i < a[0]; i++){
        ans.push_back(l);
        ans.push_back(l + 1);
      }
    } else if (a[0] == a[1] + 1){
      for (int i = 0; i < a[1]; i++){
        ans.push_back(l);
        ans.push_back(l + 1);
      }
      ans.push_back(l);
    }
  }
  if (a.size() == 3){
    if (a[1] == a[0] + a[2] + 1){
      for (int i = 0; i < a[0]; i++){
        ans.push_back(l + 1);
        ans.push_back(l);
      }
      for (int i = 0; i < a[2]; i++){
        ans.push_back(l + 1);
        ans.push_back(l + 2);
      }
      ans.push_back(l + 1);
    } else if (a[1] == a[0] + a[2]){
      for (int i = 0; i < a[0]; i++){
        ans.push_back(l + 1);
        ans.push_back(l);
      }
      for (int i = 0; i < a[2]; i++){
        ans.push_back(l + 1);
        ans.push_back(l + 2);
      }
    } else if (a[1] == a[0] + a[2] - 1){
      for (int i = 0; i < a[0]; i++){
        ans.push_back(l);
        ans.push_back(l + 1);
      }
      for (int i = 0; i < a[2] - 1; i++){
        ans.push_back(l + 2);
        ans.push_back(l + 1);
      }
      ans.push_back(l + 2);
    }
  }
  if (a.size() == 4){
    for (int i = 0; i < 4; i++){
      vector<int> a2 = a;
      if (i & 1){
        a2[0]++;
      }
      if (i & 2){
        a2[3]++;
      }
      vector<int> tmp;
      int x = a2[0];
      if (a2[1] < x){
        continue;
      }
      a2[1] -= x;
      for (int j = 0; j < x; j++){
        tmp.push_back(0);
        tmp.push_back(1);
      }
      tmp.push_back(2);
      int y = a2[1];
      if (a2[2] < y){
        continue;
      }      
      for (int j = 0; j < y; j++){
        tmp.push_back(1);
        tmp.push_back(2);
      }
      a2[2] -= y;
      int z = a2[2];
      if (a2[3] != z){
        continue;
      }
      for (int j = 0; j < z - 1; j++){
        tmp.push_back(3);
        tmp.push_back(2);
      }
      tmp.push_back(3);
      if (i & 1){
        tmp.erase(tmp.begin());
      }
      if (i & 2){
        tmp.pop_back();
      }
      ans = tmp;
      break;
    }
  }
  if (ans.empty()){
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    int s = ans.size();
    for (int i = 0; i < s; i++){
      cout << ans[i];
      if (i < s - 1){
        cout << ' ';
      }
    }
    cout << endl;
  }
}