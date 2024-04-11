#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int id[sz];
string s[sz];

bool cmp(int x, int y) {
   for(int i=0; i<s[x].size(); i++) {
      if(s[x][i] != s[y][i]) {
         if(i & 1) return s[x][i] > s[y][i];
         else return s[x][i] < s[y][i];
      }
   }
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int n, m;
   cin >> n >> m;
   for(int i=0; i<n; i++) cin >> s[i];
   iota(id, id+n, 0);
   sort(id, id+n, cmp);
   for(int i=0; i<n; i++) printf("%d ", id[i] + 1);
}