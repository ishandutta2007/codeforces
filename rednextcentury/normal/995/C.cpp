#include <bits/stdc++.h>
using namespace std;
pair<int,pair<int,int> > a[1000000];
int vec[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second.first,a[i].second.second=i;
    for (int j=0;j<50;j++)
    {
        random_shuffle(a,a+n);
        long long X=0,Y=0;
        for (int i=0;i<n;i++)
        {
            long long x=a[i].first;
            long long y=a[i].second.first;
            long long x1=X-x,y1=Y-y,x2=X+x,y2=Y+y;
            if (x1*x1+y1*y1 < x2*x2+y2*y2)
            {
                X=x1,Y=y1;
                vec[a[i].second.second]=-1;
            }
            else
            {
                X=x2,Y=y2;
                vec[a[i].second.second]=1;
            }
        }
        if (X*X+Y*Y <= 2000000000000LL)
        {
            for (int i=0;i<n;i++)
                cout<<vec[i]<<' ';
            return 0;
        }
    }
}