#include <bits/stdc++.h>
using namespace std;

int main(){
  int s[10],i,sum = 0;
  int res = 0;
  for (i = 0;i < 5;i++){
    scanf("%d",&s[i]);
    res += s[i];
  }
  sum = res;
  sort(s, s + 5);

  for(int i = 0; i < 4; i++){
    if(s[i] == s[i + 1]){
        res = min(res, sum - 2 * s[i]);
    }
    if(i < 3 && s[i] == s[i + 1] && s[i] == s[i + 2]){
      res = min(res, sum - 3 * s[i]);
    }
  }
  printf("%d\n", res);
}