#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define N 2005
#define ULL unsigned long long
char s[N] , b[N] , e[N];
int n , lb , le , fb[N] , fe[N];
ULL h[N] , power[N];
ULL hash[N * N] ; int sum;
void getFail(char *P , int* f)
{
  int m = strlen(P);
  f[0] = f[1] = 0;
  for (int i = 1 ; i < m ;i ++)
  {
    int j = f[i];
    while (j && P[i] != P[j]) j = f[j];
    f[i + 1] = P[i] == P[j] ? j + 1 : 0;
  }
}

int main()
{
   int i , j; ULL x;
   scanf("%s%s%s",s , b , e);
   n = strlen(s) , lb = strlen(b) , le = strlen(e);
   getFail(b , fb) , getFail(e , fe);
   h[0] = s[0] - '0' + 1 , power[0] = 1;
   for (i = 1 ; i < n ; ++ i)
     h[i] = h[i - 1] * 29 + s[i] - 'a' + 1 , power[i] = power[i - 1] * 29;
   vector<int> p , q;
   for (int i = 0 ,j = 0 ; i < n ;i ++) {
      while (j && s[i] != b[j]) j = fb[j];
      if (s[i] == b[j]) ++ j;
      if (j == lb) p.push_back(i - lb + 1);
   }
   for (int i = 0 ,j = 0 ; i < n ;i ++) {
      while (j && s[i] != e[j]) j = fe[j];
      if (s[i] == e[j]) ++ j;
      if (j == le) q.push_back(i);
   }
   //map<ULL , int> hash;
   for (i = 0 ; i < p.size() ; ++ i)
     for (j = 0 ; j < q.size() ; ++ j) if (q[j] - p[i] + 1 >= max(lb,le))
       hash[sum ++] = h[q[j]] - h[p[i]] * power[q[j] - p[i]];
   sort(hash , hash + sum);
   cout << unique(hash , hash + sum) - hash << endl;
   return 0;
}