#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >>  q;
  for (int i = 0; i < q; i++){
    int n;
    cin >> n;
    string t;
    cin >> t;
    int p = 0;
    string s;
    while (!t.empty()){
      if (t.back() == '0'){
        s += 'a' - 1 + (t[t.size() - 3] - '0') * 10 + (t[t.size() - 2] - '0');
        t.pop_back();
        t.pop_back();
        t.pop_back();
      } else {
        s += 'a' - 1 + (t.back() - '0');
        t.pop_back();
      }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
  }
}