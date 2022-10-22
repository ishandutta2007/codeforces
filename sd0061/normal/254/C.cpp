#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#define N 25005
using namespace std;
string s , t;
int a[26] , b[26] , ans;
int main()
{
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  int i , j , x ,y;
  cin >> s >> t;
  for (i = 0 ; i < s.size() ;i ++)
    a[s[i] - 'A'] ++;
  for (i = 0 ; i < t.size() ;i ++)
    b[t[i] - 'A'] ++;
  for (i = 0 ;i < 26 ;i ++)
    ans += abs(a[i] - b[i]); ans >>= 1;
  cout << ans << endl;
  for(i = 0 ; i < s.size() ; i++)
  {
    x = s[i] - 'A';
    if(a[x] > b[x])
    {
      for(j = 0 ; j < 26 ;j ++)
        if(a[j] < b[j])
        {
          if(j < x || !b[x])
            s[i] = j + 'A' , b[j] --;
          else
            b[x] --;
          break;
        }
      a[x] --;
    }
  } 
  cout << s;
  return 0;
}