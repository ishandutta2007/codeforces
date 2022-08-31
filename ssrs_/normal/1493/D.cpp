#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }
  vector<int> f(200001, -1);
  for (int i = 2; i <= 200000; i++){
    if (f[i] == -1){
      for (int j = i * 2; j <= 200000; j += i){
        f[j] = i;
      }
    }
  }
  int pcnt = 0;
  vector<int> prime;
  vector<int> prime_id(200001, -1);
  for (int i = 2; i <= 200000; i++){
    if (f[i] == -1){
      prime_id[i] = pcnt;
      prime.push_back(i);
      pcnt++;
    }
  }
  vector<vector<pair<int, int>>> F(200001);
  for (int i = 2; i <= 200000; i++){
    map<int, int> mp;
    int curr = i;
    while (f[curr] != -1){
      mp[prime_id[f[curr]]]++;
      curr /= f[curr];
    }
    mp[prime_id[curr]]++;
    for (auto P : mp){
      F[i].push_back(P);
    }
  }
  vector<multiset<int>> st(pcnt);
  vector<map<int, int>> mp(n);
  for (int i = 0; i < n; i++){
    int cnt = F[a[i]].size();
    for (int j = 0; j < cnt; j++){
      st[F[a[i]][j].first].insert(F[a[i]][j].second);
      mp[i][F[a[i]][j].first] = F[a[i]][j].second;
    }
  }
  long long g = 1;
  for (int i = 0; i < pcnt; i++){
    if (st[i].size() == n){
      int mn = *st[i].begin();
      for (int j = 0; j < mn; j++){
        g *= prime[i];
        g %= MOD;
      }
    }
  }
  for (int j = 0; j < q; j++){
    int i, x;
    cin >> i >> x;
    i--;
    int cnt = F[x].size();
    for (int k = 0; k < cnt; k++){
      int prv = 0;
      if (st[F[x][k].first].size() == n){
        prv = *st[F[x][k].first].begin();
      }
      int C = 0;
      if (mp[i].count(F[x][k].first)){
        C = mp[i][F[x][k].first];
        st[F[x][k].first].erase(st[F[x][k].first].find(C));
      }
      st[F[x][k].first].insert(F[x][k].second + C);
      mp[i][F[x][k].first] = F[x][k].second + C;
      int nxt = 0;
      if (st[F[x][k].first].size() == n){
        nxt = *st[F[x][k].first].begin();
      }
      for (int l = prv; l < nxt; l++){
        g *= prime[F[x][k].first];
        g %= MOD;
      }
    }
    cout << g << "\n";
  }
}