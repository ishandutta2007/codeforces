#include <iostream>
#include <string>
#include <cstdlib> 
#include <cmath>
using namespace std;

int main() 
{
  string s;
  cin >> s;
  int pos = -1;
  for (int i = 0; i < s.size(); ++i)
  {
    if (s[i] == '^')  pos = i;
  }  
  long long sum1 = 0;
  long long sum2 = 0;
  for (int i = pos; i < s.size(); ++i) 
  {
    if ('1' <= s[i] && s[i] <= '9') 
      sum1 += (s[i] - '0') * (i - pos);
  }
  for (int i = pos; i >= 0; --i)
  {
    if ('1' <= s[i] && s[i] <= '9')
      sum2 += (s[i] - '0') * abs(i - pos); 
  } 
  if (sum1 > sum2) cout << "right";
  else if (sum2 > sum1) cout << "left";
  else cout << "balance";
}