#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int p[1010], a, ans, cnt;
char s[10000];
bool sign[1010], type[1010], vis[1010];
int main(){
   scanf("%d %s", &a, s);
   int len = strlen(s);
   for(int cur = 0; cur < len;){
      if(s[cur] > 47 and s[cur] < 58){ p[cnt] = p[cnt] * 10 + s[cur] - 48; cur ++; vis[cnt] = 1; continue; }
      if(s[cur] == '*') { cur++; continue; }
      if(s[cur] == '-') { sign[cnt] = 1; cur ++; continue; }
      if(s[cur] == 'a') { cnt ++; cur += 3; continue; }
      if(cur + 2 < len and s[cur + 1] == '+' and s[cur + 2] == 'a'){ type[cnt++] = 1; cur += 3; continue; }
      cur ++;
   }
   for(int i = 0; i < cnt; i ++){
      if(vis[i] == 0) p[i] = 1; if(sign[i]) p[i] = - p[i];
      ans += type[i] * p[i];
   }
   sort(p, p + cnt);
   for(int i = 0; i < cnt; i ++) ans += p[i] * (a + i);
   printf("%d\n", ans);
}