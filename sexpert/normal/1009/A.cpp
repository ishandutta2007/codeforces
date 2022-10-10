#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n, m, count = 0;
   vector<int> a, c;
   cin >> n >> m;
   for(int i = 0; i < n; i++){
       int x;
       cin >> x;
       c.push_back(x);
   }
   for(int i = 0; i < m; i++){
       int x;
       cin >> x;
       a.push_back(x);
   }
   for(int i = 0; i < n; i++){
       if(a.empty()) break;
       if(a[0] >= c[0]){
           a.erase(a.begin());
           count++;
       }
       c.erase(c.begin());
   }
   cout << count;
}