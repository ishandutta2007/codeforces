#include <stdio.h>
#include <string.h>

char ts[1<<20], s[1<<20];
int ans[1<<20];

int main()
{
  int i, n;
  int cnt;
  scanf("%s", ts);
  n = strlen(ts);
  for(i = 0; i < n; i++)
    s[i] = ts[n-i-1];
  cnt = 0;
  s[n] = '0';
  for(i = 0; i <= n; i++)
  {
    if(s[i] == '2')
    {
      s[i+1]++;
    }
    else if(s[i] == '1')
    {
      if(s[i+1] == '1')
      {
        s[i+1]++;
        ans[cnt++] = ~i;
      }
      else
        ans[cnt++] = i;
    }
  }
  printf("%d\n", cnt);
  for(i = 0; i < cnt; i++)
  {
    if(ans[i] < 0)
      printf("-2^%d\n", ~ans[i]);
    else
      printf("+2^%d\n", ans[i]);
  }
  //scanf("%d", &i);
  return 0;
}