#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
#define N 5005
int n , m;
string s , name[N << 1];
map<string,int> hash;
vector<int> e[N << 1];
bool f[N << 1];

int main()
{
  cin >> m;
  int i ,j , k , x ,y;
  while (m --)
  {
    cin >> s;
    if (!hash.count(s))
      name[n] = s , hash[s] = n ++ ;    
    x = hash[s];
    cin >> s;
    if (!hash.count(s))
      name[n] = s , hash[s] = n ++ ;    
    y = hash[s];
    e[x].push_back(y) , e[y].push_back(x);
  }
  cout << n << endl;
  for (i = 0 ;i < n ;i ++)
  {
    int cnt = 0 , ans = 0;  
    memset(f,0,sizeof(f));
    for (j = 0 ;j < e[i].size() ;j ++)
      f[e[i][j]] = 1;
    f[i] = 1;
    for (j = 0 ;j < n ;j ++)
      if (!f[j])
      {
        int sum = 0;        
        for (k = 0 ; k < e[j].size() ; k ++)
          if (f[e[j][k]])
            sum ++;
        if (sum > cnt)
          cnt = sum , ans = 1;
        else if (sum == cnt)
          ans ++;             
      }
    cout << name[i] << ' ' << ans << endl;  
  }
  return 0;    
}