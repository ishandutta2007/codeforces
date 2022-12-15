# include <iostream>
# include <string>
# include <map>
# include <stdio.h>
# include <cmath>
# include <cstdio>
# include <queue>
# include <algorithm>
# include <stack>
# include <cstring>
# include <iomanip>
# include<ios>
using namespace std;
long long a[100000];
int main()
{
    long long n,x;
    cin>>n>>x;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    long long time=0;
    for (int i=0;i<n;i++)
    {
        time+=max(x,(long long)1)*a[i];
        x--;
    }
    cout<<time<<endl;
}