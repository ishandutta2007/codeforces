#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#define N 500005
using namespace std;
int n , m , num;
string t[N];
int sec[N];
int month[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
void convent(int x, string s)
{
     //2012-03-16 16:15:25: Disk size is
  int mn = (s[5] - '0')* 10 + (s[6] - '0');
  int dy = (s[8] - '0') * 10 + (s[9] - '0');
  int h = (s[11] - '0') * 10 + (s[12] - '0');
  int mi = (s[14] - '0') * 10 + (s[15] - '0');
  int se = (s[17] - '0') * 10 + (s[18] - '0');
  int sum = 86400 * (month[mn - 1] + dy - 1);
  sum += 3600 * h , sum += 60 * mi , sum += se;   
  sec[x] = sum;
}

int main()
{
  int i , j;
  cin >> n >> m; getline(cin, t[0]);
  for (i = 1 ; i <= 12 ;i ++)
    month[i] += month[i - 1];
  while (getline(cin, t[num]))
  {
    convent(num, t[num]); 
    num ++;
  }
  
  j = 0;
  for (i = m - 1 ;i < num ;i ++)
    if (sec[i] - sec[i - m + 1] < n)
    {
        cout << t[i].substr(0,19) << endl;
        break;    
    }
  if (i >= num)
    cout << -1 << endl;  
  return 0;    
}