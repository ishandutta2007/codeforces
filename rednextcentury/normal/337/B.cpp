# include <iostream>
# include <cmath>
# include <iomanip>
# include <algorithm>
# include <map>
# include <vector>
# include <queue>
# include <stack>
using namespace std;
int a[1000];
int main()
{
    long down=0;
    long up=0;
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  if (double(a)/double(b)>double(c)/double(d))
  {
        down=a*d;
        up=b*c;
  }
  else
  {
        down=b*c;
        up=a*d;
  }
  up=down-up;
  for (int i=up;i>=1;i--)
  {
    if (up%i==0 && down%i==0)
    {
        up/=i;
        down/=i;
        break;
    }
  }
  if (up==0)
      cout<<0<<"/"<<1<<endl;
  else
  cout<<up<<"/"<<down<<endl;
}