#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 100005
int n , m;
vector<int> g[5005];
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout); 
  int i , j, x , y;
  scanf("%d",&n);
  for (i = 1  ;i <= n << 1 ; i ++)
    scanf("%d",&x) , g[x].push_back(i);
  for (i = 1 ; i <= 5000 ;i ++)
    if (g[i].size() & 1)
    {
        printf("-1");
        return 0;
    }
  for (i = 1 ; i <= 5000 ;i ++)
    for (j = 0 ;j < g[i].size() ; j += 2)
      printf("%d %d\n",g[i][j] , g[i][j + 1]);  
  return 0;    
}