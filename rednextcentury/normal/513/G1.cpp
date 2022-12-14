# include <iostream>
# include <algorithm>
# include <iomanip>
# include <cmath>
using namespace std;
long double a[10];
long double sum[100];
   long double y=0;
long double m;
long double n;
long double solve(long double k)
{
    if (k==m)
    {
        y++;
        int now=0;
        for (int i=1;i<n;i++)
        {
            for (int j=i-1;j>=0;j--)
            {
                if (a[j]>a[i])
                    now++;
            }
        }
        sum[now]++;
    }
    else
    {
        for (long  i=0;i<n;i++)
        {
            for (long  j=i;j<n;j++)
            {
                reverse(a+i,a+j+1);
                solve(k+1);
                reverse(a+i,a+j+1);
            }
        }
    }
}
int main()
{
   cin>>n>>m;
   for (long i=0;i<n;i++)
        cin>>a[i];
   solve(0);
   long double x=0;
   for (long i=0;i<100;i++)
   {
       x+=sum[i]*i;
   }
   cout<<setprecision(15)<<x/(y)<<endl;;
}