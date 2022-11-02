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

int a,b,c;

int lou(int num)
{
    int c=0,o=0,f[100];
    while (num>0) {o++;f[o]=num%10;num/=10;}
    for (int i=o;i>=1;i--)
        if (f[i]!=0) c=c*10+f[i];
    return c;
}

int main()
{
    cin>>a>>b;
    c=a+b;
    a=lou(a);b=lou(b);c=lou(c);
    if (a+b==c) cout<<"YES"<<endl; else cout<<"NO"<<endl;
    return 0;
}