#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
string s;
int main()
{
  cin >> s;
  int i = 0 , f = 0 , j;
  if (s[0] == 'f')
    printf("ftp://"), i += 3 ;
  else printf("http://") , i += 4;
  int l = s.size();  
  j = i;
  for (; i < l ; i ++)
  {
    if (j != i && !f && s[i] == 'r' && s[i + 1] == 'u')
    {
      f = 1 , i += 2 , printf(".ru");
      if (i < l)
        printf("/");
    }
    if (i < l)
    printf("%c",s[i]);    
  }  
  return 0;    
}