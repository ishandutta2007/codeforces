#include<bits/stdc++.h>
using namespace std;

int vis[110], p[100], cnt, tot;
char s[100];

void get_prime(){
   for(int i = 2; i <= 100; i ++){
      if(vis[i]) continue;
      p[cnt ++ ] = i;
      for(int j = i * i; j <= 100; j += i) vis[j] = 1;
   }
}

int main(){
   get_prime();

   for(int i = 0; p[i] < 50; i ++){
      printf("%d\n", p[i]);
      fflush(stdout);
      gets(s);
      if(s[0] == 'y') tot ++;
      if(p[i] < 10){
         printf("%d\n", p[i] * p[i]);
         fflush(stdout);
         gets(s);
         if(s[0] == 'y') tot ++;
      }
   }
   if(tot >= 2){ puts("composite"); fflush(stdout); return 0; }
   else { puts("prime"); fflush(stdout); return 0; }
}