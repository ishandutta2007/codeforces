#include<bits/stdc++.h>
using namespace std;

multiset <int> S;
multiset <int> :: iterator it;

char ss[5];
int cur, n, mid;

bool OK(int st, int en){
   if(S.lower_bound(st) == S.end()) return 0;
   return *S.lower_bound(st) < en;
}

int main(){
  // freopen("a.in", "r", stdin);
   S.clear();
   S.insert(0);
   scanf("%d", &n);
   for(int i = 0; i < n; i ++){
      scanf("%s %d", ss, &cur);
      if(ss[0] == '+') S.insert(cur);
      else if(ss[0] == '-'){ S.erase( S.find(cur) ); }
      else{
         int low = 0;
         int high = (1 << 30);
         int b = 29;
         while(high > low + 1){
            mid = (low + high) >> 1;
            if((cur & (1 << b))){
               if(OK(low, mid)) high = mid;
               else low = mid;
            }
            else{
               if(OK(mid, high)) low = mid;
               else high = mid;
            }
            b --;
         }
         printf("%d\n", (low ^ cur));
      }
   }
}