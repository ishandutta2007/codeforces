#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <ios>
using namespace std;
char a[100][100];
char b[100][100];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        if (i%2==0)
        {
            for (int x=0;x<m;x++)
            {
                if (x%2==0)
                    a[i][x]='B';
                else
                    a[i][x]='W';
            }
        }
        else
        {
            for (int x=0;x<m;x++)
            {
                if (x%2!=0)
                    a[i][x]='B';
                else
                    a[i][x]='W';
            }
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            cin>>b[i][x];
        }
    }
    for (int i=0;i<n;i++)
    {
        for (int x=0;x<m;x++)
        {
            if (b[i][x]=='.')
                cout<<a[i][x];
            else
                cout<<"-";
        }
        cout<<endl;
    }
}