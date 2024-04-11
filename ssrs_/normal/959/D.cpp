#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<bool> is_prime(1500000, true);
  is_prime[1] = false;
  for (int i = 2; i * i <= 1500000; i++){
    if (is_prime[i]){
      for (int j = i * 2; j < 1500000; j += i){
        is_prime[j] = false;
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  set<int> st;
  for (int i = 2; i < 1500000; i++){
    st.insert(i);
  }
  set<int> prime_used;
  vector<int> b(n);
  bool smaller = false;
  for (int i = 0; i < n; i++){
    int lb;
    if (smaller){
      lb = 2;
    } else {
      lb = a[i];
    }
    auto itr = st.lower_bound(lb);
    b[i] = *itr;
    if (b[i] > a[i]){
      smaller = true;
    }
    int tmp = b[i];
    vector<int> pf;
    for (int j = 2; j * j <= tmp; j++){
      if (tmp % j == 0){
        pf.push_back(j);
        while (tmp % j == 0){
          tmp /= j;
        }
      }
    }
    if (tmp != 1){
      pf.push_back(tmp);
    }
    for (auto p : pf){
      if (!prime_used.count(p)){
        prime_used.insert(p);
        for (int j = p; j < 1500000; j += p){
          if (st.count(j)){
            st.erase(j);
          }
        }
      }
    }
  }
  for (int i = 0; i < n; i++){
    cout << b[i] << ' ';
  }
  cout << endl;
}