#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;char s[105];
int main()
{
  int i ,j , ans;  
  scanf("%d\n",&n);
  for (i = 1 ; i <= n ;i ++)
  {
    scanf("%s",s);
    if (strlen(s) <= 10)
      puts(s);
    else
      printf("%c%d%c\n",s[0],strlen(s) - 2 , s[strlen(s) - 1]);    
  }
  return 0;
}