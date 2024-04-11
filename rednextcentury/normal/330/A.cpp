#include<iostream>
#include<algorithm>
# include <map>
# include <string>
# include <iomanip>
# include <queue>
# define FOR(n) for (long long i=0;i<n;i++)
struct f
{
    char a;
    bool b;
};
f d[100][100];
using namespace std;
int main()
{
    int r,c;
    cin>>c>>r;
    for (int i=0;i<c;i++)
    {
        for (int x=0;x<r;x++)
        {
            cin>>d[i][x].a;
        }
    }
    int ans=0;
    for (int i=0;i<c;i++)
    {
        bool t=0;
        for (int x=0;x<r;x++)
        {
            if (d[i][x].a=='S')
                t=1;
        
        }
        if (t==0)
        {
            for (int x=0;x<r;x++)
            {
                if (d[i][x].b==0)
                {
                    ans++;
                    d[i][x].b=1;
                    
                }
            
            }
        
        }
    
    }
    for (int i=0;i<r;i++)
    {
        bool t=0;
        for (int x=0;x<c;x++)
        {
            if (d[x][i].a=='S')
                t=1;
        
        }
        if (t==0)
        {
            for (int x=0;x<c;x++)
            {
                if (d[x][i].b==0)
                {
                    ans++;
                    
                    d[x][i].b=1;
                }
            
            }
        
        }
    
    }
    cout<<ans<<endl;
    
return 0;
}