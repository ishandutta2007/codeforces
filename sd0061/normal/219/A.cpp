#include <stdio.h>
#include <string.h>

int k,l,n[27];
char s[1001];
bool f;
int main()
{
  scanf("%d\n%s",&k,s);
  l = strlen(s);
  for (int i = 0 ;i < l ;i ++)  
    n[s[i] - 'a'] ++;
  for (int i = 0 ; i < 26 ;i ++)
    if (n[i] % k != 0)
      f = 1; 
  if (f == 1)
    printf("-1\n");
  else
  {
    for (int i = 1 ; i <= k ;i ++)
      for (int j = 0 ;j < 26 ;j ++)
        if (n[j])
          for (int q = 1 ; q <= n[j] / k ;q ++)
            printf("%c",'a' + j);
  }         
  return 0;
}