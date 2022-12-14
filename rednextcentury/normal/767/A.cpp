# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
bool fell[1000000];
bool is[1000000];
int main()
{
    int n;
    cin>>n;
    int l=n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        fell[x]=1;
        while(l>=1 && fell[l]==1)
        {
            cout<<l<<' ';
            l--;
        }
        cout<<endl;
    }
}