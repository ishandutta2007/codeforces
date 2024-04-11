#include <bits/stdc++.h>
using namespace std;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, p, q, r;
  cin >> n >> p >> q >> r;
  vector<tuple<int, int, int>> card(n);
  for (int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    card[i] = make_tuple(a, b, c);
  }
  sort(card.begin(), card.end());
  set<int> A;
  A.insert(1);
  A.insert(p + 1);
  for (int i = 0; i < n; i++){
    A.insert(get<0>(card[i]) + 1);
  }
  set<int> B;
  B.insert(1);
  B.insert(q + 1);
  for (int i = 0; i < n; i++){
    B.insert(get<1>(card[i]) + 1);
  }
  set<int> C;
  C.insert(1);
  C.insert(r + 1);
  for (int i = 0; i < n; i++){
    C.insert(get<2>(card[i]) + 1);
  }
  vector<int> aval;
  for (auto a : A){
    aval.push_back(a);
  }
  vector<int> bval;
  for (auto b : B){
    bval.push_back(b);
  }
  int Acnt = aval.size() - 1;
  int Bcnt = bval.size() - 1; //range cnt
  vector<pair<int, int>> range(Bcnt); //ranges of B
  for (int i = 0; i < bval.size() - 1; i++){
    range[i] = make_pair(bval[i], bval[i + 1]);
  }
  vector<int> min_c(Bcnt, 1);
  for (int i = 0; i < n; i++){
    int a = get<0>(card[i]);
    int b = get<1>(card[i]);
    int c = get<2>(card[i]);
    if (a == p){
      min_c.back() = max(min_c.back(), c + 1);
      auto itr = lower_bound(bval.begin(), bval.end(), b + 1) - 1;
      int pos = itr - bval.begin();
      min_c[pos] = r + 1;
    } else {
      auto itr = lower_bound(bval.begin(), bval.end(), b + 1) - 1;
      int pos = itr - bval.begin();
      min_c[pos] = max(min_c[pos], c + 1);
    }
  }
  //Emax
  for (int i = Bcnt - 1; i >= 1; i--){
    min_c[i - 1] = max(min_c[i - 1], min_c[i]);
  }
  /*
  cout << "bval.size() = " << bval.size() << endl;
  for (int i = 0; i < Bcnt; i++){
    cout << "[" << bval[i] << "," << bval[i + 1] << "), m = " << min_c[i] << endl;
  }
  */
  long long curr = 0;
  //calculate area
  for (int i = 0; i < Bcnt; i++){
    curr += (long long) (range[i].second - range[i].first) * (r - min_c[i] + 1);
  }
  //cout << "curr = " << curr << endl;
  long long ans = 0;
  for (int i = Acnt - 1; i >= 0; i--){
    ans += curr * (aval[i + 1] - aval[i]);
    //cout << "ans = " << ans << endl;
    //cout << "aval[i] = " << aval[i] << endl;
    //update min_c
    auto itr1 = lower_bound(card.begin(), card.end(), make_tuple(aval[i] - 1, 0, 0));
    auto itr2 = lower_bound(card.begin(), card.end(), make_tuple(aval[i], 0,0));
    //cout << "dist = " << itr2 - itr1 << endl;
    for (auto itr = itr1; itr < itr2; itr++){
      int b = get<1>(*itr);
      int c = get<2>(*itr);
      //cout << "b = " << b << ", c = " << c << endl;
      auto itr3 = lower_bound(bval.begin(), bval.end(), b + 1) - 1;
      int pos = itr3 - bval.begin();
      //cout << "begin = " << bval[pos] << ", end = " << bval[pos + 1] << endl;
      for (int j = pos; j >= 0; j--){
        long long delta = r + 1 - min_c[j];
        if (delta == 0){
          break;
        } else {
          //cout << "a: j = " << j << ", delta = " << delta << endl;
          curr -= delta * (bval[j + 1] - bval[j]);
          min_c[j] = r + 1;
        }
      }
      pos++;
      for (int j = Bcnt - 1; j >= pos; j--){
        long long delta = c + 1 - min_c[j];
        if (delta <= 0){
          break;
        } else {
          //cout << "b: j = " << j << ", delta = " << delta << endl;
          curr -= delta * (bval[j + 1] - bval[j]);
          min_c[j] = c + 1;
        }
      }
      //cout << endl;
    }
    /*
    for (int i = 0; i < Bcnt; i++){
      cout << "[" << bval[i] << "," << bval[i + 1] << "), m = " << min_c[i] << endl;
    }
    cout << "curr = " << curr << endl;
    */
  }
  cout << ans << endl;
}