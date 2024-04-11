#include <bits/stdc++.h>

using namespace std;

int main(){
  int y,b,r;
  scanf("%d%d%d",&y,&b,&r);
  int x = min(y,min(b-1,r-2));
  int ans = x + (x+1) + (x+2);
  printf("%d\n",ans);
  return 0;
}