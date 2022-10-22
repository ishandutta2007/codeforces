#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;char s[105];
int main()
{
  int i;  
  scanf("%s",s);
  for (i = 0 ;i < strlen(s) ;i ++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z') 
      s[i] += 'a' - 'A';
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') 
      continue;
    else printf(".%c",s[i]);    
  }
  return 0;
}