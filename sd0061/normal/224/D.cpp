#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define N 200005
string s , t;
int cnt[26][N];
int l[N] , r[N] , ls , lt;
int main()
{
  int i , j;
  cin >> s >> t;
  ls = s.size() , lt = t.size();
  j = 0;
  for (i = 1 ; i <= ls ; ++ i)
  {
    l[i] = l[i - 1];
    if (s[i - 1] == t[j] && j < lt)
      ++ l[i] , ++ j; 
  }
  j = lt - 1;
  for (i = ls ; i >= 1 ; -- i)
  {
    r[i] = r[i + 1];
    if (s[i - 1] == t[j] && j >= 0)
      ++ r[i] , -- j; 
  }
  for (i = 1 ;i <= lt ; ++ i)
    for (j = 0 ; j < 26 ; ++ j)
      if (j == t[i - 1] - 'a')
        cnt[j][i] = cnt[j][i - 1] + 1;
      else cnt[j][i] = cnt[j][i - 1];
  
  for (i = 1 ;i <= ls ;++ i)
    if ((cnt[s[i - 1] - 'a'][l[i]] - cnt[s[i - 1] - 'a'][lt - r[i]]) <= 0)
    {
      cout << "No" << endl;       
      return 0;       
    }
  cout << "Yes" << endl;  
  return 0;
}