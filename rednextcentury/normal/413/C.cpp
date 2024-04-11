# include <iostream>
# include <stdio.h>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <map>
# include <iomanip>
# include <string>
# include <ios>
# include <queue>
# include <algorithm>
using namespace std;
struct ques
{
    long long a;
    long long b;
};
ques a[1000];
bool comp(ques a,ques b)
{
    return a.a<b.a;
}
int main()
{
    long long n,m;
    cin>>n>>m;
    long long sum=0; 
    int most=0;
    for (long long i=0;i<n;i++)
    {
        cin>>a[i].a;
        sum+=a[i].a;
    }
    int h;
    for (long long i=0;i<m;i++)
    {   
        long long idx;
        cin>>idx;
        a[idx-1].b=1;
        sum-=a[idx-1].a;
        if (a[idx-1].a>most)
        {
            most=a[idx-1].a;
            h=idx-1;
        }
    }
    if(m==0)
        cout<<sum<<endl;
    else
        {
            long long now=0;
            
                if (sum<most)
                {
                    a[h].b=2;
                    now=most;
                }
                
            sort(a,a+n,comp);
                
                    now+=sum;
    for (int i=n-1;i>=0;i--)
    {
        if (a[i].b==1)
        {
            if (now==0)
                now=a[i].a;
            else
            now*=2;
        }
    }
            cout<<now<<endl;
        }
}