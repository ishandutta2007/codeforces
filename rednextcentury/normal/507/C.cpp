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
    cin>>h>>n;
    solve(0,1,(long long)1<<h);
    cout<<moves<<endl;
}