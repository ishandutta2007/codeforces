#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef __int64 ll;
const ll M = 400000 + 100;
const ll inf  = 1e9 + 7;
int a[4];
int main()
{
    int x,y,res=0;
    cin>>x>>y;
    for(int i=1;i<=3;i++)
    {
        a[i]=y;
    }
    while((a[2]+a[3]-1)<x)
    {
        a[1]=a[2]+a[3]-1;res++;
        sort(a+1,a+4);
    }
    res+=3;
    cout<<res<<endl;
}