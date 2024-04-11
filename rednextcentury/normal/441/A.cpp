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
int ans[1000];
int main()
{   
    int n,m;
    cin>>n>>m;
    int tot=0;
    for (int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        int best=100000000;
        for (int i=0;i<k;i++)
        {
            int j;
            cin>>j;
            if (j<best)
                best=j;
        }
        if (m>best)
        {
            ans[tot++]=i+1;
        }
    }
    cout<<tot<<endl;
    for (int i=0;i<tot;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}