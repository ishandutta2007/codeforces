# include <iostream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <algorithm>
# include <cmath>
# include <iomanip>
# include <queue>
# include <map>
# include <vector>
# include <stack>
using namespace std;
int in[40000];
int main()
{
    int x,k;
    cin>>x>>k;
    for (int i=0;i<k;i++)
    {
        int y,div1,div2;
        cin>>y;
        if (y==1)
        {
            cin>>div1>>div2;
            in[div1]=1;
            in[div2]=1;
        }
        else
        {
            cin>>div2;
            in[div2]=1;
        }
    }
    int now=0;
    int r=in[1];
    int min=0,max=0;
    for (int i=1;i<x;i++)
    {
        if (r==in[i])
            now++;
        if (r!=in[i])
        {
            if (r==0)
            {
            max+=now;
            min+=now/2;
            if (now%2!=0)
                min++;
            }
            r=1-r;
            now=1;
        }
        if (i==x-1)
        {
            if (r==0)
            {
                min+=now/2;
                max+=now;
                if (now%2!=0)
                    min++;
            }
        }
    }
    cout<<min<<" "<<max<<endl;
}