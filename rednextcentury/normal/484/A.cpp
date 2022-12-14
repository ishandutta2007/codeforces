#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <list>
#include <string.h>
#include <assert.h>
#include <time.h>
long long pows[100];
long long pow2[1000];
using namespace std;

int main()
{
    int n;
    cin>>n;
    pows[0]=1;
    pow2[0]=1;
    for (int i=1;i<100;i++)
    {
        pows[i]=pows[i-1]*2;
        pow2[i]=pows[i];
    }
    for (int i=1;i<100;i++)
    {
        pows[i]+=pows[i-1];
    }
    for (int i=0;i<n;i++)
    {
        long long l,r;
        cin>>l>>r;
        int mx=0;
        while(pows[mx]<=r)
            mx++;
        mx--;
        if (pows[mx]>=l)
        {
            cout<<pows[mx]<<endl;
            continue;
        }
        mx++;
        long long k=pows[mx];
        for (int i=62;i>=0;i--)
        {
            if (k-pow2[i]>=l)
                k-=pow2[i];
            if (k<=r)
                break;
        }
        cout<<k<<endl;
    }
}