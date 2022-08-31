#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
struct binary_trie{
  int N;
  vector<int> prev, left, right, count;
  binary_trie(): N(1), prev(1, -1), left(1, -1), right(1, -1), count(1, 0){
  }
  void add(int p){
    prev.push_back(p);
    left.push_back(-1);
    right.push_back(-1);
    count.push_back(0);
    N++;
  }
  void insert(int x){
    int v = 0;
    for (int i = 30; i >= 0; i--){
      int a = (x >> i) & 1;
      if (a == 0 && left[v] == -1){
        left[v] = N;
        add(v);
      }
      if (a == 1 && right[v] == -1){
        right[v] = N;
        add(v);
      }
      if (a == 0){
        v = left[v];
      } else {
        v = right[v];
      }
    }
    count[v]++;
    while (prev[v] != -1){
      v = prev[v];
      count[v] = 0;
      if (left[v] != -1){
        count[v] += count[left[v]];
      }
      if (right[v] != -1){
        count[v] += count[right[v]];
      }
    }
  }
  int order(int x){
    int v = 0;
    int ans = 0;
    for (int i = 30; i >= 0; i--){
      if ((x >> i & 1) == 0){
        v = left[v];
      } else {
        if (left[v] != -1){
          ans += count[left[v]];
        }
        v = right[v];
      }
      if (v == -1){
        break;
      }
    }
    return ans;
  }
};
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  binary_trie st;
  int lastans = 0;
  for (int i = 0; i < n; i++){
    int T;
    cin >> T;
    T += MAX;
    int tv1 = T + MAX, fv1 = T - MAX;
    while (tv1 - fv1 > 1){
      int mid = (tv1 + fv1) / 2;
      if (mid - st.order(mid + 1) + i >= T){
        tv1 = mid;
      } else {
        fv1 = mid;
      }
    }
    int tv2 = T + MAX, fv2 = T - MAX;
    while (tv2 - fv2 > 1){
      int mid = (tv2 + fv2) / 2;
      if (mid - st.order(mid + 1) + i > T){
        tv2 = mid;
      } else {
        fv2 = mid;
      }
    }
    st.insert(tv1);
    st.insert(tv2);
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){
      int xx;
      cin >> xx;
      int x = (xx + lastans) % 1000000001;
      lastans = x - st.order(x + MAX + 1) + (i + 1);
      cout << lastans << "\n";
    }
  }
}