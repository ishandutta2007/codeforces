#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

int a[5001];

int main()
{
    int n, sum12, sum13, sum23, sum, sum123;
    cin>>n;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>sum12;
    cout<<"? 1 3"<<endl;
    fflush(stdout);
    cin>>sum13;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    cin>>sum23;
    sum123 = (sum12 + sum23 + sum13) / 2;
    a[1] = sum123 - sum23;
    a[2] = sum123 - sum13;
    a[3] = sum123 - sum12;
    for(int i=4;i<=n;i++)
    {
        cout<<"? 1 "<<i<<endl;
        fflush(stdout);
        cin>>sum;
        a[i] = sum - a[1];
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}