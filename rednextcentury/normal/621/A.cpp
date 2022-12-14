#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main()
{
    long long sum=0;
    int m,n=0;
    cin>>m;
    long long mn=(1LL<<50);
    int num=0;
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if (x%2==0)sum+=x;
        else mn=min(mn,x+0LL),num++,sum+=x;
    }
    if (num%2)sum-=mn;
    cout<<sum<<endl;
}