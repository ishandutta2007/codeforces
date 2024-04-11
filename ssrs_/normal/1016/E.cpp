#include <bits/stdc++.h>
using namespace std;
long long INF = 5000000000000000000;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(15);
  long long sy, a, b;
  cin >> sy >> a >> b;
  int n;
  cin >> n;
  vector<pair<long long, long long>> F(n);
  for (int i = 0; i < n; i++){
    long long l, r;
    cin >> l >> r;
    F[i] = make_pair(l, r);
  }
  sort(F.begin(), F.end());
  map<double, int> M;
  M[-INF] = 0;
  long long sum = 0;
  for (int i = 0; i < n; i++){
    M[F[i].first] = sum;
    sum += F[i].second - F[i].first;
    M[F[i].second] = sum;
  }
  M[INF] = sum;
  /*
  for (auto P : M){
      cout << P.first << ' ' << P.second << endl;
  }
  */
  int q;
  cin >> q;
  for (int i = 0; i < q; i++){
    long long x, y;
    cin >> x >> y;
    double t = (double) y / (y - sy);
    double L = x + (a - x) * t;
    double R = x + (b - x) * t;
    //cout << L << ' ' << R << endl;
    //check for range (L, R)
    double X;
    auto itr1 = M.lower_bound(L);
    auto itr2 = itr1;
    itr2--;
    if ((*itr1).second == (*itr2).second){
      X = (*itr2).second;
    } else {
      X = (*itr2).second + L - (*itr2).first;
    }
    double Y;
    auto itr3 = M.lower_bound(R);
    auto itr4 = itr3;
    itr4--;
    if ((*itr3).second == (*itr4).second){
      Y = (*itr4).second;
    } else {
      Y = (*itr4).second + R - (*itr4).first;
    }
    //cout << X << ' ' << Y << endl;
    cout << (Y - X) / t << "\n";
  }
}