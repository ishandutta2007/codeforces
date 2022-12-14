#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <set>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;
char a[1000][1000];
int main()
{
    int n,m;
    cin>>n;
    m=n;
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            cin>>a[i][x];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            int now=0;
            if (i>0 && a[i-1][x]=='o')
                now++;
            if (x>0 && a[i][x-1]=='o')
                now++;
            if (x<m-1 && a[i][x+1]=='o')
                now++;
            if (i<n-1 && a[i+1][x]=='o')
                now++;
            if (now==1 || now==3)
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}