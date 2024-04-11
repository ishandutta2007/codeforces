#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int main()
{
   ll k;
   cin >> k;
   vector <ll> ara;
   for(int i=0; i<10; i++) ara.push_back(1);
   ll tot = 1;

   int i=0;
   while(tot < k) {
      tot /= ara[i];
      ara[i]++;
      tot *= ara[i];
      i++;
      if(i == 10) i = 0;
   }

   string s = "codeforces";
   for(int i=0; i<10; i++) {
      while(ara[i]--) printf("%c", s[i]);
   }
}