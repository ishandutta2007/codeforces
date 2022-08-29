#include <bits/stdc++.h>
using namespace std;
int main(){
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    int n,m;
    cin >> n >> m;
    int t,l,h;
    vector<tuple<int,int,int>> tlh(n);
    for (int j = 0; j < n; j++){
      cin >> t >> l >> h;
      tlh[j] = make_tuple(t,l,h);
    }
    sort(tlh.begin(),tlh.end());
    int L = m;
    int H = m;
    int T = 0;
    bool res = true;
    for (int j = 0; j < n; j++){
      t = get<0>(tlh[j]);
      l = get<1>(tlh[j]);
      h = get<2>(tlh[j]);
      if (j == 0){
        L -= t;
        H += t;
      } else {
        L -= t - get<0>(tlh[j - 1]);
        H += t - get<0>(tlh[j - 1]);
      }
      if (H < l || L > h){
        res = false;
        break;
      }
      if (H > h){
        H = h;
      }
      if (L < l){
        L = l;
      }
    }
    if (res){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}