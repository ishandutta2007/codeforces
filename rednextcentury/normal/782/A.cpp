# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <algorithm>
using namespace std;
bool on[1000000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int t=0;
    int mt=0;
    for (int i=0;i<2*n;i++)
    {
        int x;
        cin>>x;
        if (on[x])on[x]=0,t--;
        else on[x]=1,t++;
        mt=max(mt,t);
    }
    cout<<mt<<endl;
}