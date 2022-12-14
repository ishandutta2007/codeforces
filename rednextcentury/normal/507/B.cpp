#include <iostream>
# include <cstdlib>
# include <algorithm>
#include<cstdio>
# include <vector>
#include <cmath>
#include <map>
#include<set>
#include <stack>
using namespace std;
long long n;
long long h;
long long moves;
void solve(long long level,long long l,long long r)
{
    if (level==h)
        return;
    long long x=(l+r)/2;
    if (n<=x)
    {
        if (moves%2==0)
        {
            moves++;
            solve(level+1,l,x);
        }
        else
        {
            //if (h==level+1)
            //moves+=2;
            //else
            moves+=((long long)1<<(h-level));
            solve(level+1,l,x);
        }
    }
    else
    {
        if (moves%2==0)
        {
         //  if (h==level+1)
            //moves+=2;
            //else
            moves+=(((long long)1<<(h-level)));
            solve(level+1,x+1,r);
        }
        else
        {
            moves++;
            solve(level+1,x+1,r);
        }
    }
}
int main()
{
    long double  r,x,y,x1,y1;
    cin>>r>>x>>y>>x1>>y1;
    long double dist=(x1-x)*(x1-x)+(y1-y)*(y1-y);
    r=r*2;
    dist=sqrt(dist);
    long double k=dist/r;
    if (k==(long long)k)
        cout<<k<<endl;
    else
        cout<<(long long)k+1<<endl;
}