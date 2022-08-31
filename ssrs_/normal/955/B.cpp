#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  set<char> st;
  map<char, int> mp;
  for (int i = 0; i < N; i++){
    st.insert(s[i]);
    mp[s[i]]++;
  }
  if (st.size() == 1){
    cout << "No" << endl;
  } else if (st.size() == 2){
    char c1 = *(st.begin());
    char c2 = *next(st.begin());
    if (mp[c1] > 1 && mp[c2] > 1){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  } else if (st.size() == 3){
    if (N == 3){
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  } else if (st.size() == 4){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}