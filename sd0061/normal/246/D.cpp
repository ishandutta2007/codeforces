#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 100005
int n , m ,c[N] , mc , ans = -1 , sum , ansx;
vector<int> e[N], p[N];
bool f[N];

int main()
{
  int i , j , k ,  x , y;
  scanf("%d %d",&n,&m);
  for (i = 1 ;i <= n; i ++)
  {
    scanf("%d",&c[i]);
    mc = max(mc , c[i]);
    p[c[i]].push_back(i);  
  }  
  while (m --)
  {
    scanf("%d %d",&x,&y);
    e[x].push_back(y) , e[y].push_back(x);    
  }
  
  for (i = 1 ; i <= mc ;i ++)
    if (p[i].size())
    {
      sum = 0 , f[i] = 1;              
      for (j = 0 ; j < p[i].size() ;j ++)
      {
        x = p[i][j];  
        for (k = 0 ; k < e[x].size() ;k ++)
          if (!f[c[e[x][k]]])
            ++ sum , f[c[e[x][k]]] = 1;  
      }     
      for (j = 0 ; j < p[i].size() ;j ++)
      {
        x = p[i][j];  
        for (k = 0 ; k < e[x].size() ;k ++)
          f[c[e[x][k]]] = 0;  
      }
      //memset(f,0,sizeof(f));     
    //  cout << i << ' ' << sum << endl;
      f[i] = 0;         
      if (sum > ans)
        ans = sum , ansx = i;
    }
  cout << ansx << endl;  
  return 0;    
}