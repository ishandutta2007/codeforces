#include <bits/stdc++.h>
using namespace std;
int LOG = 20;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int Q;
  cin >> Q;
  vector<int> p1(1, -1);
  vector<long long> w(1, 0);
  vector<int> p2(1, -1);
  //binary lifting
  vector<vector<int>> anc(1, vector<int>(LOG, -1));
  vector<vector<long long>> sum(1, vector<long long>(LOG, 0));
  int cnt = 1;
  long long last = 0;
  for (int i = 0; i < Q; i++){
    /*
    cout << "parent 1" << endl;
    for (int j : p1){
      cout << j << ' ';
    }
    cout << endl;
    cout << "weight" << endl;
    for (int j : w){
      cout << j << ' ';
    }
    cout << endl;
    cout << "parent 2" << endl;
    for (int j : p2){
      cout << j << ' ';
    }
    cout << endl;
    cout << "ancestor" << endl;
    for (auto i : anc){
      for (int j = 0; j < 3; j++){
        cout << i[j] << ' ';
      }
      cout << endl;
    }
    cout << "sum" << endl;
    for (auto i : sum){
      for (int j = 0; j < 3; j++){
        cout << i[j] << ' ';
      }
      cout << endl;
    }
    cout << endl;
    */
    int t;
    cin >> t;
    if (t == 1){
      long long p, q;
      cin >> p >> q;
      long long R = p ^ last;
      long long W = q ^ last;
      R--;
      //cout << "R = " << R << ", W = " << W << endl;
      p1.push_back(R);
      w.push_back(W);
      if (w[R] >= W){
        p2.push_back(R);
      } else {
        int v = R;
        while (v != -1 && w[v] < W){
          v = p2[v];
        }
        p2.push_back(v);
      }
      //calculate anc and sum
      anc.push_back(vector<int>(LOG, -1));
      sum.push_back(vector<long long>(LOG, 0));
      if (p2.back() != -1){
        anc.back()[0] = p2.back();
        sum.back()[0] = w[p2.back()];
        int v = p2.back();
        int e = 1;
        long long s = w[p2.back()];
        while (1){
          s += sum[v][e - 1];
          v = anc[v][e - 1];
          if (v == -1){
            break;
          }
          anc.back()[e] = v;
          sum.back()[e] = s;
          e++;
        }
      }
    } else {
      long long p, q;
      cin >> p >> q;
      long long R = p ^ last;
      long long X = q ^ last;
      R--;
      //cout << "R = " << R << ", X = " << X << endl;
      last = 0;
      if (X >= w[R]){
        X -= w[R];
        last = 1;
        int v = R;
        for (int i = LOG - 1; i >= 0; i--){
          if (anc[v][i] != -1){
            if (X >= sum[v][i]){
              X -= sum[v][i];
              v = anc[v][i];
              last += (1 << i);
            }
          }
        }
      }
      cout << last << endl;
    }
  }
}