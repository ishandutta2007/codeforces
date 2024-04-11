#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>

#define maxlongint 2147483647;

using namespace std;

long long d,p,c,k,maxc,maxk,s;
int main()
{
    cin>>d>>p;
    c=1;
    k=0;
    maxc=0;maxk=d;
    while (true)
    {
        k++;c*=10;
        if (c>d) break;
        s=d%c;
        if (s==c-1)
        {
            maxc=k;
            maxk=d;
        }
        else
            if (s+1<=p)
            {
                maxc=k;
                maxk=d-s-1;
            }
    }
    cout<<maxk<<endl;
    return 0;
}