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
   int n,m;
   cin>>n>>m;
   for (int i=0;i<m;i++)
       cin>>a[i];
   sort(a,a+m);
   int min=1000000;
   for (int i=n-1;i<m;i++)
   {
       if (a[i]-a[i-(n-1)]<min)
           min=a[i]-a[i-(n-1)];
   }
   cout<<min<<endl;
}