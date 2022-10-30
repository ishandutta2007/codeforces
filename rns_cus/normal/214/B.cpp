#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, sum, a[N];
bool fg, vis[N], OK;
vector <int> v;

int main(){
   
   scanf("%d", &n);
   for(int i = 0; i < n; i ++){
      scanf("%d", a + i); sum += a[i];
   }
   
   sort(a, a + n);

   if(a[0] != 0){ puts("-1"); return 0; }///

   sum %= 3;
   if(!sum){
      if( !a[n-1] ){ puts("0"); return 0; }
      for(int i = n; i --; ){
         printf("%d", a[i]);
      } puts(""); return 0;
   }
   
   fg = 0;
   for(int i = 1; i < n; i ++){
      if(a[i] % 3 == sum){ vis[i] = 1; fg = 1; break; }
   }
   if(fg){
      OK = 0;
      for(int i = n; i --; ){
         if(vis[i]) continue;
         if(a[i] == 0 && OK == 0){ puts("0"); return 0; }
         printf("%d", a[i]);
         OK = 1;
      } puts(""); return 0;
   }

   v.clear();
   for(int i = 1; i < n; i ++) if(a[i] % 3) v.push_back(i);
   vis[v[0]] = 1; vis[v[1]] = 1;
   
   OK = 0; 
   for(int i = n; i --; ){
      if(vis[i]) continue;
      if(a[i] == 0 && OK == 0) { puts("0"); return 0;}
      printf("%d", a[i]);
      OK = 1;
   } puts(""); return 0;

}