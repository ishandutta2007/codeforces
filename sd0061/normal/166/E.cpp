#include <iostream>
using namespace std;
const int Q = 1000000007;
int n ,x ,y ,a ,b;

int main()
{
  cin >> n;
  a = 0 , b = 1;
  for (int i = 1 ; i <= n ;i ++)  
  {
    x = ((a + a) % Q + b) % Q, y = ((a + a) % Q + a) % Q;
    a = x , b = y;  
  }
  cout << b;
  return 0;
}