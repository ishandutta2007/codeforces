#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <set>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include <map>
using namespace std;
int main()
{
	long long k,b,n;
	long long z=1,t;
	cin>>k>>b>>n>>t;

	for (int i=0;i<n;i++)
    {
        if (z>t)
        {
            cout<<n-i+1<<endl;

            return 0;
        }
        z=z*k+b;
    }
    if (z<=t)
        cout<<0<<endl;
    else
        cout<<1<<endl;
}