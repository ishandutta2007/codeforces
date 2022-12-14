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
int a[100000];
int main()
{
    int n,d;
    cin>>n>>d;
    int x=0;
    int h=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        x+=a[i];
        if (i<n-1)
        {
        x+=10;
        h+=2;
        }
    }
    if (x>d)
        cout<<-1<<endl;
    else
    {
        cout<<(d-x)/5+h<<endl;
    }
}