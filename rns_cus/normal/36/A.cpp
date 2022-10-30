//A
#include<stdio.h>

char s[110];
int n, a[110], tot;

int main(){
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   scanf("%d\n", &n);
   gets(s);
   tot = 0;
   for(int i = 0; i < n; i ++){
      if(s[i] == '1') a[tot++] = i;
   }
   for(int i = 0; i < tot-2 ; i ++){
      if(a[i+1] - a[i] != a[i+2] - a[i+1]){ puts("NO"); return 0; }
   }
   puts("YES");
}