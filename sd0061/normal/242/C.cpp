#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <utility>
using namespace std;
#define N 100005
pair<int , int>  point;
map<pair<int , int> , int> g , s;
int n , X0 ,X1 , Y0 , Y1;

int BFS()
{
  s.clear();
  queue<pair<int ,int> > q;
  q.push(make_pair(X0 , Y0));
  g[make_pair(X0 ,Y0)] = 0;
  while(!q.empty())
  {
    int xx = q.front().first;
    int yy = q.front().second;
    q.pop();
    for (int i = -1 ; i <= 1 ; i ++ )
      for (int j = -1 ; j <= 1 ;j ++)
      {
        if (!i && !j) continue;
        pair<int ,int> next = make_pair(xx + i , yy + j);
        if (!g.count(next) || s.count(next)) 
          continue;
        q.push(next);
        s[next] = s[make_pair(xx,yy)] + 1;
        if (next.first == X1 && next.second == Y1)
          return s[next];   
      }
  }
  return -1;     
}

int main()
{
  cin >> X0 >> Y0 >> X1 >> Y1 >> n;
  while (n --)
  {
    int r , a ,b;
    cin >> r >> a >> b;
    for (int i = a ; i <= b ;i ++)
      g[make_pair(r,i)] ++;   
  }
  printf("%d\n",BFS());      
  return 0;    
}