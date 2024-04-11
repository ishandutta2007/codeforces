#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

ll a[sz], ans, now;
vector <pair<int,int>> gmx[64], gmn[64];
int mn, mx, bt[sz], mnstk[sz], mxstk[sz];
vector <int> mncum[64], mxcum[64];

int mxfnc(int b, int l, int r) {
   auto &vec = gmx[b];
   int x = lower_bound(vec.begin(), vec.end(), make_pair(l, -1)) - vec.begin();
   int y = lower_bound(vec.begin(), vec.end(), make_pair(r + 1, -1)) - vec.begin();

   y--;
   int res = 0;
   if(y > x) res += mxcum[b][y+1] - mxcum[b][x+1];
   if(x >= 0 and x < vec.size()) {
      auto [hr, hl] = vec[x];
      hl = hr - hl + 1;
      res += max(0, min(hr, r) - max(hl, l) + 1);
   }
   y++;
   if(y > x and y < vec.size()) {
      auto [hr, hl] = vec[y];
      hl = hr - hl + 1;
      res += max(0, min(hr, r) - max(hl, l) + 1);
   }
   return res;
}

int mnfnc(int b, int l, int r) {
   auto &vec = gmn[b];
   int x = lower_bound(vec.begin(), vec.end(), make_pair(l, -1)) - vec.begin();
   int y = lower_bound(vec.begin(), vec.end(), make_pair(r + 1, -1)) - vec.begin();

   y--;
   int res = 0;
   if(y > x) res += mncum[b][y+1] - mncum[b][x+1];
   if(x >= 0 and x < vec.size()) {
      auto [hr, hl] = vec[x];
      hl = hr - hl + 1;
      res += max(0, min(hr, r) - max(hl, l) + 1);
   }
   y++;
   if(y > x and y < vec.size()) {
      auto [hr, hl] = vec[y];
      hl = hr - hl + 1;
      res += max(0, min(hr, r) - max(hl, l) + 1);
   }
   return res;
}

int main() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) 
      scanf("%lld", &a[i]), bt[i] = __builtin_popcountll(a[i]);

   int fml[64] = {};
   for(int i=1; i<=n; i++) fml[bt[i]]++;
   for(int i=0; i<64; i++) {
      mncum[i].resize(fml[i] + 10, 0);
      mxcum[i].resize(fml[i] + 10, 0);
   }

   for(int i=1; i<=n; i++) {
      while(mn and a[mnstk[mn]] >= a[i]) {
         int j = bt[mnstk[mn]];
         auto [r, l] = gmn[j].back();
         now -= mxfnc(j, r - l + 1, r);
         gmn[j].pop_back();
         mn--;
      }
      gmn[bt[i]].emplace_back(i, mn ? i - mnstk[mn] : i);
      {
         int j = bt[i];
         auto [r, l] = gmn[j].back();
         now += mxfnc(j, r - l + 1, r);

         int e = gmn[j].size();
         mncum[j][e] = mncum[j][e - 1] + l;
      }
      mnstk[++mn] = i;

      while(mx and a[mxstk[mx]] <= a[i]) {
         int j = bt[mxstk[mx]];
         auto [r, l] = gmx[j].back();
         now -= mnfnc(j, r - l + 1, r);
         gmx[j].pop_back();
         mx--;
      }
      gmx[bt[i]].emplace_back(i, mx ? i - mxstk[mx] : i);
      mxstk[++mx] = i;
      {
         int j = bt[i];
         auto [r, l] = gmx[j].back();
         now += mnfnc(j, r - l + 1, r);

         int e = gmx[j].size();
         mxcum[j][e] = mxcum[j][e - 1] + l;
      }
      ans += now;
   }
   cout << ans;
}