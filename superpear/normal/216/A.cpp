#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>

#define maxlongint 2147483647;

using namespace std;

int main()
{
    int a,b,c,sum=0;
    cin>>a>>b>>c;
    if (a>b) swap(a,b);
    if (a>c) swap(a,c);
    if (b>c) swap(b,c);
    for (int i=1;i<=b;i++)
    {
        sum+=a;
        a++;
    }
    a--;
    for (int i=1;i<=c-b;i++)
    {
        sum+=a;
    }
    for (int i=1;i<=b-1;i++)
    {
        a--;
        sum+=a;
    }
    cout<<sum<<endl;
    return 0;
}