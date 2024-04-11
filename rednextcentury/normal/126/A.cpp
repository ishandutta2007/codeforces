#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long double t1,t2,x1,x2,t;
long double ans=10000000.0;
long long cold=0,hot=0;
long double binsearch(int s,int e,long double sum)
{
    while(s<=e)
    {
        long double mid=(s+e)/2;
        if (sum-mid>x2)
        {
            s=mid+1;
        }
        else if (((mid*t1+(sum-mid)*t2)/sum)<t)
            e=mid-1;
        else
        {
            if (((mid*t1+(sum-mid)*t2)/sum)<=ans)
            {
                ans=((mid*t1+(sum-mid)*t2)/sum);
                cold=mid;
                hot=sum-mid;
            }
            s=mid+1;
        }
    }
    return ans;
}
int main() {
    cin>>t1>>t2>>x1>>x2>>t;
    long double x;
    for (int i=0;i<=x1+x2;i++)
    {
        x=binsearch(0,x1,i);
    }
    cout<<cold<<" "<<hot<<endl;
    return 0;
}