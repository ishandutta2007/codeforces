#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  for (int i = 0; i < t; i++){
    int h;
    cin >> h;
    vector<int> l(h);
    for (int j = 0; j < h; j++){
      cin >> l[j];
    }
    int v;
    cin >> v;
    vector<int> p(v);
    for (int j = 0; j < v; j++){
      cin >> p[j];
    }
    if (h != v){
      cout << "No" << endl;
    } else {
      int lsum = 0;
      for (int j = 0; j < h; j++){
        lsum += l[j];
      }
      int psum = 0;
      for (int j = 0; j < v; j++){
        psum += p[j];
      }
      if (lsum % 2 == 1 || psum % 2 == 1){
        cout << "No" << endl;
      } else {
        vector<vector<bool>> dph(h + 1, vector<bool>(lsum / 2 + 1, false));
        dph[0][0] = true;
        for (int j = 0; j < h; j++){
          dph[j + 1] = dph[j];
          for (int k = lsum / 2; k >= l[j]; k--){
            if (dph[j][k - l[j]]){
              dph[j + 1][k] = true;
            }
          }
        }
        vector<vector<bool>> dpv(v + 1, vector<bool>(psum / 2 + 1, false));
        dpv[0][0] = true;
        for (int j = 0; j < v; j++){
          dpv[j + 1] = dpv[j];
          for (int k = psum / 2; k >= p[j]; k--){
            if (dpv[j][k - p[j]]){
              dpv[j + 1][k] = true;
            }
          }
        }
        if (!dph[h][lsum / 2] || !dpv[v][psum / 2]){
          cout << "No" << endl;
        } else {
          int hc = lsum / 2;
          vector<int> ha, hb;
          for (int j = h - 1; j >= 0; j--){
            if (!dph[j][hc]){
              ha.push_back(l[j]);
              hc -= l[j];
            } else {
              hb.push_back(l[j]);
            }
          }
          int vc = psum / 2;
          vector<int> va, vb;
          for (int j = v - 1; j >= 0; j--){
            if (!dpv[j][vc]){
              va.push_back(p[j]);
              vc -= p[j];
            } else {
              vb.push_back(p[j]);
            }
          }
          if (va.size() == ha.size()){
            sort(ha.rbegin(), ha.rend());
            sort(hb.rbegin(), hb.rend());
            sort(va.begin(), va.end());
            sort(vb.begin(), vb.end());
            cout << "Yes" << endl;
            int x = 0, y = 0;
            for (int j = 0; j < va.size(); j++){
              x += ha[j];
              cout << x << ' ' << y << endl;
              y += va[j];
              cout << x << ' ' << y << endl;
            }
            for (int j = 0; j < vb.size(); j++){
              x -= hb[j];
              cout << x << ' ' << y << endl;
              y -= vb[j];
              cout << x << ' ' << y << endl;
            }
          }
          if (ha.size() < va.size()){
            vector<int> h1, v1;
            for (int j = 0; j < ha.size(); j++){
              h1.push_back(ha[j]);
              v1.push_back(va[j]);
            }
            vector<int> h2, v2;
            for (int j = 0; j < va.size() - ha.size(); j++){
              h2.push_back(hb[j]);
              v2.push_back(va[j + ha.size()]);
            }
            vector<int> h3, v3;
            for (int j = 0; j < h - va.size(); j++){
              h3.push_back(hb[j + (va.size() - ha.size())]);
              v3.push_back(vb[j]);
            }
            sort(h1.rbegin(), h1.rend());
            sort(v1.begin(), v1.end());
            sort(h2.begin(), h2.end());
            sort(v2.rbegin(), v2.rend());
            sort(h3.rbegin(), h3.rend());
            sort(v3.begin(), v3.end());
            cout << "Yes" << endl;
            int x = 0, y = 0;
            for (int j = 0; j < h1.size(); j++){
              x += h1[j];
              cout << x << ' ' << y << endl;
              y += v1[j];
              cout << x << ' ' << y << endl;
            }
            for (int j = 0; j < h2.size(); j++){
              x -= h2[j];
              cout << x << ' ' << y << endl;
              y += v2[j];
              cout << x << ' ' << y << endl;
            }
            for (int j = 0; j < h3.size(); j++){
              x -= h3[j];
              cout << x << ' ' << y << endl;
              y -= v3[j];
              cout << x << ' ' << y << endl;
            }
          }
          if (ha.size() > va.size()){
            vector<int> h1, v1;
            for (int j = 0; j < va.size(); j++){
              h1.push_back(ha[j]);
              v1.push_back(va[j]);
            }
            vector<int> h2, v2;
            for (int j = 0; j < ha.size() - va.size(); j++){
              h2.push_back(ha[j + va.size()]);
              v2.push_back(vb[j]);
            }
            vector<int> h3, v3;
            for (int j = 0; j < h - ha.size(); j++){
              h3.push_back(hb[j]);
              v3.push_back(vb[j + (ha.size() - va.size())]);
            }
            sort(h1.begin(), h1.end());
            sort(v1.rbegin(), v1.rend());
            sort(h2.rbegin(), h2.rend());
            sort(v2.begin(), v2.end());
            sort(h3.begin(), h3.end());
            sort(v3.rbegin(), v3.rend());
            cout << "Yes" << endl;
            int x = 0, y = 0;
            for (int j = 0; j < h1.size(); j++){
              y += v1[j];
              cout << x << ' ' << y << endl;
              x += h1[j];
              cout << x << ' ' << y << endl;
            }
            for (int j = 0; j < h2.size(); j++){
              y -= v2[j];
              cout << x << ' ' << y << endl;
              x += h2[j];
              cout << x << ' ' << y << endl;
            }
            for (int j = 0; j < h3.size(); j++){
              y -= v3[j];
              cout << x << ' ' << y << endl;
              x -= h3[j];
              cout << x << ' ' << y << endl;
            }
          }
        }
      }
    }
  }
}