#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;

string s;
int main()
{
  int i ,x = 0, y;
  cin >> s;
  for (i = 0 ; i != s.size() ; i ++)
    if (isupper(s[i]))
      x ++;
  if (x == s.size() - 1 && islower(s[0]))
    for (i = 0 ; i != s.size() ; i ++)
     printf("%c",i == 0 ? toupper(s[i]) : tolower(s[i]));
  else if (x == s.size())
    for (i = 0 ; i != s.size() ; i ++)
     printf("%c",tolower(s[i]));       
  else cout << s; 
  return 0;
}