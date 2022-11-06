#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

typedef pair <int, int> pii;
#define x first
#define y second

vector <pii> ans;

void fnc(pii a, pii b)
{
//   printf("%d %d %d %d\n", a.x, a.y, b.x, b.y);
   ans.push_back(a);
   if(!a.y) {
      while(a.y > b.y) {
         a.y--;
         ans.push_back(a);
      }
      while(a.y < b.y) {
         a.y++;
         ans.push_back(a);
      }
      while(a.x < b.x) {
         a.x++;
         ans.push_back(a);
      }
      while(a.x > b.x) {
         a.x--;
         ans.push_back(a);
      }
   }
   else {
      while(a.x < b.x) {
         a.x++;
         ans.push_back(a);
      }
      while(a.x > b.x) {
         a.x--;
         ans.push_back(a);
      }
      while(a.y > b.y) {
         a.y--;
         ans.push_back(a);
      }
      while(a.y < b.y) {
         a.y++;
         ans.push_back(a);
      }
   }
}

bool s[5][35];

int main()
{
   int n;
   cin >> n;

   vector <int> d;
   int j=1;
   for(int i=0; i<n; i++) {
      ans.emplace_back(j++, 0);
      ans.emplace_back(j, +1);
      ans.emplace_back(j, -1);
      d.push_back(j);
      ans.emplace_back(j++, 0);
      ans.emplace_back(j++, 0);
   }

   vector <pii> dd;
   dd.emplace_back(0, 0);
   for(int x : d) dd.emplace_back(x, -2);
   dd.emplace_back(j, 0);
   reverse(d.begin(), d.end());
   for(int x : d) dd.emplace_back(x, +2);

   for(int i=0; i<dd.size(); i+=2) {
      fnc(dd[i], dd[i+1]);
   }

   printf("%d\n", ans.size());
//   sort(ans.begin(), ans.end());
   for(auto p : ans) printf("%d %d\n", p.x, p.y);

//
//   for(auto p : ans) s[p.y+2][p.x+2] = 1;
//
//   for(int i=0; i<5; i++) {
//      for(int j=0; j<35; j++) {
//         if(s[i][j]) printf("*");
//         else printf(".");
//      }
//      puts("");
//   }
}