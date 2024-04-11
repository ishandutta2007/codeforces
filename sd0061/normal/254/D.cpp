#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#define N 1005

#define MP make_pair
#define PB push_back
using namespace std;
int n , m , d , sum , tot;
char s[N][N];
int dx[4] = {0 , 0, 1 , -1} , dy[4] = {1,-1, 0 ,0};
int u[N][N] , v[N][N] , f[N][N];
bool q;
vector<pair<int,int> >  w , t , r;
queue<pair<int ,int > > Q;

void bfs(int x , int y , bool test)
{
  Q.push(MP(x,y)); u[x][y] = 1;
  while (!Q.empty())
  {
    pair<int ,int> a = Q.front() ; Q.pop();
    x = a.first , y = a.second;
    if (s[x][y] == 'R')
      sum ++;
    if (test)
      w.PB(MP(x,y));
    for (int i = 0 ;i < 4 ;i ++)
      if (u[x][y] != d + 1 && s[x + dx[i]][y + dy[i]] != 'X' && !u[x + dx[i]][y + dy[i]])
        u[x + dx[i]][y + dy[i]] = u[x][y] + 1 , Q.push(MP(x + dx[i], y + dy[i]));
  }
}

void bfs2(int x , int y)
{
  Q.push(MP(x,y)); v[x][y] = 1;
  while (!Q.empty())
  {
    pair<int ,int> a = Q.front() ; Q.pop();
    x = a.first , y = a.second;
    r.PB(MP(x,y));
    for (int i = 0 ;i < 4 ;i ++)
      if (v[x][y] != d + 1 && s[x + dx[i]][y + dy[i]] != 'X' && !v[x + dx[i]][y + dy[i]])
        v[x + dx[i]][y + dy[i]] = v[x][y] + 1 , Q.push(MP(x + dx[i], y + dy[i]));
  }
}

void bfs3(int x , int y)
{
  Q.push(MP(x,y)); f[x][y] = 1;
  while (!Q.empty())
  {
    pair<int ,int> a = Q.front() ; Q.pop();
    x = a.first , y = a.second;
    if (!u[x][y] && s[x][y] == 'R')
      sum ++;
    t.PB(MP(x,y));
    for (int i = 0 ;i < 4 ;i ++)
      if (f[x][y] != d + 1 && s[x + dx[i]][y + dy[i]] != 'X' && !f[x + dx[i]][y + dy[i]])
        f[x + dx[i]][y + dy[i]] = f[x][y] + 1 , Q.push(MP(x + dx[i], y + dy[i]));
  }
}

int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , j , k , l ,x , y;
  scanf("%d %d %d\n",&n,&m,&d);
  for (i = 1 ; i <= n; i ++)
    scanf("%s\n",s[i] + 1);
  for (i = 2 ; i < n ;i ++)
    for (j = 2 ;j < m ;j ++)
      if (s[i][j] == 'R')
        x = i , y = j , tot ++;

  bfs(x, y ,  1);

  for (i = 0 ;i < w.size() ; ++ i)
  {
    memset(u , 0  , sizeof(u));

    sum = 0 , q = 0;
    bfs(w[i].first , w[i].second , 0);


  /*  for (j = 1 ;j <= n ;j ++)
    {
        for (k = 1 ;k <= m ;k ++)
          if (s[j][k] == 'X')
            printf("X");
           else if (s[j][k] == 'R' && u[j][k])
             printf("r");
           else if (s[j][k] == 'R' && !u[j][k])
           printf("R");
            else if (u[j][k])
            printf("O");
            else printf(".");
            printf("\n");
    }*/


    if (sum == tot)
    {
      for (j = 2 ; j < n ; j ++)
      {
        for (k = 2 ; k < m ;k ++)
          if (s[j][k] != 'X')
          {
            q = 1;
            break;
          }
        if (q) break;
      }
      printf("%d %d %d %d\n", w[i].first , w[i].second , j , k);
      return 0;
    }

    for (j = 2 ; j < n ; j ++)
    {
      for (k = 2 ; k < m ;k ++)
        if (!u[j][k] && s[j][k] == 'R')
        {
          q = 1;
          break;
        }
      if (q) break;
    }

    r.clear();
    memset(v , 0 , sizeof(v));
    bfs2(j , k );

    for (j = 0 ;j < r.size() ;j ++)
    {
      k = r[j].first , l = r[j].second;
      x = sum;
      bfs3(k , l);
      if (tot == sum)
      {
        printf("%d %d %d %d\n", w[i].first , w[i].second , k , l);
        return 0;
      }
      sum = x;
      for (k = 0 ;k < t.size() ; k ++)
        f[t[k].first][t[k].second] = 0;
      t.clear();

    }

  }
  printf("-1");
  return 0;
}