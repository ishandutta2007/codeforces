#include <iostream> 

using namespace std;

int abs(int a)
{
  if (a >= 0) return a;
  return -a;
} 
int main()    
{
    int a, b;
    cin >> a >> b;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 1; i <= 6; ++i) 
    {
      int v = abs(a - i) - abs(b - i);
      if (v > 0) ++c2;
      else if (v < 0) ++c1;
      else ++c3;
    }
    cout << c1 << ' ' << c3 << ' ' << c2 << endl;
}