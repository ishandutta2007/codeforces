#include<bits/stdc++.h>
using namespace std;

int x, sum, n, cnt;

int main(){
   scanf("%d", &n);
   for(int i = 0; i < n; i ++){ scanf("%d", &x); sum += x; }
   for(int i = 1; i <= 5; i ++){
      if((sum + i) % (n + 1) != 1) cnt ++;
   }
   printf("%d\n", cnt);
}