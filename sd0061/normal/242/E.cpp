#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
#define M 20
#define LL long long

#define MID int mid = (L + R) >> 1
struct stree
{
  int x , s;     
} t[M][N << 2];
int n , q , a[N];

void Buildtree(int p ,int top, int bot)
{
  if (top < bot)
  {
    int mid = (top + bot) >> 1;      
    Buildtree(p << 1 , top , mid);
    Buildtree(p << 1 | 1, mid + 1 , bot);      
    for (int i = 0 ;i < M ;i ++)
      t[i][p].s = t[i][p << 1].s + t[i][p << 1 | 1].s;
    return;
  }   
  for (int i = 0 ;i < M ;i ++)
    t[i][p].s = (1 << i) & a[top] ? 1 : 0;
}

void Pushdown(int m , int p ,int L ,int R)
{
  if (t[m][p].x && L != R)
  {
    t[m][p << 1].x ^= 1 , t[m][p << 1 | 1].x ^= 1;MID;
    t[m][p << 1].s = mid - L + 1 - t[m][p << 1].s;
    t[m][p << 1 | 1].s = R - mid - t[m][p << 1 | 1].s;
    t[m][p].x = 0;             
  }   
}
void Pushup(int m , int p ,int L ,int R)
{
  if (L != R)   
    t[m][p].s = t[m][p << 1].s + t[m][p << 1 | 1].s; 
}

void Xor(int m , int p, int L , int R , int top, int bot)
{
  if (top <= L && bot >= R)
  {
    t[m][p].x ^= 1;
    t[m][p].s = R - L + 1 - t[m][p].s;    
    return;  
  }  
  MID ; Pushdown(m , p , L , R);
  if (top <= mid)
    Xor(m , p << 1 , L , mid , top , bot);
  if (bot > mid)
    Xor(m , p << 1 | 1, mid + 1 , R , top , bot);
  Pushup(m ,p , L , R);
}

int Query(int m , int p, int L , int R , int top, int bot)
{
  if (top <= L && bot >= R)
    return t[m][p].s; 
  MID ; Pushdown(m , p , L , R);
  int ans = 0;
  if (top <= mid)
    ans += Query(m , p << 1 , L , mid , top , bot);
  if (bot > mid)
    ans += Query(m , p << 1 | 1, mid + 1 , R , top , bot);
  Pushup(m ,p , L , R);
  return ans;
}

int main()
{
  int i ,  x , y , z;  
  scanf("%d",&n);
  for (i = 1 ;i <= n ;i ++)
    scanf("%d",&a[i]);
  Buildtree(1,1,n);    
  scanf("%d",&q);
  while (q --)
  {
    scanf("%d",&i);
    if (i == 1)
    {
      scanf("%d %d",&x,&y);
      LL sum = 0;
      for (int j = M - 1 ; j >= 0 ; j --)
        sum <<= 1 , sum += Query(j , 1 , 1 , n , x , y);
      cout << sum << endl;      
    }    
    
    if (i == 2)
    {
      scanf("%d %d %d",&x,&y,&z);
      for (int j = 0 ; j < M ; j ++)
        if (z & (1 << j)) 
          Xor(j , 1 , 1 , n , x , y);
    }    
  }
  return 0;
}