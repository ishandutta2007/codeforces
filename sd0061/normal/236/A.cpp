#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
bool f[2000];
string s;
int main()
{
  cin >> s;
  int l = s.size() , i , ans = 0;
  for (i = 0 ;i < l ;i ++)
    if (!f[s[i]])
      f[s[i]] = 1 , ans ++;
  if (ans & 1)
    cout << "IGNORE HIM!";    
  else cout << "CHAT WITH HER!" ; 
  return 0;  
}